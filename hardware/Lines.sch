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
$Comp
L Isolator:H11AA1 U?
U 1 1 5BAA6BC5
P 1900 1500
AR Path="/5BAA6BC5" Ref="U?"  Part="1" 
AR Path="/5BA4B80D/5BAA6BC5" Ref="U?"  Part="1" 
AR Path="/5BAA648F/5BAA6BC5" Ref="U7"  Part="1" 
F 0 "U7" H 1900 1847 60  0000 C CNN
F 1 "H11AA1" H 1900 1741 60  0000 C CNN
F 2 "Package_DIP:DIP-6_W7.62mm" H 2100 1700 60  0001 L CNN
F 3 "http://www.onsemi.com/pub/Collateral/H11AA4M-D.pdf" H 2100 1800 60  0001 L CNN
F 4 "H11AA1M-ND" H 2100 1900 60  0001 L CNN "Digi-Key_PN"
F 5 "H11AA1" H 2100 2000 60  0001 L CNN "MPN"
F 6 "Isolators" H 2100 2100 60  0001 L CNN "Category"
F 7 "Optoisolators - Transistor, Photovoltaic Output" H 2100 2200 60  0001 L CNN "Family"
F 8 "http://www.onsemi.com/pub/Collateral/H11AA4M-D.pdf" H 2100 2300 60  0001 L CNN "DK_Datasheet_Link"
F 9 "https://www.digikey.com/product-detail/en/on-semiconductor/H11AA1M/H11AA1M-ND/1053602" H 2100 2400 60  0001 L CNN "DK_Detail_Page"
F 10 "OPTOISO 4.17KV TRANS W/BASE 6DIP" H 2100 2500 60  0001 L CNN "Description"
F 11 "ON Semiconductor" H 2100 2600 60  0001 L CNN "Manufacturer"
F 12 "Active" H 2100 2700 60  0001 L CNN "Status"
	1    1900 1500
	-1   0    0    -1  
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
P 1450 1700
AR Path="/5BA4B80D/5BAA6C1D" Ref="#PWR?"  Part="1" 
AR Path="/5BAA648F/5BAA6C1D" Ref="#PWR032"  Part="1" 
F 0 "#PWR032" H 1450 1450 50  0001 C CNN
F 1 "GND" H 1455 1527 50  0000 C CNN
F 2 "" H 1450 1700 50  0001 C CNN
F 3 "" H 1450 1700 50  0001 C CNN
	1    1450 1700
	1    0    0    -1  
$EndComp
Wire Wire Line
	1450 1700 1450 1600
Wire Wire Line
	1450 1600 1600 1600
Text HLabel 1350 1500 0    50   Output ~ 0
L1_OFF_HOOK_N
Wire Wire Line
	1350 1500 1500 1500
Wire Wire Line
	4700 2000 5000 2000
NoConn ~ 1600 1400
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
	2200 1600 2300 1600
Wire Wire Line
	2300 1600 2300 2000
Wire Wire Line
	2300 2000 1400 2000
Wire Wire Line
	2200 1400 2400 1400
Wire Wire Line
	2400 1400 2400 2000
Wire Wire Line
	2400 2000 2550 2000
$Comp
L Device:R_US R6
U 1 1 5BAB9452
P 1750 900
F 0 "R6" V 1545 900 50  0000 C CNN
F 1 "220" V 1636 900 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 1790 890 50  0001 C CNN
F 3 "~" H 1750 900 50  0001 C CNN
	1    1750 900 
	0    1    1    0   
$EndComp
$Comp
L Device:LED D6
U 1 1 5BAB9516
P 1500 1150
F 0 "D6" V 1538 1033 50  0000 R CNN
F 1 "LED" V 1447 1033 50  0000 R CNN
F 2 "LED_THT:LED_D5.0mm" H 1500 1150 50  0001 C CNN
F 3 "~" H 1500 1150 50  0001 C CNN
	1    1500 1150
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1500 1500 1500 1300
Connection ~ 1500 1500
Wire Wire Line
	1500 1500 1600 1500
Wire Wire Line
	1500 1000 1500 900 
Wire Wire Line
	1500 900  1600 900 
$Comp
L power:+5V #PWR034
U 1 1 5BAC3C63
P 1950 850
F 0 "#PWR034" H 1950 700 50  0001 C CNN
F 1 "+5V" H 1965 1023 50  0000 C CNN
F 2 "" H 1950 850 50  0001 C CNN
F 3 "" H 1950 850 50  0001 C CNN
	1    1950 850 
	1    0    0    -1  
$EndComp
Wire Wire Line
	1900 900  1950 900 
