EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 6 6
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L 1d_coinctrl_r2-rescue:G5V-2-DC12-dk_Signal-Relays-Up-to-2-Amps RLY?
U 1 1 5BAA6BB5
P 2850 2300
AR Path="/5BAA6BB5" Ref="RLY?"  Part="1" 
AR Path="/5BA4B80D/5BAA6BB5" Ref="RLY?"  Part="1" 
AR Path="/5BAA648F/5BAA6BB5" Ref="K3"  Part="1" 
F 0 "K3" H 3338 2346 50  0000 L CNN
F 1 "L1_HOLD" H 3338 2255 50  0000 L CNN
F 2 "digikey-footprints:Relay_THT_G5V-2" H 3050 2500 50  0001 L CNN
F 3 "http://omronfs.omron.com/en_US/ecb/products/pdf/en-g5v_2.pdf" H 3050 2600 60  0001 L CNN
F 4 "Z768-ND" H 3050 2700 60  0001 L CNN "Digi-Key_PN"
F 5 "G5V-2-DC12" H 3050 2800 60  0001 L CNN "MPN"
F 6 "Relays" H 3050 2900 60  0001 L CNN "Category"
F 7 "Signal Relays, Up to 2 Amps" H 3050 3000 60  0001 L CNN "Family"
F 8 "http://omronfs.omron.com/en_US/ecb/products/pdf/en-g5v_2.pdf" H 3050 3100 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/omron-electronics-inc-emc-div/G5V-2-DC12/Z768-ND/87821" H 3050 3200 60  0001 L CNN "DK_Detail_Page"
F 10 "RELAY GEN PURPOSE DPDT 2A 12V" H 3050 3300 60  0001 L CNN "Description"
F 11 "Omron Electronics Inc-EMC Div" H 3050 3400 60  0001 L CNN "Manufacturer"
F 12 "Active" H 3050 3500 60  0001 L CNN "Status"
	1    2850 2300
	0    1    -1   0   
$EndComp
Text HLabel 1400 2000 0    50   UnSpc ~ 0
L1_CO_TIP
Text HLabel 1400 2400 0    50   UnSpc ~ 0
L1_CO_RING
Wire Wire Line
	2550 2400 1400 2400
$Comp
L 1d_coinctrl_r2-rescue:+12V_RELAY-power #PWR?
U 1 1 5BAA6BD4
P 3500 2850
AR Path="/5BA4B80D/5BAA6BD4" Ref="#PWR?"  Part="1" 
AR Path="/5BAA648F/5BAA6BD4" Ref="#PWR036"  Part="1" 
F 0 "#PWR036" H 3500 2700 50  0001 C CNN
F 1 "+12V_RELAY" H 3515 3023 50  0000 C CNN
F 2 "" H 3500 2850 50  0001 C CNN
F 3 "" H 3500 2850 50  0001 C CNN
	1    3500 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	3150 2700 3300 2700
$Comp
L Diode:1N4148 D?
U 1 1 5BAA6BDC
P 2900 3250
AR Path="/5BAA6BDC" Ref="D?"  Part="1" 
AR Path="/5BA4B80D/5BAA6BDC" Ref="D?"  Part="1" 
AR Path="/5BAA648F/5BAA6BDC" Ref="D8"  Part="1" 
F 0 "D8" V 2854 3329 50  0000 L CNN
F 1 "1N4148" V 2945 3329 50  0000 L CNN
F 2 "Diode_THT:D_DO-35_SOD27_P7.62mm_Horizontal" H 2900 3075 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/1N4148_1N4448.pdf" H 2900 3250 50  0001 C CNN
	1    2900 3250
	-1   0    0    -1  
$EndComp
Wire Wire Line
	3050 3250 3300 3250
Wire Wire Line
	3300 3250 3300 2900
Wire Wire Line
	2750 3250 2400 3250
Wire Wire Line
	2400 3250 2400 2700
Wire Wire Line
	2400 2700 2550 2700
Wire Wire Line
	2400 2700 1400 2700
Connection ~ 2400 2700
Text HLabel 1400 2700 0    50   Input ~ 0
L1_HOLD_CO
Text HLabel 5000 2000 2    50   UnSpc ~ 0
L1_COIN_TIP
$Comp
L 1d_coinctrl_r2-rescue:G5V-2-DC12-dk_Signal-Relays-Up-to-2-Amps RLY?
U 1 1 5BAA6BF6
P 4400 2300
AR Path="/5BAA6BF6" Ref="RLY?"  Part="1" 
AR Path="/5BA4B80D/5BAA6BF6" Ref="RLY?"  Part="1" 
AR Path="/5BAA648F/5BAA6BF6" Ref="K4"  Part="1" 
F 0 "K4" H 4888 2346 50  0000 L CNN
F 1 "L1_COIN_CTRL" H 4888 2255 50  0000 L CNN
F 2 "digikey-footprints:Relay_THT_G5V-2" H 4600 2500 50  0001 L CNN
F 3 "http://omronfs.omron.com/en_US/ecb/products/pdf/en-g5v_2.pdf" H 4600 2600 60  0001 L CNN
F 4 "Z768-ND" H 4600 2700 60  0001 L CNN "Digi-Key_PN"
F 5 "G5V-2-DC12" H 4600 2800 60  0001 L CNN "MPN"
F 6 "Relays" H 4600 2900 60  0001 L CNN "Category"
F 7 "Signal Relays, Up to 2 Amps" H 4600 3000 60  0001 L CNN "Family"
F 8 "http://omronfs.omron.com/en_US/ecb/products/pdf/en-g5v_2.pdf" H 4600 3100 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/omron-electronics-inc-emc-div/G5V-2-DC12/Z768-ND/87821" H 4600 3200 60  0001 L CNN "DK_Detail_Page"
F 10 "RELAY GEN PURPOSE DPDT 2A 12V" H 4600 3300 60  0001 L CNN "Description"
F 11 "Omron Electronics Inc-EMC Div" H 4600 3400 60  0001 L CNN "Manufacturer"
F 12 "Active" H 4600 3500 60  0001 L CNN "Status"
	1    4400 2300
	0    -1   -1   0   
$EndComp
$Comp
L 1d_coinctrl_r2-rescue:+12V_RELAY-power #PWR038
U 1 1 5BAA6BFD
P 4000 2650
F 0 "#PWR038" H 4000 2500 50  0001 C CNN
F 1 "+12V_RELAY" H 4015 2823 50  0000 C CNN
F 2 "" H 4000 2650 50  0001 C CNN
F 3 "" H 4000 2650 50  0001 C CNN
	1    4000 2650
	1    0    0    -1  
