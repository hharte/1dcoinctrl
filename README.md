# 1dcoinctrl - Issue 4


## Western Electric 1D/2D Payphone Controller Interface for Asterisk


# WARNING - This project involves potentially lethal High-Voltage!

**_The coin relay in most payphones operates using +/- 130VDC.  This project uses a DC-DC converter to boost 12VDC to 130VDC.  Construction and operation of this circuit should only be performed by people familiar with best practices when operating with high voltage, and using extreme caution._**

I WILL NOT BE HELD LIABLE FOR INJURY OR DEATH RESULTING FROM BUILDING OR USING THIS CIRCUIT.   BUILD AND USE THIS CIRCUIT AT YOUR OWN RISK.

THIS HARDWARE AND SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL HOWARD M. HARTE BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE HARDWARE AND SOFTWARE OR THE USE OR OTHER DEALINGS IN THE HARDWARE AND SOFTWARE. 


# Overview

This project aims to emulate a coin line as required by the older "dumb" (ie, non-COCOT) payphones such as the Western Electric 1D "Fortress" series.  This coin line interface connects in between an Asterisk PBX and the payphone.  It provides the coin control functionality as well as the ability to determine whether an initial rate has been deposited, and can also perform the "stuck coin" test.

This project is based on another open-source project (see References below) and has the following goals:



