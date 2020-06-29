EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 6
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 1150 1200 0    50   Input ~ 0
12VDC
Text HLabel 3650 1650 2    50   Output ~ 0
+25VDC_TEST
Text HLabel 3650 2650 2    50   Output ~ 0
-25VDC_TEST
Wire Wire Line
	2500 1650 2700 1650
Wire Wire Line
	2500 1850 2650 1850
Wire Wire Line
	1700 1850 1550 1850
Wire Wire Line
	1700 1650 1550 1650
$Comp
L 1d_coinctrl_r2-rescue:IA1224S-dk_DC-DC-Converters PS2
U 1 1 5E743295
P 2100 1750
F 0 "PS2" H 2100 2137 60  0000 C CNN
F 1 "IA1224S" H 2100 2031 60  0000 C CNN
F 2 "1dcoinctrl_r2:IA1224S" H 2300 1950 60  0001 L CNN
F 3 "https://www.cui.com/product/resource/digikeypdf/v78-500.pdf" H 2300 2050 60  0001 L CNN
F 4 "102-1709-ND" H 2300 2150 60  0001 L CNN "Digi-Key_PN"
F 5 "V7805-500" H 2300 2250 60  0001 L CNN "MPN"
F 6 "Power Supplies - Board Mount" H 2300 2350 60  0001 L CNN "Category"
F 7 "DC DC Converters" H 2300 2450 60  0001 L CNN "Family"
F 8 "https://www.cui.com/product/resource/digikeypdf/v78-500.pdf" H 2300 2550 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/cui-inc/V7805-500/102-1709-ND/1828602" H 2300 2650 60  0001 L CNN "DK_Detail_Page"
F 10 "DC DC CONVERTER 5V 2.5W" H 2300 2750 60  0001 L CNN "Description"
F 11 "CUI Inc." H 2300 2850 60  0001 L CNN "Manufacturer"
F 12 "Active" H 2300 2950 60  0001 L CNN "Status"
	1    2100 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	1550 1850 1550 2150
Wire Wire Line
	1550 2150 2100 2150
Wire Wire Line
	2100 2150 2100 2050
$Comp
L power:GND #PWR09
U 1 1 5E750141
P 2100 2300
F 0 "#PWR09" H 2100 2050 50  0001 C CNN
F 1 "GND" H 2105 2127 50  0000 C CNN
F 2 "" H 2100 2300 50  0001 C CNN
F 3 "" H 2100 2300 50  0001 C CNN
	1    2100 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	2100 2300 2100 2150
Connection ~ 2100 2150
Wire Wire Line
	1550 1650 1550 1200
Wire Wire Line
	1550 1200 1350 1200
Connection ~ 1550 1200
Text HLabel 10250 1200 2    50   Output ~ 0
+5VDC
$Comp
L 1d_coinctrl_r2-rescue:+12V_RELAY-power #PWR?
U 1 1 5E7BBF9E
P 9700 3850
AR Path="/5BA4B80D/5E7BBF9E" Ref="#PWR?"  Part="1" 
AR Path="/5BA47743/5E7BBF9E" Ref="#PWR011"  Part="1" 
F 0 "#PWR011" H 9700 3700 50  0001 C CNN
F 1 "+12V_RELAY" H 9715 4023 50  0000 C CNN
F 2 "" H 9700 3850 50  0001 C CNN
F 3 "" H 9700 3850 50  0001 C CNN
	1    9700 3850
	1    0    0    -1  
$EndComp
Wire Wire Line
	9550 3900 9700 3900
$Comp
L Diode:1N4148 D?
U 1 1 5E7BBFA6
P 9300 4450
AR Path="/5E7BBFA6" Ref="D?"  Part="1" 
AR Path="/5BA4B80D/5E7BBFA6" Ref="D?"  Part="1" 
AR Path="/5BA47743/5E7BBFA6" Ref="D1"  Part="1" 
F 0 "D1" V 9254 4529 50  0000 L CNN
F 1 "1N4148" V 9345 4529 50  0000 L CNN
F 2 "Diode_THT:D_DO-35_SOD27_P7.62mm_Horizontal" H 9300 4275 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/1N4148_1N4448.pdf" H 9300 4450 50  0001 C CNN
	1    9300 4450
	-1   0    0    -1  
$EndComp
Wire Wire Line
	9450 4450 9700 4450
Wire Wire Line
	9700 4450 9700 3900