$EndComp
$Comp
L Diode:1N4148 D?
U 1 1 5BAA6C05
P 4400 3250
AR Path="/5BAA6C05" Ref="D?"  Part="1" 
AR Path="/5BA4B80D/5BAA6C05" Ref="D?"  Part="1" 
AR Path="/5BAA648F/5BAA6C05" Ref="D10"  Part="1" 
F 0 "D10" V 4354 3329 50  0000 L CNN
F 1 "1N4148" V 4445 3329 50  0000 L CNN
F 2 "Diode_THT:D_DO-35_SOD27_P7.62mm_Horizontal" H 4400 3075 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/1N4148_1N4448.pdf" H 4400 3250 50  0001 C CNN
	1    4400 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	4100 1900 3150 1900
$Comp
L power:GND #PWR?
U 1 1 5BAA6C1D
P 1600 1700
AR Path="/5BA4B80D/5BAA6C1D" Ref="#PWR?"  Part="1" 
AR Path="/5BAA648F/5BAA6C1D" Ref="#PWR032"  Part="1" 
F 0 "#PWR032" H 1600 1450 50  0001 C CNN
F 1 "GND" H 1605 1527 50  0000 C CNN
F 2 "" H 1600 1700 50  0001 C CNN
F 3 "" H 1600 1700 50  0001 C CNN
	1    1600 1700
	1    0    0    -1  
$EndComp
Text HLabel 1350 1400 0    50   Output ~ 0
L1_OFF_HOOK_F
Wire Wire Line
	4700 2000 5000 2000
$Comp
L Device:R_US R8
U 1 1 5BAAA638
P 3400 2100
F 0 "R8" V 3300 2100 50  0000 C CNN
F 1 "120 2W" V 3500 2100 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0516_L15.5mm_D5.0mm_P20.32mm_Horizontal" V 3440 2090 50  0001 C CNN
F 3 "~" H 3400 2100 50  0001 C CNN
	1    3400 2100
	0    1    1    0   
$EndComp
Wire Wire Line
	3150 2100 3250 2100
Text HLabel 1400 3500 0    50   Input ~ 0
L1_COIN_CONTROL
Text HLabel 5000 2400 2    50   UnSpc ~ 0
L1_COIN_RING
Wire Wire Line
	4700 2400 5000 2400
Text HLabel 1400 3700 0    50   Input ~ 0
COIN_OP
Wire Wire Line
	3750 2100 3750 3700
NoConn ~ 4100 2500
Wire Wire Line
	2150 2000 2100 2000
Wire Wire Line
	3300 2900 3500 2900
Wire Wire Line
	3500 2900 3500 2850
Connection ~ 3300 2900
Wire Wire Line
	3300 2900 3300 2700
Wire Wire Line
	3650 2500 3650 2100
Wire Wire Line
	3150 2500 3650 2500
Wire Wire Line
	3550 2100 3650 2100
Wire Wire Line
	3750 2100 4100 2100
Wire Wire Line
	3150 2300 4100 2300
Wire Wire Line
	3750 3700 1400 3700
$Comp
L 1d_coinctrl_r2-rescue:G5V-2-DC12-dk_Signal-Relays-Up-to-2-Amps RLY?
U 1 1 5BADEBBD
P 7600 2300
AR Path="/5BADEBBD" Ref="RLY?"  Part="1" 
AR Path="/5BA4B80D/5BADEBBD" Ref="RLY?"  Part="1" 
AR Path="/5BAA648F/5BADEBBD" Ref="K5"  Part="1" 
F 0 "K5" H 8088 2346 50  0000 L CNN
F 1 "L2_HOLD" H 8088 2255 50  0000 L CNN
F 2 "digikey-footprints:Relay_THT_G5V-2" H 7800 2500 50  0001 L CNN
F 3 "http://omronfs.omron.com/en_US/ecb/products/pdf/en-g5v_2.pdf" H 7800 2600 60  0001 L CNN
F 4 "Z768-ND" H 7800 2700 60  0001 L CNN "Digi-Key_PN"
F 5 "G5V-2-DC12" H 7800 2800 60  0001 L CNN "MPN"
F 6 "Relays" H 7800 2900 60  0001 L CNN "Category"
F 7 "Signal Relays, Up to 2 Amps" H 7800 3000 60  0001 L CNN "Family"
F 8 "http://omronfs.omron.com/en_US/ecb/products/pdf/en-g5v_2.pdf" H 7800 3100 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/omron-electronics-inc-emc-div/G5V-2-DC12/Z768-ND/87821" H 7800 3200 60  0001 L CNN "DK_Detail_Page"
F 10 "RELAY GEN PURPOSE DPDT 2A 12V" H 7800 3300 60  0001 L CNN "Description"
F 11 "Omron Electronics Inc-EMC Div" H 7800 3400 60  0001 L CNN "Manufacturer"
F 12 "Active" H 7800 3500 60  0001 L CNN "Status"
	1    7600 2300
	0    1    -1   0   
$EndComp
Text HLabel 6150 2000 0    50   UnSpc ~ 0
L2_CO_TIP
Text HLabel 6150 2400 0    50   UnSpc ~ 0
L2_CO_RING
Wire Wire Line
	7300 2400 6150 2400
$Comp
L 1d_coinctrl_r2-rescue:+12V_RELAY-power #PWR?
U 1 1 5BADEBD7
P 8250 2850
AR Path="/5BA4B80D/5BADEBD7" Ref="#PWR?"  Part="1" 
AR Path="/5BAA648F/5BADEBD7" Ref="#PWR044"  Part="1" 
F 0 "#PWR044" H 8250 2700 50  0001 C CNN
F 1 "+12V_RELAY" H 8265 3023 50  0000 C CNN
F 2 "" H 8250 2850 50  0001 C CNN
F 3 "" H 8250 2850 50  0001 C CNN
	1    8250 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	7900 2700 8050 2700
$Comp
L Diode:1N4148 D?
U 1 1 5BADEBDE
P 7650 3250
AR Path="/5BADEBDE" Ref="D?"  Part="1" 
AR Path="/5BA4B80D/5BADEBDE" Ref="D?"  Part="1" 
AR Path="/5BAA648F/5BADEBDE" Ref="D14"  Part="1" 
F 0 "D14" V 7604 3329 50  0000 L CNN
F 1 "1N4148" V 7695 3329 50  0000 L CNN
F 2 "Diode_THT:D_DO-35_SOD27_P7.62mm_Horizontal" H 7650 3075 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/1N4148_1N4448.pdf" H 7650 3250 50  0001 C CNN
	1    7650 3250
	-1   0    0    -1  