Wire Wire Line
	1950 900  1950 850 
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
$Comp
L Isolator:H11AA1 U?
U 1 1 5BADEBCD
P 6650 1500
AR Path="/5BADEBCD" Ref="U?"  Part="1" 
AR Path="/5BA4B80D/5BADEBCD" Ref="U?"  Part="1" 
AR Path="/5BAA648F/5BADEBCD" Ref="U9"  Part="1" 
F 0 "U9" H 6650 1847 60  0000 C CNN
F 1 "H11AA1" H 6650 1741 60  0000 C CNN
F 2 "Package_DIP:DIP-6_W7.62mm" H 6850 1700 60  0001 L CNN
F 3 "http://www.onsemi.com/pub/Collateral/H11AA4M-D.pdf" H 6850 1800 60  0001 L CNN
F 4 "H11AA1M-ND" H 6850 1900 60  0001 L CNN "Digi-Key_PN"
F 5 "H11AA1" H 6850 2000 60  0001 L CNN "MPN"
F 6 "Isolators" H 6850 2100 60  0001 L CNN "Category"
F 7 "Optoisolators - Transistor, Photovoltaic Output" H 6850 2200 60  0001 L CNN "Family"
F 8 "http://www.onsemi.com/pub/Collateral/H11AA4M-D.pdf" H 6850 2300 60  0001 L CNN "DK_Datasheet_Link"
F 9 "https://www.digikey.com/product-detail/en/on-semiconductor/H11AA1M/H11AA1M-ND/1053602" H 6850 2400 60  0001 L CNN "DK_Detail_Page"
F 10 "OPTOISO 4.17KV TRANS W/BASE 6DIP" H 6850 2500 60  0001 L CNN "Description"
F 11 "ON Semiconductor" H 6850 2600 60  0001 L CNN "Manufacturer"
F 12 "Active" H 6850 2700 60  0001 L CNN "Status"
	1    6650 1500
	-1   0    0    -1  
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
$Comp
L power:GND #PWR?
U 1 1 5BADEC11
P 6200 1700
AR Path="/5BA4B80D/5BADEC11" Ref="#PWR?"  Part="1" 
AR Path="/5BAA648F/5BADEC11" Ref="#PWR040"  Part="1" 
F 0 "#PWR040" H 6200 1450 50  0001 C CNN
F 1 "GND" H 6205 1527 50  0000 C CNN
F 2 "" H 6200 1700 50  0001 C CNN
F 3 "" H 6200 1700 50  0001 C CNN
	1    6200 1700
	1    0    0    -1  
$EndComp
Wire Wire Line
	6200 1700 6200 1600
Wire Wire Line
	6200 1600 6350 1600
Text HLabel 6100 1500 0    50   Output ~ 0
L2_OFF_HOOK_N
Wire Wire Line
	6100 1500 6250 1500
Wire Wire Line
	9450 2000 9850 2000
NoConn ~ 6350 1400
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
	6950 1600 7050 1600
Wire Wire Line
	7050 1600 7050 2000
Wire Wire Line
	7050 2000 6150 2000
Wire Wire Line
	6950 1400 7150 1400
Wire Wire Line
	7150 1400 7150 2000
Wire Wire Line
	7150 2000 7300 2000
$Comp
L Device:R_US R10
U 1 1 5BADEC32
P 6500 900
F 0 "R10" V 6295 900 50  0000 C CNN
F 1 "220" V 6386 900 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 6540 890 50  0001 C CNN
F 3 "~" H 6500 900 50  0001 C CNN
	1    6500 900 
	0    1    1    0   
$EndComp
$Comp
L Device:LED D12
U 1 1 5BADEC39
P 6250 1150
F 0 "D12" V 6288 1033 50  0000 R CNN
F 1 "LED" V 6197 1033 50  0000 R CNN
F 2 "LED_THT:LED_D5.0mm" H 6250 1150 50  0001 C CNN
F 3 "~" H 6250 1150 50  0001 C CNN
	1    6250 1150
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6250 1500 6250 1300
Connection ~ 6250 1500
Wire Wire Line
	6250 1500 6350 1500
Wire Wire Line
	6250 1000 6250 900 
Wire Wire Line
	6250 900  6350 900 
$Comp
L power:+5V #PWR042
U 1 1 5BADEC45
P 6700 850
F 0 "#PWR042" H 6700 700 50  0001 C CNN
F 1 "+5V" H 6715 1023 50  0000 C CNN
F 2 "" H 6700 850 50  0001 C CNN
F 3 "" H 6700 850 50  0001 C CNN
	1    6700 850 
	1    0    0    -1  
$EndComp
Wire Wire Line
	6650 900  6700 900 