Wire Wire Line
	9150 4450 8800 4450
Wire Wire Line
	8800 4450 8800 3900
Wire Wire Line
	8800 3900 8950 3900
Text HLabel 8100 4750 0    50   Input ~ 0
REFUND
$Comp
L 1d_coinctrl_r2-rescue:G5V-2-DC12-dk_Signal-Relays-Up-to-2-Amps RLY?
U 1 1 5E7BBF90
P 9250 3500
AR Path="/5E7BBF90" Ref="RLY?"  Part="1" 
AR Path="/5BA4B80D/5E7BBF90" Ref="RLY?"  Part="1" 
AR Path="/5BA47743/5E7BBF90" Ref="K11"  Part="1" 
F 0 "K11" H 9738 3546 50  0000 L CNN
F 1 "G5V-2-DC12" H 9738 3455 50  0000 L CNN
F 2 "digikey-footprints:Relay_THT_G5V-2" H 9450 3700 50  0001 L CNN
F 3 "http://omronfs.omron.com/en_US/ecb/products/pdf/en-g5v_2.pdf" H 9450 3800 60  0001 L CNN
F 4 "Z768-ND" H 9450 3900 60  0001 L CNN "Digi-Key_PN"
F 5 "G5V-2-DC12" H 9450 4000 60  0001 L CNN "MPN"
F 6 "Relays" H 9450 4100 60  0001 L CNN "Category"
F 7 "Signal Relays, Up to 2 Amps" H 9450 4200 60  0001 L CNN "Family"
F 8 "http://omronfs.omron.com/en_US/ecb/products/pdf/en-g5v_2.pdf" H 9450 4300 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/omron-electronics-inc-emc-div/G5V-2-DC12/Z768-ND/87821" H 9450 4400 60  0001 L CNN "DK_Detail_Page"
F 10 "RELAY GEN PURPOSE DPDT 2A 12V" H 9450 4500 60  0001 L CNN "Description"
F 11 "Omron Electronics Inc-EMC Div" H 9450 4600 60  0001 L CNN "Manufacturer"
F 12 "Active" H 9450 4700 60  0001 L CNN "Status"
	1    9250 3500
	0    1    -1   0   
$EndComp
Text Label 7800 3200 0    50   ~ 0
+130VDC
Text Label 7800 3600 0    50   ~ 0
-130VDC
Wire Wire Line
	9550 3500 9650 3500
Wire Wire Line
	9650 3500 9650 3300
Wire Wire Line
	9650 3300 9550 3300
Wire Wire Line
	9550 3700 9800 3700
Wire Wire Line
	9800 3700 9800 3100
Wire Wire Line
	9800 3100 9550 3100
$Comp
L power:GND #PWR013
U 1 1 5E7EB687
P 9650 3550
F 0 "#PWR013" H 9650 3300 50  0001 C CNN
F 1 "GND" H 9655 3377 50  0000 C CNN
F 2 "" H 9650 3550 50  0001 C CNN
F 3 "" H 9650 3550 50  0001 C CNN
	1    9650 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	9650 3550 9650 3500
Connection ~ 9650 3500
$Comp
L 1d_coinctrl_r2-rescue:R12-100B-R12-100B PS1
U 1 1 5E7FEA4F
P 5750 3400
F 0 "PS1" H 5750 3867 50  0000 C CNN
F 1 "R12-100B" H 5750 3776 50  0000 C CNN
F 2 "kicad-snapeda:CONV_R12-100B" H 5750 3400 50  0001 L BNN
F 3 "7" H 5750 3400 50  0001 L BNN
F 4 "Recom" H 5750 3400 50  0001 L BNN "Field4"
F 5 "9.4mm" H 5750 3400 50  0001 L BNN "Field5"
F 6 "Manufacturer Recommendations" H 5750 3400 50  0001 L BNN "Field6"
	1    5750 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	6350 3200 6600 3200
Wire Wire Line
	6350 3600 6600 3600
Wire Wire Line
	5150 3600 5050 3600
Wire Wire Line
	5050 3600 5050 3650
$Comp
L power:GND #PWR010
U 1 1 5E80499D
P 5050 3700
F 0 "#PWR010" H 5050 3450 50  0001 C CNN
F 1 "GND" H 5055 3527 50  0000 C CNN
F 2 "" H 5050 3700 50  0001 C CNN
F 3 "" H 5050 3700 50  0001 C CNN
	1    5050 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	4900 3200 5150 3200