$EndComp
Wire Wire Line
	7800 3250 8050 3250
Wire Wire Line
	8050 3250 8050 2900
Wire Wire Line
	7500 3250 7150 3250
Wire Wire Line
	7150 3250 7150 2700
Wire Wire Line
	7150 2700 7300 2700
Wire Wire Line
	7150 2700 6150 2700
Connection ~ 7150 2700
Text HLabel 6150 2700 0    50   Input ~ 0
L2_HOLD_CO
Text HLabel 9850 2000 2    50   UnSpc ~ 0
L2_COIN_TIP
$Comp
L 1d_coinctrl_r2-rescue:G5V-2-DC12-dk_Signal-Relays-Up-to-2-Amps RLY?
U 1 1 5BADEBF7
P 9150 2300
AR Path="/5BADEBF7" Ref="RLY?"  Part="1" 
AR Path="/5BA4B80D/5BADEBF7" Ref="RLY?"  Part="1" 
AR Path="/5BAA648F/5BADEBF7" Ref="K6"  Part="1" 
F 0 "K6" H 9638 2346 50  0000 L CNN
F 1 "L2_COIN_CTRL" H 9638 2255 50  0000 L CNN
F 2 "digikey-footprints:Relay_THT_G5V-2" H 9350 2500 50  0001 L CNN
F 3 "http://omronfs.omron.com/en_US/ecb/products/pdf/en-g5v_2.pdf" H 9350 2600 60  0001 L CNN
F 4 "Z768-ND" H 9350 2700 60  0001 L CNN "Digi-Key_PN"
F 5 "G5V-2-DC12" H 9350 2800 60  0001 L CNN "MPN"
F 6 "Relays" H 9350 2900 60  0001 L CNN "Category"
F 7 "Signal Relays, Up to 2 Amps" H 9350 3000 60  0001 L CNN "Family"
F 8 "http://omronfs.omron.com/en_US/ecb/products/pdf/en-g5v_2.pdf" H 9350 3100 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/omron-electronics-inc-emc-div/G5V-2-DC12/Z768-ND/87821" H 9350 3200 60  0001 L CNN "DK_Detail_Page"
F 10 "RELAY GEN PURPOSE DPDT 2A 12V" H 9350 3300 60  0001 L CNN "Description"
F 11 "Omron Electronics Inc-EMC Div" H 9350 3400 60  0001 L CNN "Manufacturer"
F 12 "Active" H 9350 3500 60  0001 L CNN "Status"
	1    9150 2300
	0    -1   -1   0   
$EndComp
$Comp
L 1d_coinctrl_r2-rescue:+12V_RELAY-power #PWR046
U 1 1 5BADEBFE
P 8750 2650
F 0 "#PWR046" H 8750 2500 50  0001 C CNN
F 1 "+12V_RELAY" H 8765 2823 50  0000 C CNN
F 2 "" H 8750 2650 50  0001 C CNN
F 3 "" H 8750 2650 50  0001 C CNN
	1    8750 2650
	1    0    0    -1  
$EndComp
$Comp
L Diode:1N4148 D?
U 1 1 5BADEC05
P 9150 3250
AR Path="/5BADEC05" Ref="D?"  Part="1" 
AR Path="/5BA4B80D/5BADEC05" Ref="D?"  Part="1" 
AR Path="/5BAA648F/5BADEC05" Ref="D16"  Part="1" 
F 0 "D16" V 9104 3329 50  0000 L CNN
F 1 "1N4148" V 9195 3329 50  0000 L CNN
F 2 "Diode_THT:D_DO-35_SOD27_P7.62mm_Horizontal" H 9150 3075 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/1N4148_1N4448.pdf" H 9150 3250 50  0001 C CNN
	1    9150 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	8850 1900 7900 1900
Wire Wire Line
	9450 2000 9850 2000
$Comp
L Device:R_US R12
U 1 1 5BADEC1D
P 8150 2100
F 0 "R12" V 8050 2100 50  0000 C CNN
F 1 "120 2W" V 8250 2100 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0516_L15.5mm_D5.0mm_P20.32mm_Horizontal" V 8190 2090 50  0001 C CNN
F 3 "~" H 8150 2100 50  0001 C CNN
	1    8150 2100
	0    1    1    0   
$EndComp
Wire Wire Line
	7900 2100 8000 2100
Text HLabel 6150 3500 0    50   Input ~ 0
L2_COIN_CONTROL
Text HLabel 9850 2400 2    50   UnSpc ~ 0
L2_COIN_RING
Wire Wire Line
	9450 2400 9850 2400
Wire Wire Line
	8500 2100 8500 3700
NoConn ~ 8850 2500
Wire Wire Line
	8050 2900 8250 2900
Wire Wire Line
	8250 2900 8250 2850
Connection ~ 8050 2900
Wire Wire Line
	8050 2900 8050 2700
Wire Wire Line
	8400 2500 8400 2100
Wire Wire Line
	7900 2500 8400 2500
Wire Wire Line
	8300 2100 8400 2100
Wire Wire Line
	8500 2100 8850 2100
Wire Wire Line
	7900 2300 8850 2300
Wire Wire Line
	3750 3700 8500 3700
Connection ~ 3750 3700
$Comp
L 1d_coinctrl_r2-rescue:G5V-2-DC12-dk_Signal-Relays-Up-to-2-Amps RLY?
U 1 1 5BAE9B65
P 2850 5300
AR Path="/5BAE9B65" Ref="RLY?"  Part="1" 
AR Path="/5BA4B80D/5BAE9B65" Ref="RLY?"  Part="1" 
AR Path="/5BAA648F/5BAE9B65" Ref="K7"  Part="1" 
F 0 "K7" H 3338 5346 50  0000 L CNN
F 1 "L3_HOLD" H 3338 5255 50  0000 L CNN
F 2 "digikey-footprints:Relay_THT_G5V-2" H 3050 5500 50  0001 L CNN
F 3 "http://omronfs.omron.com/en_US/ecb/products/pdf/en-g5v_2.pdf" H 3050 5600 60  0001 L CNN
F 4 "Z768-ND" H 3050 5700 60  0001 L CNN "Digi-Key_PN"
F 5 "G5V-2-DC12" H 3050 5800 60  0001 L CNN "MPN"
F 6 "Relays" H 3050 5900 60  0001 L CNN "Category"
F 7 "Signal Relays, Up to 2 Amps" H 3050 6000 60  0001 L CNN "Family"
F 8 "http://omronfs.omron.com/en_US/ecb/products/pdf/en-g5v_2.pdf" H 3050 6100 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/omron-electronics-inc-emc-div/G5V-2-DC12/Z768-ND/87821" H 3050 6200 60  0001 L CNN "DK_Detail_Page"
F 10 "RELAY GEN PURPOSE DPDT 2A 12V" H 3050 6300 60  0001 L CNN "Description"
F 11 "Omron Electronics Inc-EMC Div" H 3050 6400 60  0001 L CNN "Manufacturer"
F 12 "Active" H 3050 6500 60  0001 L CNN "Status"
	1    2850 5300
	0    1    -1   0   