Wire Wire Line
	6700 900  6700 850 
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
$Comp
L Isolator:H11AA1 U?
U 1 1 5BAE9B74
P 1900 4500
AR Path="/5BAE9B74" Ref="U?"  Part="1" 
AR Path="/5BA4B80D/5BAE9B74" Ref="U?"  Part="1" 
AR Path="/5BAA648F/5BAE9B74" Ref="U8"  Part="1" 
F 0 "U8" H 1900 4847 60  0000 C CNN
F 1 "H11AA1" H 1900 4741 60  0000 C CNN
F 2 "Package_DIP:DIP-6_W7.62mm" H 2100 4700 60  0001 L CNN
F 3 "http://www.onsemi.com/pub/Collateral/H11AA4M-D.pdf" H 2100 4800 60  0001 L CNN
F 4 "H11AA1M-ND" H 2100 4900 60  0001 L CNN "Digi-Key_PN"
F 5 "H11AA1" H 2100 5000 60  0001 L CNN "MPN"
F 6 "Isolators" H 2100 5100 60  0001 L CNN "Category"
F 7 "Optoisolators - Transistor, Photovoltaic Output" H 2100 5200 60  0001 L CNN "Family"
F 8 "http://www.onsemi.com/pub/Collateral/H11AA4M-D.pdf" H 2100 5300 60  0001 L CNN "DK_Datasheet_Link"
F 9 "https://www.digikey.com/product-detail/en/on-semiconductor/H11AA1M/H11AA1M-ND/1053602" H 2100 5400 60  0001 L CNN "DK_Detail_Page"
F 10 "OPTOISO 4.17KV TRANS W/BASE 6DIP" H 2100 5500 60  0001 L CNN "Description"
F 11 "ON Semiconductor" H 2100 5600 60  0001 L CNN "Manufacturer"
F 12 "Active" H 2100 5700 60  0001 L CNN "Status"
	1    1900 4500
	-1   0    0    -1  
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
$Comp
L power:GND #PWR?
U 1 1 5BAE9BB4
P 1450 4700
AR Path="/5BA4B80D/5BAE9BB4" Ref="#PWR?"  Part="1" 
AR Path="/5BAA648F/5BAE9BB4" Ref="#PWR033"  Part="1" 
F 0 "#PWR033" H 1450 4450 50  0001 C CNN
F 1 "GND" H 1455 4527 50  0000 C CNN
F 2 "" H 1450 4700 50  0001 C CNN
F 3 "" H 1450 4700 50  0001 C CNN
	1    1450 4700
	1    0    0    -1  
$EndComp
Wire Wire Line
	1450 4700 1450 4600
Wire Wire Line
	1450 4600 1600 4600
Text HLabel 1350 4500 0    50   Output ~ 0
L3_OFF_HOOK_N
Wire Wire Line
	1350 4500 1500 4500
Wire Wire Line
	4700 5000 5000 5000
NoConn ~ 1600 4400
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
	2200 4600 2300 4600
Wire Wire Line
	2300 4600 2300 5000
Wire Wire Line
	2300 5000 1400 5000
Wire Wire Line
	2200 4400 2400 4400
Wire Wire Line
	2400 4400 2400 5000
Wire Wire Line
	2400 5000 2550 5000
$Comp
L Device:R_US R7
U 1 1 5BAE9BD4
P 1750 3900
F 0 "R7" V 1545 3900 50  0000 C CNN
F 1 "220" V 1636 3900 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 1790 3890 50  0001 C CNN
F 3 "~" H 1750 3900 50  0001 C CNN
	1    1750 3900
	0    1    1    0   
$EndComp
$Comp
L Device:LED D7
U 1 1 5BAE9BDA
P 1500 4150
F 0 "D7" V 1538 4033 50  0000 R CNN
F 1 "LED" V 1447 4033 50  0000 R CNN
F 2 "LED_THT:LED_D5.0mm" H 1500 4150 50  0001 C CNN
F 3 "~" H 1500 4150 50  0001 C CNN
	1    1500 4150
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1500 4500 1500 4300
Connection ~ 1500 4500
Wire Wire Line
	1500 4500 1600 4500
Wire Wire Line
	1500 4000 1500 3900
Wire Wire Line
	1500 3900 1600 3900
$Comp
L power:+5V #PWR035
U 1 1 5BAE9BE5
P 1950 3850
F 0 "#PWR035" H 1950 3700 50  0001 C CNN
F 1 "+5V" H 1965 4023 50  0000 C CNN
F 2 "" H 1950 3850 50  0001 C CNN
F 3 "" H 1950 3850 50  0001 C CNN
	1    1950 3850
	1    0    0    -1  
$EndComp
Wire Wire Line
	1900 3900 1950 3900