$Comp
L Device:CP1 C2
U 1 1 5E807C55
P 7400 3400
F 0 "C2" H 7515 3446 50  0000 L CNN
F 1 "4.7uF 250V" H 7515 3355 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D8.0mm_P3.50mm" H 7400 3400 50  0001 C CNN
F 3 "~" H 7400 3400 50  0001 C CNN
	1    7400 3400
	1    0    0    -1  
$EndComp
$Comp
L Device:R_US R3
U 1 1 5E80A3F3
P 10000 3100
F 0 "R3" V 9900 3100 50  0000 C CNN
F 1 "1.5K 5W" V 10100 3100 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_Power_L25.0mm_W9.0mm_P30.48mm" V 10040 3090 50  0001 C CNN
F 3 "~" H 10000 3100 50  0001 C CNN
	1    10000 3100
	0    1    1    0   
$EndComp
Wire Wire Line
	4900 1200 4900 3200
Wire Wire Line
	7400 3550 7400 3600
Wire Wire Line
	7400 3600 8950 3600
Text HLabel 10250 3100 2    50   Output ~ 0
V_COIN_RELAY
$Comp
L Device:CP1 C1
U 1 1 5EBF3406
P 1350 1700
F 0 "C1" H 1465 1746 50  0000 L CNN
F 1 "10uF 25V" H 1465 1655 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W4.4mm_P5.00mm" H 1350 1700 50  0001 C CNN
F 3 "~" H 1350 1700 50  0001 C CNN
	1    1350 1700
	1    0    0    -1  
$EndComp
Wire Wire Line
	1350 1550 1350 1200
Connection ~ 1350 1200
Wire Wire Line
	1350 1200 1150 1200
Wire Wire Line
	1350 1850 1350 2150
Wire Wire Line
	1350 2150 1550 2150
Connection ~ 1550 2150
$Comp
L Device:R_POT_US R13
U 1 1 5EC6CACD
P 6750 4300
F 0 "R13" V 6637 4300 50  0000 C CNN
F 1 "5K" V 6546 4300 50  0000 C CNN
F 2 "Potentiometer_THT:Potentiometer_Bourns_3266W_Vertical" H 6750 4300 50  0001 C CNN
F 3 "~" H 6750 4300 50  0001 C CNN
	1    6750 4300
	0    1    -1   0   
$EndComp
Wire Wire Line
	6750 4150 6750 3450
Wire Wire Line
	6750 3400 6350 3400
Wire Wire Line
	6900 4300 7100 4300
Wire Wire Line
	6600 4300 4900 4300
Wire Wire Line
	4900 4300 4900 3450
Wire Wire Line
	4900 3400 5150 3400
Connection ~ 4900 1200
Wire Wire Line
	7100 1750 7750 1750
Wire Wire Line
	7100 1650 7100 1750
Wire Wire Line
	7100 1200 7350 1200
Connection ~ 7100 1200
Wire Wire Line
	7100 1350 7100 1200
Wire Wire Line
	7750 1750 7750 1600
Connection ~ 7750 1750
Wire Wire Line
	8300 1750 7750 1750
Wire Wire Line
	8300 1650 8300 1750
Connection ~ 8300 1200
Wire Wire Line
	8300 1350 8300 1200
$Comp
L Device:CP1 C4
U 1 1 5E7B069C
P 8300 1500
F 0 "C4" H 8415 1546 50  0000 L CNN
F 1 "22uF 16V" H 8415 1455 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D6.3mm_P2.50mm" H 8300 1500 50  0001 C CNN
F 3 "~" H 8300 1500 50  0001 C CNN
	1    8300 1500
	1    0    0    -1  
$EndComp
$Comp
L Device:CP1 C3
U 1 1 5E7AF9F4
P 7100 1500
F 0 "C3" H 7215 1546 50  0000 L CNN
F 1 "10uF 25V" H 7215 1455 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D6.0mm_W4.4mm_P5.00mm" H 7100 1500 50  0001 C CNN
F 3 "~" H 7100 1500 50  0001 C CNN
	1    7100 1500
	1    0    0    -1  
$EndComp
Wire Wire Line
	8150 1200 8300 1200
Wire Wire Line
	7750 1850 7750 1750