$EndComp
Text HLabel 1400 5000 0    50   UnSpc ~ 0
L3_CO_TIP
Text HLabel 1400 5400 0    50   UnSpc ~ 0
L3_CO_RING
Wire Wire Line
	2550 5400 1400 5400
$Comp
L 1d_coinctrl_r2-rescue:+12V_RELAY-power #PWR?
U 1 1 5BAE9B7D
P 3500 5850
AR Path="/5BA4B80D/5BAE9B7D" Ref="#PWR?"  Part="1" 
AR Path="/5BAA648F/5BAE9B7D" Ref="#PWR037"  Part="1" 
F 0 "#PWR037" H 3500 5700 50  0001 C CNN
F 1 "+12V_RELAY" H 3515 6023 50  0000 C CNN
F 2 "" H 3500 5850 50  0001 C CNN
F 3 "" H 3500 5850 50  0001 C CNN
	1    3500 5850
	1    0    0    -1  
$EndComp
Wire Wire Line
	3150 5700 3300 5700
$Comp
L Diode:1N4148 D?
U 1 1 5BAE9B84
P 2900 6250
AR Path="/5BAE9B84" Ref="D?"  Part="1" 
AR Path="/5BA4B80D/5BAE9B84" Ref="D?"  Part="1" 
AR Path="/5BAA648F/5BAE9B84" Ref="D9"  Part="1" 
F 0 "D9" V 2854 6329 50  0000 L CNN
F 1 "1N4148" V 2945 6329 50  0000 L CNN
F 2 "Diode_THT:D_DO-35_SOD27_P7.62mm_Horizontal" H 2900 6075 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/1N4148_1N4448.pdf" H 2900 6250 50  0001 C CNN
	1    2900 6250
	-1   0    0    -1  
$EndComp
Wire Wire Line
	3050 6250 3300 6250
Wire Wire Line
	3300 6250 3300 5900
Wire Wire Line
	2750 6250 2400 6250
Wire Wire Line
	2400 6250 2400 5700
Wire Wire Line
	2400 5700 2550 5700
Wire Wire Line
	2400 5700 1400 5700
Connection ~ 2400 5700
Text HLabel 1400 5700 0    50   Input ~ 0
L3_HOLD_CO
Text HLabel 5000 5000 2    50   UnSpc ~ 0
L3_COIN_TIP
$Comp
L 1d_coinctrl_r2-rescue:G5V-2-DC12-dk_Signal-Relays-Up-to-2-Amps RLY?
U 1 1 5BAE9B9C
P 4400 5300
AR Path="/5BAE9B9C" Ref="RLY?"  Part="1" 
AR Path="/5BA4B80D/5BAE9B9C" Ref="RLY?"  Part="1" 
AR Path="/5BAA648F/5BAE9B9C" Ref="K8"  Part="1" 
F 0 "K8" H 4888 5346 50  0000 L CNN
F 1 "L3_COIN_CTRL" H 4888 5255 50  0000 L CNN
F 2 "digikey-footprints:Relay_THT_G5V-2" H 4600 5500 50  0001 L CNN
F 3 "http://omronfs.omron.com/en_US/ecb/products/pdf/en-g5v_2.pdf" H 4600 5600 60  0001 L CNN
F 4 "Z768-ND" H 4600 5700 60  0001 L CNN "Digi-Key_PN"
F 5 "G5V-2-DC12" H 4600 5800 60  0001 L CNN "MPN"
F 6 "Relays" H 4600 5900 60  0001 L CNN "Category"
F 7 "Signal Relays, Up to 2 Amps" H 4600 6000 60  0001 L CNN "Family"
F 8 "http://omronfs.omron.com/en_US/ecb/products/pdf/en-g5v_2.pdf" H 4600 6100 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/omron-electronics-inc-emc-div/G5V-2-DC12/Z768-ND/87821" H 4600 6200 60  0001 L CNN "DK_Detail_Page"
F 10 "RELAY GEN PURPOSE DPDT 2A 12V" H 4600 6300 60  0001 L CNN "Description"
F 11 "Omron Electronics Inc-EMC Div" H 4600 6400 60  0001 L CNN "Manufacturer"
F 12 "Active" H 4600 6500 60  0001 L CNN "Status"
	1    4400 5300
	0    -1   -1   0   
$EndComp
$Comp
L 1d_coinctrl_r2-rescue:+12V_RELAY-power #PWR039
U 1 1 5BAE9BA2
P 4000 5650
F 0 "#PWR039" H 4000 5500 50  0001 C CNN
F 1 "+12V_RELAY" H 4015 5823 50  0000 C CNN
F 2 "" H 4000 5650 50  0001 C CNN
F 3 "" H 4000 5650 50  0001 C CNN
	1    4000 5650
	1    0    0    -1  
$EndComp
$Comp
L Diode:1N4148 D?
U 1 1 5BAE9BA9
P 4400 6250
AR Path="/5BAE9BA9" Ref="D?"  Part="1" 
AR Path="/5BA4B80D/5BAE9BA9" Ref="D?"  Part="1" 
AR Path="/5BAA648F/5BAE9BA9" Ref="D11"  Part="1" 
F 0 "D11" V 4354 6329 50  0000 L CNN
F 1 "1N4148" V 4445 6329 50  0000 L CNN
F 2 "Diode_THT:D_DO-35_SOD27_P7.62mm_Horizontal" H 4400 6075 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/1N4148_1N4448.pdf" H 4400 6250 50  0001 C CNN
	1    4400 6250
	1    0    0    -1  
$EndComp
Wire Wire Line
	4850 6250 4850 5700
Wire Wire Line
	4100 4900 3150 4900
Wire Wire Line
	4700 5000 5000 5000