Wire Wire Line
	1950 3900 1950 3850
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
$Comp
L Isolator:H11AA1 U?
U 1 1 5BAE9C15
P 6650 4500
AR Path="/5BAE9C15" Ref="U?"  Part="1" 
AR Path="/5BA4B80D/5BAE9C15" Ref="U?"  Part="1" 
AR Path="/5BAA648F/5BAE9C15" Ref="U10"  Part="1" 
F 0 "U10" H 6650 4847 60  0000 C CNN
F 1 "H11AA1" H 6650 4741 60  0000 C CNN
F 2 "Package_DIP:DIP-6_W7.62mm" H 6850 4700 60  0001 L CNN
F 3 "http://www.onsemi.com/pub/Collateral/H11AA4M-D.pdf" H 6850 4800 60  0001 L CNN
F 4 "H11AA1M-ND" H 6850 4900 60  0001 L CNN "Digi-Key_PN"
F 5 "H11AA1" H 6850 5000 60  0001 L CNN "MPN"
F 6 "Isolators" H 6850 5100 60  0001 L CNN "Category"
F 7 "Optoisolators - Transistor, Photovoltaic Output" H 6850 5200 60  0001 L CNN "Family"
F 8 "http://www.onsemi.com/pub/Collateral/H11AA4M-D.pdf" H 6850 5300 60  0001 L CNN "DK_Datasheet_Link"
F 9 "https://www.digikey.com/product-detail/en/on-semiconductor/H11AA1M/H11AA1M-ND/1053602" H 6850 5400 60  0001 L CNN "DK_Detail_Page"
F 10 "OPTOISO 4.17KV TRANS W/BASE 6DIP" H 6850 5500 60  0001 L CNN "Description"
F 11 "ON Semiconductor" H 6850 5600 60  0001 L CNN "Manufacturer"
F 12 "Active" H 6850 5700 60  0001 L CNN "Status"
	1    6650 4500
	-1   0    0    -1  
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
$Comp
L power:GND #PWR?
U 1 1 5BAE9C55
P 6200 4700
AR Path="/5BA4B80D/5BAE9C55" Ref="#PWR?"  Part="1" 
AR Path="/5BAA648F/5BAE9C55" Ref="#PWR041"  Part="1" 
F 0 "#PWR041" H 6200 4450 50  0001 C CNN
F 1 "GND" H 6205 4527 50  0000 C CNN
F 2 "" H 6200 4700 50  0001 C CNN
F 3 "" H 6200 4700 50  0001 C CNN
	1    6200 4700
	1    0    0    -1  
$EndComp
Wire Wire Line
	6200 4700 6200 4600
Wire Wire Line
	6200 4600 6350 4600
Text HLabel 6100 4500 0    50   Output ~ 0
L4_OFF_HOOK_N
Wire Wire Line
	6100 4500 6250 4500
Wire Wire Line
	9450 5000 9850 5000
NoConn ~ 6350 4400
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
	6950 4600 7050 4600
Wire Wire Line
	7050 4600 7050 5000
Wire Wire Line
	7050 5000 6150 5000
Wire Wire Line
	6950 4400 7150 4400
Wire Wire Line
	7150 4400 7150 5000
Wire Wire Line
	7150 5000 7300 5000
$Comp
L Device:R_US R11
U 1 1 5BAE9C74
P 6500 3900
F 0 "R11" V 6400 3900 50  0000 C CNN
F 1 "220" V 6600 3900 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 6540 3890 50  0001 C CNN
F 3 "~" H 6500 3900 50  0001 C CNN
	1    6500 3900
	0    1    1    0   
$EndComp
$Comp
L Device:LED D13
U 1 1 5BAE9C7A
P 6250 4150
F 0 "D13" V 6288 4033 50  0000 R CNN
F 1 "LED" V 6197 4033 50  0000 R CNN
F 2 "LED_THT:LED_D5.0mm" H 6250 4150 50  0001 C CNN
F 3 "~" H 6250 4150 50  0001 C CNN
	1    6250 4150
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6250 4500 6250 4300
Connection ~ 6250 4500
Wire Wire Line
	6250 4500 6350 4500
Wire Wire Line
	6250 4000 6250 3900
Wire Wire Line
	6250 3900 6350 3900
$Comp
L power:+5V #PWR043
U 1 1 5BAE9C85
P 6700 3850
F 0 "#PWR043" H 6700 3700 50  0001 C CNN
F 1 "+5V" H 6715 4023 50  0000 C CNN
F 2 "" H 6700 3850 50  0001 C CNN
F 3 "" H 6700 3850 50  0001 C CNN
	1    6700 3850
	1    0    0    -1  
$EndComp
Wire Wire Line
	6650 3900 6700 3900
Wire Wire Line
	6700 3900 6700 3850
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
Text Notes 7050 7050 0    50   Italic 10
(c) 2020, Howard M. Harte - WZ2Q
Text Notes 10550 7650 0    50   ~ 0
1
Text Notes 7400 7500 0    50   ~ 0
1D Coin Controller - Coin Line Control
Text Notes 8150 7650 0    50   ~ 0
2020-06-06
$EndSCHEMATC
