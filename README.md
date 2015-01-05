1dcoinctrl
==========

Western Electric 1D/2D Payphone Controller Interface for Asterisk

### WARNING - This project involves potentially lethal High-Voltage!
Coin collect/refund operates from +/- 130VDC.  This means that there is a potental difference of 260VDC across the bridge rectifier in this circuit!  Construction and operation of this circuit should only be performed by people familiar with best practices when operating with high voltages and using extreme caution.

I WILL NOT BE HELD LIABLE FOR INJURY OR DEATH RESULTING FROM BUILDING OR USING THIS CIRCUIT.   BUILD AND USE THIS CIRCUIT AT YOUR OWN RISK.  BE SURE TO USE A LINE FUSE ON THE 120VAC MAINS.

THIS HARDWARE AND SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL HOWARD M. HARTE BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE HARDWARE AND SOFTWARE OR THE USE OR OTHER DEALINGS IN THE HARDWARE AND SOFTWARE. 

####Overview

This project aims to emulate a coin line as required by the older "dumb" (ie, non-COCOT) payphones such as the Western Electric 1D "Fortress" series.  This coin line interface connects in between an Asterisk PBX the payphone.  It provide the coin control functionality as well as the ability to determine whether an initial rate has been deposited, and can also perform the "stuck coin" test.  In addition, it can count dial pulses to provide out-of-band dial signalling to Asterisk for the rotary-style 1D payphones.

This project is based on two other open-source projects (see References below) and has the following goals:

1. Real coin-line signaling, while preserving the actual payphone earth ground.  This requires both +130VDC (coin collect) and -130VDC (coin refund) as well as +25VDC for the "stuck coin" test and -25VDC for the "initial rate" test.

2. The ability to provide up to four coin lines in a single unit.

3. The ability to count dial pulses from Rotary payphones and provide the digits out-of-band to Asterisk.

4. The ability to be red-boxed.

####Pay Phone

[Imgur](http://i.imgur.com/b4mjclw.jpg)

The payphone is a standard Western Electric 1D phone with a 32B "dumb" chassis.

####Coin Line Signaling
All coin line signaling happens with respect to TIP and Ground with the RING open. For the tests, current flowing when voltage is applied indicates that either a coin is present in the hopper, or the initial rate has been deposited.

+130VDC: Collect coin.
-130VDC: Refund coin.
+25VDC: Stuck Coin Test.
-25VDC: Initial Rate Test.

####Controlling the Coin Line Signaling

[Imgur](http://i.imgur.com/M2MgEFB.jpg)

The coin line signaling is controlled via a Teensy 3.1 microcontroller.  This microcontroller can sense the line ON/OFF hook status, the test status, and can control the relays on the controller.

There are two relays that provide common control, and two additional relays per line.

Common Control Relays:
1. REFUND Relay: When operated will prepare negative voltage to be applied to the TIP when the selected line's COIN_CONTROL relay is operated.  When this relay is operated, either Coin Refund or Initial Rate Test will be performed based on the state of the DISPOSITION relay.

2. DISPOSITION Relay: When operated will prepare high voltage (either +130VDC or -130VDC, repending on the state of the REFUND relay) to be applied to the TIP when the selected line's COIN_CONTROL relay is operated.  When the DISPOSITION relay is not operated, low voltage (+25VDC or -25VDC) will be applied in order to perform either the initial rate test or the stuck coin test.

Per-Line Relays (one each per coin line:)
1. HOLD Relay: When operated will shunt the TIP and RING towards the CO (Asterisk PBX in our case) with a 120-ohm resistor.  This will keep the line on hold while coin disposition or rate tests are performed.

2. COIN_CONTROL Relay: When operated, will apply the coin control voltage to the TIP towards the payphone.  When not operated, the TIP and RING from the CO (Asterisk PBX) will be passed through to the payphone.

There are several opto-isolated sensors in the design to provide status to the microcontroller.

1. TEST_STATUS sensor will go low when current is flowing during a test.  It will be high when current is not flowing.

2. Per-line OFF_HOOK sensors (one per line) will go low when current is flowing through the loop to the CO (Asterisk PBX.)  This current will be flowing either when the payphone is off-hook or when the line is on hold.

####Microcontroller Firmware
The microcontroller firmware is written in the C programming language, and currently only provides a basic interface in order to test the coin controller circuit.

The firmware follows Karl Lunt's [http://www.seanet.com/~karllunt/bareteensy31.html](Bare-metal Teensy 3.x Development) and also uses his [http://www.seanet.com/~karllunt/bareteensy31libs.html](UART and Terminal I/O libraries).

####Asterisk PBX Modifications
Modifications to Asterisk in order to recognize the 1700/2200Hz coin tones is based on [https://github.com/jcs/payphone](Joshua Stein's project) although I modified them to treat the 1700/2200Hz tones as a 5th row/column in the standard DTMF decoding routine in Asterisk's main/dsp.c.

The Asterisk AGI script is not complete, but at present it will prompt for money and can recognize the coin tones.  It will complete the call after 25 cents has been deposited.

####References
[https://github.com/jcs/payphone](https://github.com/jcs/payphone)
[http://gpl-projects.ohnosec.org/payphone/](http://gpl-projects.ohnosec.org/payphone/)