$Comp
L Device:R_US R9
U 1 1 5BAE9BC0
P 3400 5100
F 0 "R9" V 3300 5100 50  0000 C CNN
F 1 "120 2W" V 3500 5100 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0516_L15.5mm_D5.0mm_P20.32mm_Horizontal" V 3440 5090 50  0001 C CNN
F 3 "~" H 3400 5100 50  0001 C CNN
	1    3400 5100
	0    1    1    0   
$EndComp
Wire Wire Line
	3150 5100 3250 5100
Text HLabel 1400 6400 0    50   Input ~ 0
L3_COIN_CONTROL
Text HLabel 5000 5400 2    50   UnSpc ~ 0
L3_COIN_RING
Wire Wire Line
	4700 5400 5000 5400
NoConn ~ 4100 5500
Wire Wire Line
	3300 5900 3500 5900
Wire Wire Line
	3500 5900 3500 5850
Connection ~ 3300 5900
Wire Wire Line
	3300 5900 3300 5700
Wire Wire Line
	3650 5500 3650 5100
Wire Wire Line
	3150 5500 3650 5500
Wire Wire Line
	3550 5100 3650 5100
Wire Wire Line
	4550 6250 4850 6250
Wire Wire Line
	4700 5700 4850 5700
Wire Wire Line
	3750 5100 4100 5100
Wire Wire Line
	3150 5300 4100 5300
$Comp
L 1d_coinctrl_r2-rescue:G5V-2-DC12-dk_Signal-Relays-Up-to-2-Amps RLY?
U 1 1 5BAE9C06
P 7600 5300
AR Path="/5BAE9C06" Ref="RLY?"  Part="1" 
AR Path="/5BA4B80D/5BAE9C06" Ref="RLY?"  Part="1" 
AR Path="/5BAA648F/5BAE9C06" Ref="K9"  Part="1" 
F 0 "K9" H 8088 5346 50  0000 L CNN
F 1 "L4_HOLD" H 8088 5255 50  0000 L CNN
F 2 "digikey-footprints:Relay_THT_G5V-2" H 7800 5500 50  0001 L CNN
F 3 "http://omronfs.omron.com/en_US/ecb/products/pdf/en-g5v_2.pdf" H 7800 5600 60  0001 L CNN
F 4 "Z768-ND" H 7800 5700 60  0001 L CNN "Digi-Key_PN"
F 5 "G5V-2-DC12" H 7800 5800 60  0001 L CNN "MPN"
F 6 "Relays" H 7800 5900 60  0001 L CNN "Category"
F 7 "Signal Relays, Up to 2 Amps" H 7800 6000 60  0001 L CNN "Family"
F 8 "http://omronfs.omron.com/en_US/ecb/products/pdf/en-g5v_2.pdf" H 7800 6100 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/omron-electronics-inc-emc-div/G5V-2-DC12/Z768-ND/87821" H 7800 6200 60  0001 L CNN "DK_Detail_Page"
F 10 "RELAY GEN PURPOSE DPDT 2A 12V" H 7800 6300 60  0001 L CNN "Description"
F 11 "Omron Electronics Inc-EMC Div" H 7800 6400 60  0001 L CNN "Manufacturer"
F 12 "Active" H 7800 6500 60  0001 L CNN "Status"
	1    7600 5300
	0    1    -1   0   
$EndComp
Text HLabel 6150 5000 0    50   UnSpc ~ 0
L4_CO_TIP
Text HLabel 6150 5400 0    50   UnSpc ~ 0
L4_CO_RING
Wire Wire Line
	7300 5400 6150 5400
$Comp
L 1d_coinctrl_r2-rescue:+12V_RELAY-power #PWR?
U 1 1 5BAE9C1E
P 8250 5850
AR Path="/5BA4B80D/5BAE9C1E" Ref="#PWR?"  Part="1" 
AR Path="/5BAA648F/5BAE9C1E" Ref="#PWR045"  Part="1" 
F 0 "#PWR045" H 8250 5700 50  0001 C CNN
F 1 "+12V_RELAY" H 8265 6023 50  0000 C CNN
F 2 "" H 8250 5850 50  0001 C CNN
F 3 "" H 8250 5850 50  0001 C CNN
	1    8250 5850
	1    0    0    -1  
$EndComp
Wire Wire Line
	7900 5700 8050 5700
$Comp
L Diode:1N4148 D?
U 1 1 5BAE9C25
P 7650 6250
AR Path="/5BAE9C25" Ref="D?"  Part="1" 
AR Path="/5BA4B80D/5BAE9C25" Ref="D?"  Part="1" 
AR Path="/5BAA648F/5BAE9C25" Ref="D15"  Part="1" 
F 0 "D15" V 7604 6329 50  0000 L CNN
F 1 "1N4148" V 7695 6329 50  0000 L CNN
F 2 "Diode_THT:D_DO-35_SOD27_P7.62mm_Horizontal" H 7650 6075 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/1N4148_1N4448.pdf" H 7650 6250 50  0001 C CNN
	1    7650 6250
	-1   0    0    -1  
$EndComp
Wire Wire Line
	7800 6250 8050 6250
Wire Wire Line
	8050 6250 8050 5900
Wire Wire Line
	7500 6250 7150 6250
Wire Wire Line
	7150 6250 7150 5700
Wire Wire Line
	7150 5700 7300 5700
Wire Wire Line
	7150 5700 6150 5700
Connection ~ 7150 5700
Text HLabel 6150 5700 0    50   Input ~ 0
L4_HOLD_CO
Text HLabel 9850 5000 2    50   UnSpc ~ 0
L4_COIN_TIP
$Comp
L 1d_coinctrl_r2-rescue:G5V-2-DC12-dk_Signal-Relays-Up-to-2-Amps RLY?
U 1 1 5BAE9C3D
P 9150 5300
AR Path="/5BAE9C3D" Ref="RLY?"  Part="1" 
AR Path="/5BA4B80D/5BAE9C3D" Ref="RLY?"  Part="1" 
AR Path="/5BAA648F/5BAE9C3D" Ref="K10"  Part="1" 
F 0 "K10" H 9638 5346 50  0000 L CNN
F 1 "L4_COIN_CTRL" H 9638 5255 50  0000 L CNN
F 2 "digikey-footprints:Relay_THT_G5V-2" H 9350 5500 50  0001 L CNN
F 3 "http://omronfs.omron.com/en_US/ecb/products/pdf/en-g5v_2.pdf" H 9350 5600 60  0001 L CNN
F 4 "Z768-ND" H 9350 5700 60  0001 L CNN "Digi-Key_PN"
F 5 "G5V-2-DC12" H 9350 5800 60  0001 L CNN "MPN"
F 6 "Relays" H 9350 5900 60  0001 L CNN "Category"
F 7 "Signal Relays, Up to 2 Amps" H 9350 6000 60  0001 L CNN "Family"
F 8 "http://omronfs.omron.com/en_US/ecb/products/pdf/en-g5v_2.pdf" H 9350 6100 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/omron-electronics-inc-emc-div/G5V-2-DC12/Z768-ND/87821" H 9350 6200 60  0001 L CNN "DK_Detail_Page"
F 10 "RELAY GEN PURPOSE DPDT 2A 12V" H 9350 6300 60  0001 L CNN "Description"
F 11 "Omron Electronics Inc-EMC Div" H 9350 6400 60  0001 L CNN "Manufacturer"
F 12 "Active" H 9350 6500 60  0001 L CNN "Status"
	1    9150 5300
	0    -1   -1   0   