$Comp
L power:GND #PWR012
U 1 1 5E7AB391
P 7750 1850
F 0 "#PWR012" H 7750 1600 50  0001 C CNN
F 1 "GND" H 7755 1677 50  0000 C CNN
F 2 "" H 7750 1850 50  0001 C CNN
F 3 "" H 7750 1850 50  0001 C CNN
	1    7750 1850
	1    0    0    -1  
$EndComp
$Comp
L 1d_coinctrl_r2-rescue:V7805-1000-dk_DC-DC-Converters U2
U 1 1 5E7AA3A7
P 7750 1300
F 0 "U2" H 7750 1687 60  0000 C CNN
F 1 "V7805-1000" H 7750 1581 60  0000 C CNN
F 2 "digikey-footprints:3-SIP_Module_V7805-1000" H 7950 1500 60  0001 L CNN
F 3 "https://www.cui.com/product/resource/digikeypdf/v78xx-1000.pdf" H 7950 1600 60  0001 L CNN
F 4 "102-1715-ND" H 7950 1700 60  0001 L CNN "Digi-Key_PN"
F 5 "V7805-1000" H 7950 1800 60  0001 L CNN "MPN"
F 6 "Power Supplies - Board Mount" H 7950 1900 60  0001 L CNN "Category"
F 7 "DC DC Converters" H 7950 2000 60  0001 L CNN "Family"
F 8 "https://www.cui.com/product/resource/digikeypdf/v78xx-1000.pdf" H 7950 2100 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/cui-inc/V7805-1000/102-1715-ND/1828608" H 7950 2200 60  0001 L CNN "DK_Detail_Page"
F 10 "DC DC CONVERTER 5V 5W" H 7950 2300 60  0001 L CNN "Description"
F 11 "CUI Inc." H 7950 2400 60  0001 L CNN "Manufacturer"
F 12 "Active" H 7950 2500 60  0001 L CNN "Status"
	1    7750 1300
	1    0    0    -1  
$EndComp
Wire Wire Line
	4900 1200 7100 1200
Wire Wire Line
	8300 1200 8900 1200
Wire Wire Line
	1550 1200 4900 1200
$Comp
L Device:C C?
U 1 1 5EC94EF8
P 8900 1500
AR Path="/5BA49F1B/5EC94EF8" Ref="C?"  Part="1" 
AR Path="/5BA47743/5EC94EF8" Ref="C9"  Part="1" 
F 0 "C9" H 9015 1546 50  0000 L CNN
F 1 "0.1uF" H 9015 1455 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D3.0mm_W2.0mm_P2.50mm" H 8938 1350 50  0001 C CNN
F 3 "~" H 8900 1500 50  0001 C CNN
	1    8900 1500
	1    0    0    -1  
$EndComp
Wire Wire Line
	8300 1750 8900 1750
Wire Wire Line
	8900 1750 8900 1650
Connection ~ 8300 1750
Wire Wire Line
	8900 1350 8900 1200
Connection ~ 8900 1200
Wire Wire Line
	8900 1200 10250 1200
Wire Wire Line
	8100 4750 8800 4750
Wire Wire Line
	8800 4750 8800 4450
Connection ~ 8800 4450
Wire Wire Line
	9700 3900 9700 3850
Connection ~ 9700 3900
$Comp
L Device:R_US R?
U 1 1 5EFAFABF
P 2850 1650
AR Path="/5BAA648F/5EFAFABF" Ref="R?"  Part="1" 
AR Path="/5EFAFABF" Ref="R?"  Part="1" 
AR Path="/5BA47743/5EFAFABF" Ref="R1"  Part="1" 
F 0 "R1" V 2645 1650 50  0000 C CNN
F 1 "1.5K 1W" V 2736 1650 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 2890 1640 50  0001 C CNN
F 3 "~" H 2850 1650 50  0001 C CNN
	1    2850 1650
	0    1    1    0   
$EndComp
$Comp
L Device:R_US R?
U 1 1 5EFB0CA9
P 2850 2650
AR Path="/5BAA648F/5EFB0CA9" Ref="R?"  Part="1" 
AR Path="/5EFB0CA9" Ref="R?"  Part="1" 
AR Path="/5BA47743/5EFB0CA9" Ref="R2"  Part="1" 
F 0 "R2" V 2950 2650 50  0000 C CNN
F 1 "1.5K 1W" V 3050 2650 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 2890 2640 50  0001 C CNN
F 3 "~" H 2850 2650 50  0001 C CNN
	1    2850 2650
	0    1    1    0   
$EndComp
Wire Wire Line
	3000 2650 3150 2650