1. Real coin-line signaling, while preserving the payphone earth ground.  This requires both +130VDC (coin collect) and -130VDC (coin refund) as well as +25VDC for the "stuck coin" test and -25VDC for the "initial rate" test.
2. The ability to provide up to four coin lines in a single unit.
3. The ability to count dial pulses from Rotary payphones and provide the digits out-of-band to Asterisk.
4. The ability to be [red-boxed](http://en.wikipedia.org/wiki/Red_box_(phreaking)).

![alt_text](https://raw.githubusercontent.com/hharte/1dcoinctrl/main/photos/1dcoinctrl_iss2.jpg "image_tooltip")


# Pay phone

The payphone is a standard Western Electric 1D phone with a 32B "dumb" chassis.  I also verified that Western Electric 32A and TeleService 4032C chassis work well with this design.


# Coin Line Signaling

All coin line signaling happens with respect to TIP and Ground with the RING open. For the tests, current flowing when voltage is applied indicates that either a coin is present in the hopper, or the initial rate has been deposited.


<table>
  <tr>
   <td>Voltage
   </td>
   <td>Operation
   </td>
  </tr>
  <tr>
   <td>+130VDC
   </td>
   <td>Collect coins.
   </td>
  </tr>
  <tr>
   <td>-130VDC
   </td>
   <td>Refund coins.
   </td>
  </tr>
  <tr>
   <td>+25VDC
   </td>
   <td>Stuck Coin Test
   </td>
  </tr>
  <tr>
   <td>-25VDC
   </td>
   <td>Initial Rate Test
   </td>
  </tr>
</table>



## Controlling the Coin Line Signaling

Control of the coin lines is handled by a PIC18F47Q84 microcontroller.  This microcontroller can sense the line polarity and ON/OFF hook status, the test status, and can control the relays on the controller.

There are three relays that provide common control, and two additional relays per line.


### Common Control Relays

1. **_REFUND_** Relay: When operated will prepare negative voltage to be applied to the TIP when the selected line's COIN_CONTROL relay is operated.  When this relay is operated, either Coin Refund or Initial Rate Test will be performed based on the state of the DISPOSITION relay.

2. **_DISPOSITION_** Relay: When operated will prepare high voltage (either +130VDC or -130VDC, depending on the state of the REFUND relay) to be applied to the TIP when the selected line's COIN_CONTROL relay is operated.  When the DISPOSITION relay is not operated, low voltage (+25VDC or -25VDC) will be applied in order to perform either the initial rate test or the stuck coin test.

3. **_POLE-CHANGER_** Relay: This relay is used to swap the Vout+ and Vout- on the output of the 130VDC DC-DC converter so that both +130VDC and -130VDC are available depending on whether the coin should be collected or refunded.


### Per-Line Relays, one each per coin line:

1. **_HOLD_** Relay: When operated will shunt the TIP and RING towards the CO (Asterisk PBX in our case) with a 120-ohm resistor.  This will keep the line on hold while coin disposition or rate tests are performed.

2. **_COIN_CONTROL_** Relay: When operated, will apply the coin control voltage to the TIP towards the payphone.  When not operated, the TIP and RING from the CO (Asterisk PBX) will be passed through to the payphone.


### Sensors

There are several opto-isolated sensors in the design to provide status to the microcontroller.

1. **_TEST_STATUS_** sensor will go low when current is flowing during a test.  It will be high when current is not flowing.

2. Per-line **_OFF_HOOK_F and OFF_HOOK_R_** sensors (one per line) will go low when current is flowing through the loop to the CO (Asterisk PBX) and can detect forward and reverse polarity.  This current will be flowing either when the payphone is off-hook or when the line is on hold.  Polarity reversal answer supervision, if provided by your telephone line, can be used to determine whether coins should be collected or refunded.  These LEDs will blink rapidly while a rotary payphone is being dialed.


# Microcontroller Firmware

The microcontroller firmware uses the [Arduino](https://www.arduino.cc/) development environment with the [DxCore library](https://github.com/SpenceKonde/DxCore) for ease of development.  The firmware provides a command-line interface via the serial port that uses a command set modeled after the familiar Hayes AT command set.

The command syntax is AT followed by a single character command, and an optional number [1-4] for the coin line to operate on.  If the coin line is omitted, the previously used coin line is assumed.

Commands are as follows:


<table>
  <tr>
   <td><strong><em>Command</em></strong>
   </td>
   <td><strong><em>Description</em></strong>
   </td>
   <td><strong><em>Response</em></strong>
   </td>
  </tr>
  <tr>
   <td>AT
   </td>
   <td>Attention
   </td>
   <td>OK
   </td>
  </tr>
  <tr>
   <td>ATZ
   </td>
   <td>Reset
   </td>
   <td>OK
   </td>
  </tr>
  <tr>
   <td>ATC
   </td>
   <td>Collect coin
   </td>
   <td>OK
   </td>
  </tr>
  <tr>
   <td>ATR
   </td>
   <td>Refund coin
   </td>
   <td>OK
   </td>
  </tr>
  <tr>
   <td>ATI
   </td>
   <td>Initial rate test
   </td>
   <td>0 = Initial rate not deposited
<p>
1 = Initial rate deposited
   </td>
  </tr>
  <tr>
   <td>ATS
   </td>
   <td>Stuck coin test
   </td>
   <td>0 = No coin in escrow.
<p>
1 = Coin in escrow.
   </td>
  </tr>
  <tr>
   <td>ATQ
   </td>
   <td>Query hook state
   </td>
   <td>0 = On hook
<p>
1 = Off hook (normal polarity)
<p>
2 = Off hook (reversed polarity)
   </td>
  </tr>
  <tr>
   <td>ATL
   </td>
   <td>Query selected coin line
   </td>
   <td>1-4
   </td>
  </tr>
  <tr>
   <td>ATH
   </td>
   <td>Hold CO line
   </td>
   <td>OK
   </td>
  </tr>
  <tr>
   <td>ATU
   </td>
   <td>Un-hold CO line
   </td>
   <td>OK
   </td>
  </tr>
  <tr>
   <td>ATD
   </td>
   <td>Dump current controller state
   </td>
   <td>OK
   </td>
  </tr>
  <tr>
   <td>ATE
   </td>
   <td>Stress test 100 refunds (1s apart)
   </td>
   <td>OK
   </td>
  </tr>
  <tr>
   <td>ATT
   </td>
   <td>Coin line simulation
   </td>
   <td>Need hard reset to exit.
   </td>
  </tr>
  <tr>
   <td>ATV
   </td>
   <td>Display firmware version
   </td>
   <td>OK
   </td>
  </tr>
  <tr>
   <td>AT?
   </td>
   <td>Help
   </td>
   <td>Display command help
   </td>
  </tr>
</table>


 


# Building the Hardware


## Components

The components for this board can be ordered from Digi-Key using [this parts list](https://www.digikey.com/en/mylists/list/BGQKKBOZGS).  The list includes all components and accessories to build the full board supporting all four coin lines.  The user will need to provide their own 12VDC power supply.

There is an [interactive Bill of Materials here](https://html-preview.github.io/?url=https://github.com/hharte/1dcoinctrl/blob/main/hardware/bom/ibom.html).


## Stuffing Options


### Relay Coil Voltage and DC-DC Converters

The schematic/BOM supports either 5V or 12V coil relays.  Alternatively, the board may be built to support a 24VDC input voltage and the user may use 24V coil relays.  In this case, PS1 and PS2 need to change:


<table>
  <tr>
   <td>Power Supply Voltage
   </td>
   <td>Relay Coil Voltage
   </td>
   <td>J8 Setting
   </td>
   <td>PS1 Part
   </td>
   <td>PS2 Part
   </td>
  </tr>
  <tr>
   <td>+12VDC*
   </td>
   <td>12V*
   </td>
   <td>1-2
   </td>
   <td>R12-100B
   </td>
   <td>IA1224S
   </td>
  </tr>
  <tr>
   <td>+12VDC
   </td>
   <td>5V
   </td>
   <td>2-3
   </td>
   <td>R12-100B
   </td>
   <td>IA1224S
   </td>
  </tr>
  <tr>
   <td>+24VDC
   </td>
   <td>5V
   </td>
   <td>2-3
   </td>
   <td>R24-100B
   </td>
   <td>IA2424S
   </td>
  </tr>
  <tr>
   <td>+24VDC
   </td>
   <td>24V
   </td>
   <td>1-2
   </td>
   <td>R24-100B
   </td>
   <td>IA2424S
   </td>
  </tr>
</table>



### Serial Port - RS-232 or 5V TTL-level UART

Communication with the host computer is either via RS-232 or 5V TTL-level UART.


<table>
  <tr>
   <td><strong><em>Reference Designator</em></strong>
   </td>
   <td><strong><em>RS-232</em></strong>
   </td>
   <td><strong><em>TTL UART </em></strong>
   </td>
   <td><strong><em>Notes</em></strong>
   </td>
  </tr>
  <tr>
   <td>U2
   </td>
   <td>✔
   </td>
   <td>
   </td>
   <td>MAX202 or equivalent.
   </td>
  </tr>
  <tr>
   <td>C3,C4,C5,C6,C8
   </td>
   <td>✔
   </td>
   <td>
   </td>
   <td>0.1uF Capacitor
   </td>
  </tr>
  <tr>
   <td>R2
   </td>
   <td>✔
   </td>
   <td>
   </td>
   <td>
   </td>
  </tr>
  <tr>
   <td>C7
   </td>
   <td>✔
   </td>
   <td>
   </td>
   <td>4700pF Capacitor
   </td>
  </tr>
  <tr>
   <td>JP1
   </td>
   <td>✔
   </td>
   <td>
   </td>
   <td>Programming Enable (to program Microcontroller)
<p>
Remove jumper from JP1 when using a standard FTDI 5V TTL UART cable.
   </td>
  </tr>
  <tr>
   <td>JP2, JP3
   </td>
   <td>1-2
   </td>
   <td>2-3
   </td>
   <td>Jumper 1-2 for RS-232 or 2-3 for TTL UART.
   </td>
  </tr>
  <tr>
   <td>J5
   </td>
   <td>✔
   </td>
   <td>✔
   </td>
   <td>6-pin right angle 0.1” male header.
   </td>
  </tr>
</table>


Note: To switch between RS-232 and TTL UART, U2 can be removed from the socket, and the 5V TTL UART cable attached to J5.  When switching back to the RS-232 port, detach the 5V TTL UART cable from J5 and reinstall U2.  In addition to the TTL UART, J5 is also used to program the microcontroller.


### External +/-130VDC Coin Collect / Refund Supply

The board can accommodate an external +/-130VDC supply with the following assembly changes:


<table>
  <tr>
   <td><strong><em>Reference Designator</em></strong>
   </td>
   <td><strong><em>Populate</em></strong>
   </td>
   <td><strong><em>Do Not Populate</em></strong>
   </td>
   <td><strong><em>Notes</em></strong>
   </td>
  </tr>
  <tr>
   <td>PS1
   </td>
   <td>
   </td>
   <td>✔
   </td>
   <td>
   </td>
  </tr>
  <tr>
   <td>C18
   </td>
   <td>
   </td>
   <td>✔
   </td>
   <td>
   </td>
  </tr>
  <tr>
   <td>D2
   </td>
   <td>
   </td>
   <td>✔
   </td>
   <td>
   </td>
  </tr>
  <tr>
   <td>D1
   </td>
   <td>
   </td>
   <td>✔
   </td>
   <td>V_COIN_RELAY (130VDC) Indicator LED.
   </td>
  </tr>
  <tr>
   <td>K1
   </td>
   <td>
   </td>
   <td>✔
   </td>
   <td>Pole Changer Relay
   </td>
  </tr>
  <tr>
   <td>R15
   </td>
   <td>
   </td>
   <td>✔
   </td>
   <td>
   </td>
  </tr>
  <tr>
   <td>R5
   </td>
   <td>
   </td>
   <td>✔
   </td>
   <td>5K Potentiometer
   </td>
  </tr>
  <tr>
   <td>R9
   </td>
   <td>
   </td>
   <td>✔
   </td>
   <td>V_COIN_RELAY (130VDC) Indicator LED current limit.
   </td>
  </tr>
  <tr>
   <td>F2, F3
   </td>
   <td>✔
   </td>
   <td>
   </td>
   <td>125mA Fuse
   </td>
  </tr>
  <tr>
   <td>R10, R11
   </td>
   <td>✔
   </td>
   <td>
   </td>
   <td>+/- 130VDC LED current limiting.
   </td>
  </tr>
  <tr>
   <td>D3, D13
   </td>
   <td>✔
   </td>
   <td>
   </td>
   <td>+/- 130VDC Indicator LEDs
   </td>
  </tr>
</table>


**_Note:_** To switch between external +/-130 VDC supply and the on-board DC-DC converter:



* At minimum, PS1 and K1 should be removed when using the external supply.  If desired, a socket can be made for PS1 by removing several pins from a 24-pin 0.6” wide, machined-pin DIP socket.  A socket can be made for K1 in a similar fashion, using a 16-pin machined-pin DIP socket.
* At minimum, F2, F3 should be removed when using the on-board DC-DC converter.  This is essential for two reasons:
1. Safety: Prevent V_COIN_RELAY (130VDC) from being present on the +/-130VDC terminals of J1.
2. Protection: to ensure that V_COIN_RELAY is not shorted to the +/-130VDC supply during operation.

**_Warning_**

D1, when illuminated, indicates that 130VDC is present on the board.  While this LED is lit, be very careful not to touch the high-voltage section of the board.

D3, D13, when illuminated, indicates that external +/-130VDC is present on the board.  While either of these LEDs are lit, be very careful not to touch the high-voltage section of the board.


### Less Than Four Coin Lines

The controller can be assembled to support fewer than four pay phones.  If only one pay phone is desired, U3 (7406) can be omitted, as well as components associated with lines 2 through 4.


<table>
  <tr>
   <td><strong><em>Coin Line</em></strong>
   </td>
   <td><strong><em>Reference Designator</em></strong>
   </td>
   <td><strong><em>Do Not Populate</em></strong>
   </td>
   <td><strong><em>Notes</em></strong>
   </td>
  </tr>
  <tr>
   <td rowspan="5" >2
   </td>
   <td>D19
   </td>
   <td>✔
   </td>
   <td>Bi-Color LED
   </td>
  </tr>
  <tr>
   <td>D5, D7
   </td>
   <td>✔
   </td>
   <td>1N4148 Switching Diodes
   </td>
  </tr>
  <tr>
   <td>R4, R16, R24
   </td>
   <td>✔
   </td>
   <td>
   </td>
  </tr>
  <tr>
   <td>K3, K6
   </td>
   <td>✔
   </td>
   <td>Hold / Coin Control Relays
   </td>
  </tr>
  <tr>
   <td>U5
   </td>
   <td>✔
   </td>
   <td>Optoisolator
   </td>
  </tr>
  <tr>
   <td rowspan="5" >3
   </td>
   <td>D20
   </td>
   <td>✔
   </td>
   <td>Bi-Color LED
   </td>
  </tr>
  <tr>
   <td>D8, D10
   </td>
   <td>✔
   </td>
   <td>1N4148 Switching Diodes
   </td>
  </tr>
  <tr>
   <td>R3, R18, R26
   </td>
   <td>✔
   </td>
   <td>
   </td>
  </tr>
  <tr>
   <td>K5, K7
   </td>
   <td>✔
   </td>
   <td>Hold / Coin Control Relays
   </td>
  </tr>
  <tr>
   <td>U4
   </td>
   <td>✔
   </td>
   <td>Optoisolator
   </td>
  </tr>
  <tr>
   <td rowspan="5" >4
   </td>
   <td>D21
   </td>
   <td>✔
   </td>
   <td>Bi-Color LED
   </td>
  </tr>
  <tr>
   <td>D9, D11
   </td>
   <td>✔
   </td>
   <td>1N4148 Switching Diodes
   </td>
  </tr>
  <tr>
   <td>R1, R19, R25
   </td>
   <td>✔
   </td>
   <td>
   </td>
  </tr>
  <tr>
   <td>K8, K9
   </td>
   <td>✔
   </td>
   <td>Hold / Coin Control Relays
   </td>
  </tr>
  <tr>
   <td>U1
   </td>
   <td>✔
   </td>
   <td>Optoisolator
   </td>
  </tr>
</table>



## Enclosure

Included in the parts list is a [Hammond 160mm extruded aluminum enclosure](https://www.hammfg.com/files/parts/pdf/1455R1602BK.pdf).  This enclosure includes end caps that can be cut/drilled for the LEDs in the front of the board, as well as the connectors in the rear.  Alternatively, a design for 3D-printed end caps is included in this project.


## Issue 4 PCB


### Microcontroller Replacement

The PIC microcontroller in previous revisions was replaced with an [AVR128DA28](https://www.microchip.com/en-us/product/avr128da28) in the DIP-28 package.  The firmware uses the [Arduino](https://www.arduino.cc/) development environment with the [DxCore library](https://github.com/SpenceKonde/DxCore) for ease of development and programming.


### Other changes between Issue 3 and Issue 4:



* Additional LED connected to microcontroller pin PA7 under firmware control.

Still need to validate:



1. Coin Lines 2, 3, 4.
2. FTDI 5V TTL UART Connection.
3. 


# Connections


## J3, J4 - Lines

The controller supports four CO lines and four coin collectors via two RJ45 connectors.  Each of these connectors is wired according to [T568A](https://en.wikipedia.org/wiki/ANSI/TIA-568).


<table>
  <tr>
   <td><strong><em>Pin</em></strong>
   </td>
   <td><strong><em>T568A Pair</em></strong>
   </td>
   <td><strong><em>J4</em></strong>
<p>
<strong><em>CO Lines</em></strong>
   </td>
   <td><strong><em>J3</em></strong>
<p>
<strong><em>Coin Phones</em></strong>
   </td>
   <td><strong><em>Color</em></strong>
   </td>
  </tr>
  <tr>
   <td>1
   </td>
   <td>3
   </td>
   <td>L3 Tip
   </td>
   <td>L3 Tip
   </td>
   <td>White/Green
   </td>
  </tr>
  <tr>
   <td>2
   </td>
   <td>3
   </td>
   <td>L3 Ring
   </td>
   <td>L3 Ring
   </td>
   <td>Green/White
   </td>
  </tr>
  <tr>
   <td>3
   </td>
   <td>2
   </td>
   <td>L2 Tip
   </td>
   <td>L2 Tip
   </td>
   <td>White/Orange
   </td>
  </tr>
  <tr>
   <td>4
   </td>
   <td>1
   </td>
   <td>L1 Ring
   </td>
   <td>L1 Ring
   </td>
   <td>Blue/White
   </td>
  </tr>
  <tr>
   <td>5
   </td>
   <td>1
   </td>
   <td>L1 Tip
   </td>
   <td>L1 Tip
   </td>
   <td>White/Blue
   </td>
  </tr>
  <tr>
   <td>6
   </td>
   <td>2
   </td>
   <td>L2 Ring
   </td>
   <td>L2 Ring
   </td>
   <td>Orange/White
   </td>
  </tr>
  <tr>
   <td>7
   </td>
   <td>4
   </td>
   <td>L4 Tip
   </td>
   <td>L4 Tip
   </td>
   <td>White/Brown
   </td>
  </tr>
  <tr>
   <td>8
   </td>
   <td>4
   </td>
   <td>L4 Ring
   </td>
   <td>L4 Ring
   </td>
   <td>Brown/White
   </td>
  </tr>
</table>



## J1 - Power


<table>
  <tr>
   <td>Pin
   </td>
   <td>Description
   </td>
  </tr>
  <tr>
   <td>+12VDC
   </td>
   <td>Positive 12V Input.  This must be positive with respect to GROUND.
   </td>
  </tr>
  <tr>
   <td>GROUND
   </td>
   <td>Power Supply Ground (Must be the same as earth ground.)
   </td>
  </tr>
  <tr>
   <td>+130VDC_IN
   </td>
   <td>Coin voltage + (Optional, board assembly option.)
   </td>
  </tr>
  <tr>
   <td>-130VDC_IN
   </td>
   <td>Coin voltage - (Optional, board assembly option.)
   </td>
  </tr>
</table>



## Earth Ground Lug

Coin control and tests are with respect to earth ground.  All payphones must be grounded and bonded for safety as well as to provide a return path for coin collect/refund as well as the initial rate and stuck coin tests.  If the payphone and coin line controller are not grounded, they will not work properly.


## Serial Port

Communication with the host computer running Asterisk is via an RS-232 serial port at J6.  If the user does not wish to use RS-232 levels to communicate with the computer, then the MAX202 IC at U2 should be removed from the socket.  With the MAX202 removed, a [USB to 5V TTL Serial cable](https://www.digikey.com/en/products/detail/ftdi-future-technology-devices-international-ltd/TTL-232R-5V/2003493) connected to J5 (Ground pin on the left when looking at the rear of the controller) can be used to connect the coin controller to a PC via USB.


# Indicators

The controller includes several indicator LEDs.  Most are on the front panel; however, high-voltage warning LEDs are present inside the enclosure.


<table>
  <tr>
   <td><strong><em>Reference Designator</em></strong>
   </td>
   <td><strong><em>Indicates</em></strong>
   </td>
   <td><strong><em>Notes</em></strong>
   </td>
  </tr>
  <tr>
   <td>D15
   </td>
   <td>Power
   </td>
   <td>Illuminates when +5VDC is present, indicating that the coin controller board is powered.
   </td>
  </tr>
  <tr>
   <td>D16
   </td>
   <td>MCU Status
   </td>
   <td>Illuminated under firmware (PA7) control by the on-board microcontroller.
   </td>
  </tr>
  <tr>
   <td>D17
   </td>
   <td>Test Status
   </td>
   <td>Illuminates during the stuck coin test or the initial rate test if the test result is positive: coin is stuck, initial rate is deposited.  This status is input to the microcontroller on PA6.
   </td>
  </tr>
  <tr>
   <td>D18
   </td>
   <td>L1 Status
   </td>
   <td>Line 1 Hook State:
<ul>

<li>Not illuminated: On-hook

<li>Green: Normal Polarity

<li>Red: Reverse Polarity (Answer supervision.)
</li>
</ul>
   </td>
  </tr>
  <tr>
   <td>D19
   </td>
   <td>L2 Status
   </td>
   <td>Line 2 Hook State
   </td>
  </tr>
  <tr>
   <td>D20
   </td>
   <td>L3 Status
   </td>
   <td>Line 1 Hook State
   </td>
  </tr>
  <tr>
   <td>D21
   </td>
   <td>L4 Status
   </td>
   <td>Line 1 Hook State
   </td>
  </tr>
  <tr>
   <td>D1
   </td>
   <td>V_COIN_RELAY
   </td>
   <td>(Internal) 130VDC produced by the on-board DC-DC converter.
   </td>
  </tr>
  <tr>
   <td>D3
   </td>
   <td>+130VDC
   </td>
   <td>(Internal) Indicates +130VDC from the external supply is present.
   </td>
  </tr>
  <tr>
   <td>D13
   </td>
   <td>-130VDC
   </td>
   <td>(Internal) Indicates -130VDC from the external supply is present.
   </td>
  </tr>
</table>



# Asterisk PBX Modifications

Modifications to Asterisk in order to recognize the 1700/2200Hz coin tones is based on [Joshua Stein's project](https://github.com/jcs/payphone) although I modified them to treat the 1700/2200Hz tones as a 5th row/column in the standard [DTMF](http://en.wikipedia.org/wiki/Dual-tone_multi-frequency_signaling) decoding routine in Asterisk's main/dsp.c.

The Asterisk AGI script is not complete, but at present it will prompt for money and can recognize the coin tones.  It will complete the call after 25 cents has been deposited.


## References



* [https://github.com/jcs/payphone](https://github.com/jcs/payphone)
* [Bell System Public Services Crafts' Manual for Station, Network, and Testboard](http://wedophones.com/TheBellSystem/pdf/bsp/coin/PublicServices1.pdf)