$EndComp
$Comp
L 1d_coinctrl_r2-rescue:+12V_RELAY-power #PWR047
U 1 1 5BAE9C43
P 8750 5650
F 0 "#PWR047" H 8750 5500 50  0001 C CNN
F 1 "+12V_RELAY" H 8765 5823 50  0000 C CNN
F 2 "" H 8750 5650 50  0001 C CNN
F 3 "" H 8750 5650 50  0001 C CNN
	1    8750 5650
	1    0    0    -1  
$EndComp
$Comp
L Diode:1N4148 D?
U 1 1 5BAE9C4A
P 9150 6250
AR Path="/5BAE9C4A" Ref="D?"  Part="1" 
AR Path="/5BA4B80D/5BAE9C4A" Ref="D?"  Part="1" 
AR Path="/5BAA648F/5BAE9C4A" Ref="D17"  Part="1" 
F 0 "D17" V 9104 6329 50  0000 L CNN
F 1 "1N4148" V 9195 6329 50  0000 L CNN
F 2 "Diode_THT:D_DO-35_SOD27_P7.62mm_Horizontal" H 9150 6075 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/1N4148_1N4448.pdf" H 9150 6250 50  0001 C CNN
	1    9150 6250
	1    0    0    -1  
$EndComp
Wire Wire Line
	9600 6250 9600 5700
Wire Wire Line
	8750 6250 8750 5700
Wire Wire Line
	8850 4900 7900 4900
Wire Wire Line
	9450 5000 9850 5000
$Comp
L Device:R_US R15
U 1 1 5BAE9C61
P 8150 5100
F 0 "R15" V 8050 5100 50  0000 C CNN
F 1 "120 2W" V 8250 5100 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0516_L15.5mm_D5.0mm_P20.32mm_Horizontal" V 8190 5090 50  0001 C CNN
F 3 "~" H 8150 5100 50  0001 C CNN
	1    8150 5100
	0    1    1    0   
$EndComp
Wire Wire Line
	7900 5100 8000 5100
Text HLabel 6150 6400 0    50   Input ~ 0
L4_COIN_CONTROL
Text HLabel 9850 5400 2    50   UnSpc ~ 0
L4_COIN_RING
Wire Wire Line
	9450 5400 9850 5400
NoConn ~ 8850 5500
Wire Wire Line
	8050 5900 8250 5900
Wire Wire Line
	8250 5900 8250 5850
Connection ~ 8050 5900
Wire Wire Line
	8050 5900 8050 5700
Wire Wire Line
	8400 5500 8400 5100
Wire Wire Line
	7900 5500 8400 5500
Wire Wire Line
	8300 5100 8400 5100
Wire Wire Line
	8850 5700 8750 5700
Wire Wire Line
	8750 6250 9000 6250
Wire Wire Line
	9300 6250 9600 6250
Wire Wire Line
	9450 5700 9600 5700
Wire Wire Line
	8500 5100 8850 5100
Wire Wire Line
	7900 5300 8850 5300
Wire Wire Line
	3750 5100 3750 3700
Wire Wire Line
	8500 5100 8500 3700
Connection ~ 8500 3700
Wire Wire Line
	4000 2650 4000 2700
Wire Wire Line
	4000 2700 4100 2700
Wire Wire Line
	4250 3250 4000 3250
Wire Wire Line
	4000 3250 4000 2700
Connection ~ 4000 2700
Wire Wire Line
	4800 3500 4800 3250
Wire Wire Line
	4800 2700 4700 2700
Wire Wire Line
	1400 3500 4800 3500
Wire Wire Line
	4550 3250 4800 3250
Connection ~ 4800 3250
Wire Wire Line
	4800 3250 4800 2700
Wire Wire Line
	9600 3500 9600 3250
Wire Wire Line
	6150 3500 9600 3500
Wire Wire Line
	8750 2650 8750 2700
Wire Wire Line
	8750 2700 8850 2700
Wire Wire Line
	8750 2700 8750 3250
Wire Wire Line
	8750 3250 9000 3250
Connection ~ 8750 2700
Wire Wire Line
	9300 3250 9600 3250
Connection ~ 9600 3250
Wire Wire Line
	9600 2700 9450 2700
Wire Wire Line
	9600 2700 9600 3250
Wire Wire Line
	1400 6400 4850 6400
Wire Wire Line
	4850 6400 4850 6250
Connection ~ 4850 6250
Wire Wire Line
	4100 5700 4000 5700
Wire Wire Line
	4000 5700 4000 6250
Wire Wire Line
	4000 6250 4250 6250
Wire Wire Line
	4000 5700 4000 5650
Connection ~ 4000 5700
Wire Wire Line
	6150 6400 9600 6400
Wire Wire Line
	9600 6400 9600 6250
Connection ~ 9600 6250
Wire Wire Line
	8750 5700 8750 5650
Connection ~ 8750 5700
Text Notes 7000 6900 0    197  Italic 39
1D Coin Controller
Text Notes 7050 7100 0    50   Italic 10
(c) 2020, Howard M. Harte - WZ2Q\nhttps://github.com/hharte/1dcoinctrl
Text Notes 10550 7650 0    50   ~ 0
2
Text Notes 7400 7500 0    50   ~ 0
1D Coin Controller - Coin Line Control
Text Notes 8150 7650 0    50   ~ 0
2020-06-27
$Comp
L Isolator:ILD74 U7
U 1 1 5EF649BB
P 2000 950
F 0 "U7" H 2000 1275 50  0000 C CNN
F 1 "ILD74" H 2000 1184 50  0000 C CNN
F 2 "Package_DIP:DIP-8_W7.62mm_Socket" H 1800 750 50  0001 L CIN
F 3 "https://www.vishay.com/docs/83640/ild74.pdf" H 2000 950 50  0001 L CNN
	1    2000 950 
	-1   0    0    -1  