Wire Wire Line
	3000 1650 3150 1650
Wire Wire Line
	2700 2650 2650 2650
Wire Wire Line
	2100 2150 3150 2150
$Comp
L Device:CP1 C12
U 1 1 5EFBCD73
P 3150 1900
F 0 "C12" H 3265 1946 50  0000 L CNN
F 1 "10uF 50V" H 3265 1855 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D6.3mm_P2.50mm" H 3150 1900 50  0001 C CNN
F 3 "~" H 3150 1900 50  0001 C CNN
	1    3150 1900
	1    0    0    -1  
$EndComp
$Comp
L Device:CP1 C13
U 1 1 5EFBFC25
P 3150 2400
F 0 "C13" H 3265 2446 50  0000 L CNN
F 1 "10uF 50V" H 3265 2355 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D6.3mm_P2.50mm" H 3150 2400 50  0001 C CNN
F 3 "~" H 3150 2400 50  0001 C CNN
	1    3150 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	3150 2650 3150 2550
Connection ~ 3150 2650
Wire Wire Line
	3150 2250 3150 2150
Wire Wire Line
	3150 2150 3150 2050
Connection ~ 3150 2150
Wire Wire Line
	2650 1850 2650 2650
Wire Wire Line
	3150 1750 3150 1650
Connection ~ 3150 1650
Wire Wire Line
	4900 3200 4900 3250
Wire Wire Line
	4900 3250 5150 3250
Connection ~ 4900 3200
Wire Wire Line
	4900 3450 5150 3450
Connection ~ 4900 3450
Wire Wire Line
	4900 3450 4900 3400
Wire Wire Line
	5050 3650 5150 3650
Connection ~ 5050 3650
Wire Wire Line
	5050 3650 5050 3700
Wire Wire Line
	6350 3250 6600 3250
Wire Wire Line
	6600 3250 6600 3200
Wire Wire Line
	6350 3450 6750 3450
Connection ~ 6750 3450
Wire Wire Line
	6750 3450 6750 3400
Wire Wire Line
	6350 3650 6600 3650
Wire Wire Line
	6600 3650 6600 3600
Wire Wire Line
	7400 3250 7400 3200
Wire Wire Line
	7400 3200 8950 3200
Connection ~ 6600 3200
Connection ~ 7400 3200
Connection ~ 7400 3600
Connection ~ 6600 3600
Wire Wire Line
	9800 3100 9850 3100
Connection ~ 9800 3100
Wire Wire Line
	10150 3100 10250 3100
Wire Wire Line
	6600 3200 7400 3200
Wire Wire Line
	6600 3600 7100 3600
Wire Wire Line
	7100 4300 7100 3600
Connection ~ 7100 3600
Wire Wire Line
	7100 3600 7400 3600
Text Label 3150 2650 0    50   ~ 0
-25VDC
Text Label 3150 1650 0    50   ~ 0
+25VDC
Wire Wire Line
	3150 1650 3650 1650
Wire Wire Line
	3150 2650 3650 2650
$Comp
L power:GND #PWR0107
U 1 1 5F22B17F
P 2750 4050
F 0 "#PWR0107" H 2750 3800 50  0001 C CNN
F 1 "GND" H 2755 3877 50  0000 C CNN
F 2 "" H 2750 4050 50  0001 C CNN
F 3 "" H 2750 4050 50  0001 C CNN
	1    2750 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	2750 4050 2750 3900
$Comp
L Mechanical:MountingHole_Pad H5
U 1 1 5F230CC5
P 2750 3800
F 0 "H5" H 2850 3849 50  0000 L CNN
F 1 "MountingHole_Pad" H 2850 3758 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.7mm_Pad" H 2750 3800 50  0001 C CNN
F 3 "~" H 2750 3800 50  0001 C CNN
	1    2750 3800
	1    0    0    -1  
$EndComp
Text Notes 7000 6900 0    197  Italic 39
1D Coin Controller
Text Notes 10550 7650 0    50   ~ 0
2
Text Notes 7400 7500 0    50   ~ 0
1D Coin Controller - Power Supply
Text Notes 8150 7650 0    50   ~ 0
2020-06-27
Text Notes 2450 3600 0    50   ~ 0
Earth Ground Pad
Text Notes 7050 7100 0    50   Italic 10
(c) 2020, Howard M. Harte - WZ2Q\nhttps://github.com/hharte/1dcoinctrl
$EndSCHEMATC