$EndComp
$Comp
L Isolator:ILD74 U7
U 2 1 5EF652BA
P 2000 1500
F 0 "U7" H 2000 1825 50  0000 C CNN
F 1 "ILD74" H 2000 1734 50  0000 C CNN
F 2 "Package_DIP:DIP-8_W7.62mm_Socket" H 1800 1300 50  0001 L CIN
F 3 "https://www.vishay.com/docs/83640/ild74.pdf" H 2000 1500 50  0001 L CNN
	2    2000 1500
	-1   0    0    -1  
$EndComp
Wire Wire Line
	2300 1400 2400 1400
Wire Wire Line
	2400 1400 2400 1050
Wire Wire Line
	2400 1050 2300 1050
Wire Wire Line
	1600 1050 1700 1050
$Comp
L Device:R_US R6
U 1 1 5EF99E9D
P 2300 2000
F 0 "R6" V 2095 2000 50  0000 C CNN
F 1 "120" V 2186 2000 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 2340 1990 50  0001 C CNN
F 3 "~" H 2300 2000 50  0001 C CNN
	1    2300 2000
	0    1    1    0   
$EndComp
Wire Wire Line
	2450 2000 2500 2000
Wire Wire Line
	1600 1700 1600 1600
Wire Wire Line
	1600 1600 1600 1050
Connection ~ 1600 1600
Wire Wire Line
	1600 1600 1700 1600
Text HLabel 1350 850  0    50   Output ~ 0
L1_OFF_HOOK_R
Wire Wire Line
	1700 1400 1350 1400
Wire Wire Line
	1700 850  1350 850 
Wire Wire Line
	2500 2000 2500 1600
Connection ~ 2500 2000
Wire Wire Line
	2500 2000 2550 2000
Wire Wire Line
	2500 1600 2300 1600
Wire Wire Line
	2500 1600 2500 850 
Wire Wire Line
	2500 850  2300 850 
Connection ~ 2500 1600
Wire Wire Line
	2400 1400 2400 1750
Wire Wire Line
	2400 1750 2100 1750
Wire Wire Line
	2100 1750 2100 2000
Connection ~ 2400 1400
Connection ~ 2100 2000
Wire Wire Line
	2100 2000 1400 2000
$Comp
L power:GND #PWR?
U 1 1 5F0821BC
P 6350 1700
AR Path="/5BA4B80D/5F0821BC" Ref="#PWR?"  Part="1" 
AR Path="/5BAA648F/5F0821BC" Ref="#PWR0121"  Part="1" 
F 0 "#PWR0121" H 6350 1450 50  0001 C CNN
F 1 "GND" H 6355 1527 50  0000 C CNN
F 2 "" H 6350 1700 50  0001 C CNN
F 3 "" H 6350 1700 50  0001 C CNN
	1    6350 1700
	1    0    0    -1  
$EndComp
Wire Wire Line
	6900 2000 6850 2000
$Comp
L Isolator:ILD74 U9
U 1 1 5F0821C3
P 6750 950
F 0 "U9" H 6750 1275 50  0000 C CNN
F 1 "ILD74" H 6750 1184 50  0000 C CNN
F 2 "Package_DIP:DIP-8_W7.62mm_Socket" H 6550 750 50  0001 L CIN
F 3 "https://www.vishay.com/docs/83640/ild74.pdf" H 6750 950 50  0001 L CNN
	1    6750 950 
	-1   0    0    -1  
$EndComp
$Comp
L Isolator:ILD74 U9
U 2 1 5F0821C9
P 6750 1500
F 0 "U9" H 6750 1825 50  0000 C CNN
F 1 "ILD74" H 6750 1734 50  0000 C CNN
F 2 "Package_DIP:DIP-8_W7.62mm_Socket" H 6550 1300 50  0001 L CIN
F 3 "https://www.vishay.com/docs/83640/ild74.pdf" H 6750 1500 50  0001 L CNN
	2    6750 1500
	-1   0    0    -1  
$EndComp
Wire Wire Line
	7050 1400 7150 1400
Wire Wire Line
	7150 1400 7150 1050
Wire Wire Line
	7150 1050 7050 1050
Wire Wire Line
	6350 1050 6450 1050
$Comp
L Device:R_US R10
U 1 1 5F0821D3
P 7050 2000
F 0 "R10" V 6845 2000 50  0000 C CNN
F 1 "120" V 6936 2000 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 7090 1990 50  0001 C CNN
F 3 "~" H 7050 2000 50  0001 C CNN
	1    7050 2000
	0    1    1    0   
$EndComp
Wire Wire Line
	7200 2000 7250 2000
Wire Wire Line
	6350 1700 6350 1600
Wire Wire Line
	6350 1600 6350 1050
Connection ~ 6350 1600
Wire Wire Line
	6350 1600 6450 1600
Wire Wire Line
	6450 1400 6100 1400
Wire Wire Line
	6450 850  6100 850 
Wire Wire Line
	7250 2000 7250 1600
Connection ~ 7250 2000
Wire Wire Line
	7250 2000 7300 2000
Wire Wire Line
	7250 1600 7050 1600
Wire Wire Line
	7250 1600 7250 850 
Wire Wire Line
	7250 850  7050 850 
Connection ~ 7250 1600
Wire Wire Line
	7150 1400 7150 1750
Wire Wire Line
	7150 1750 6850 1750
Wire Wire Line
	6850 1750 6850 2000
Connection ~ 7150 1400
Connection ~ 6850 2000
Wire Wire Line
	6850 2000 6150 2000
Text HLabel 6100 1400 0    50   Output ~ 0
L2_OFF_HOOK_F
Text HLabel 6100 850  0    50   Output ~ 0
L2_OFF_HOOK_R
$Comp
L power:GND #PWR?
U 1 1 5F0ACFE7
P 6350 4700
AR Path="/5BA4B80D/5F0ACFE7" Ref="#PWR?"  Part="1" 
AR Path="/5BAA648F/5F0ACFE7" Ref="#PWR0122"  Part="1" 
F 0 "#PWR0122" H 6350 4450 50  0001 C CNN
F 1 "GND" H 6355 4527 50  0000 C CNN
F 2 "" H 6350 4700 50  0001 C CNN
F 3 "" H 6350 4700 50  0001 C CNN
	1    6350 4700
	1    0    0    -1  
$EndComp
Wire Wire Line
	6900 5000 6850 5000
$Comp
L Isolator:ILD74 U10
U 1 1 5F0ACFEE
P 6750 3950
F 0 "U10" H 6750 4275 50  0000 C CNN
F 1 "ILD74" H 6750 4184 50  0000 C CNN
F 2 "Package_DIP:DIP-8_W7.62mm_Socket" H 6550 3750 50  0001 L CIN
F 3 "https://www.vishay.com/docs/83640/ild74.pdf" H 6750 3950 50  0001 L CNN
	1    6750 3950
	-1   0    0    -1  
$EndComp
$Comp
L Isolator:ILD74 U10
U 2 1 5F0ACFF4
P 6750 4500
F 0 "U10" H 6750 4825 50  0000 C CNN
F 1 "ILD74" H 6750 4734 50  0000 C CNN
F 2 "Package_DIP:DIP-8_W7.62mm_Socket" H 6550 4300 50  0001 L CIN
F 3 "https://www.vishay.com/docs/83640/ild74.pdf" H 6750 4500 50  0001 L CNN
	2    6750 4500
	-1   0    0    -1  
$EndComp
Wire Wire Line
	7050 4400 7150 4400
Wire Wire Line
	7150 4400 7150 4050
Wire Wire Line
	7150 4050 7050 4050
Wire Wire Line
	6350 4050 6450 4050
$Comp
L Device:R_US R11
U 1 1 5F0ACFFE
P 7050 5000
F 0 "R11" V 6845 5000 50  0000 C CNN
F 1 "120" V 6936 5000 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 7090 4990 50  0001 C CNN
F 3 "~" H 7050 5000 50  0001 C CNN
	1    7050 5000
	0    1    1    0   
$EndComp
Wire Wire Line
	7200 5000 7250 5000
Wire Wire Line
	6350 4700 6350 4600
Wire Wire Line
	6350 4600 6350 4050
Connection ~ 6350 4600
Wire Wire Line
	6350 4600 6450 4600
Wire Wire Line
	6450 4400 6100 4400
Wire Wire Line
	6450 3850 6100 3850
Wire Wire Line
	7250 5000 7250 4600
Connection ~ 7250 5000
Wire Wire Line
	7250 5000 7300 5000
Wire Wire Line
	7250 4600 7050 4600
Wire Wire Line
	7250 4600 7250 3850
Wire Wire Line
	7250 3850 7050 3850
Connection ~ 7250 4600
Wire Wire Line
	7150 4400 7150 4750
Wire Wire Line
	7150 4750 6850 4750
Wire Wire Line
	6850 4750 6850 5000
Connection ~ 7150 4400
Connection ~ 6850 5000
Wire Wire Line
	6850 5000 6150 5000
Text HLabel 6100 4400 0    50   Output ~ 0
L4_OFF_HOOK_F
Text HLabel 6100 3850 0    50   Output ~ 0
L4_OFF_HOOK_R
$Comp
L power:GND #PWR?
U 1 1 5F0D2B36
P 1600 4700
AR Path="/5BA4B80D/5F0D2B36" Ref="#PWR?"  Part="1" 
AR Path="/5BAA648F/5F0D2B36" Ref="#PWR0123"  Part="1" 
F 0 "#PWR0123" H 1600 4450 50  0001 C CNN
F 1 "GND" H 1605 4527 50  0000 C CNN
F 2 "" H 1600 4700 50  0001 C CNN
F 3 "" H 1600 4700 50  0001 C CNN
	1    1600 4700
	1    0    0    -1  
$EndComp
Wire Wire Line
	2150 5000 2100 5000
$Comp
L Isolator:ILD74 U8
U 1 1 5F0D2B3D
P 2000 3950
F 0 "U8" H 2000 4275 50  0000 C CNN
F 1 "ILD74" H 2000 4184 50  0000 C CNN
F 2 "Package_DIP:DIP-8_W7.62mm_Socket" H 1800 3750 50  0001 L CIN
F 3 "https://www.vishay.com/docs/83640/ild74.pdf" H 2000 3950 50  0001 L CNN
	1    2000 3950
	-1   0    0    -1  
$EndComp
$Comp
L Isolator:ILD74 U8
U 2 1 5F0D2B43
P 2000 4500
F 0 "U8" H 2000 4825 50  0000 C CNN
F 1 "ILD74" H 2000 4734 50  0000 C CNN
F 2 "Package_DIP:DIP-8_W7.62mm_Socket" H 1800 4300 50  0001 L CIN
F 3 "https://www.vishay.com/docs/83640/ild74.pdf" H 2000 4500 50  0001 L CNN
	2    2000 4500
	-1   0    0    -1  
$EndComp
Wire Wire Line
	2300 4400 2400 4400
Wire Wire Line
	2400 4400 2400 4050
Wire Wire Line
	2400 4050 2300 4050
Wire Wire Line
	1600 4050 1700 4050
$Comp
L Device:R_US R7
U 1 1 5F0D2B4D
P 2300 5000
F 0 "R7" V 2095 5000 50  0000 C CNN
F 1 "120" V 2186 5000 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 2340 4990 50  0001 C CNN
F 3 "~" H 2300 5000 50  0001 C CNN
	1    2300 5000
	0    1    1    0   
$EndComp
Wire Wire Line
	2450 5000 2500 5000
Wire Wire Line
	1600 4700 1600 4600
Wire Wire Line
	1600 4600 1600 4050
Connection ~ 1600 4600
Wire Wire Line
	1600 4600 1700 4600
Wire Wire Line
	1700 4400 1350 4400
Wire Wire Line
	1700 3850 1350 3850
Wire Wire Line
	2500 5000 2500 4600
Connection ~ 2500 5000
Wire Wire Line
	2500 5000 2550 5000
Wire Wire Line
	2500 4600 2300 4600
Wire Wire Line
	2500 4600 2500 3850
Wire Wire Line
	2500 3850 2300 3850
Connection ~ 2500 4600
Wire Wire Line
	2400 4400 2400 4750
Wire Wire Line
	2400 4750 2100 4750
Wire Wire Line
	2100 4750 2100 5000
Connection ~ 2400 4400
Connection ~ 2100 5000
Wire Wire Line
	2100 5000 1400 5000
Text HLabel 1350 4400 0    50   Output ~ 0
L3_OFF_HOOK_F
Text HLabel 1350 3850 0    50   Output ~ 0
L3_OFF_HOOK_R
$EndSCHEMATC
