EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 5 6
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
U 1 1 5BA4B8E1
P 3950 2850
AR Path="/5BA4B8E1" Ref="RLY?"  Part="1" 
AR Path="/5BA4B80D/5BA4B8E1" Ref="K1"  Part="1" 
F 0 "K1" H 4438 2896 50  0000 L CNN
F 1 "G5V-2-DC12" H 4438 2805 50  0000 L CNN
F 2 "digikey-footprints:Relay_THT_G5V-2" H 4150 3050 50  0001 L CNN
F 3 "http://omronfs.omron.com/en_US/ecb/products/pdf/en-g5v_2.pdf" H 4150 3150 60  0001 L CNN
F 4 "Z768-ND" H 4150 3250 60  0001 L CNN "Digi-Key_PN"
F 5 "G5V-2-DC12" H 4150 3350 60  0001 L CNN "MPN"
F 6 "Relays" H 4150 3450 60  0001 L CNN "Category"
F 7 "Signal Relays, Up to 2 Amps" H 4150 3550 60  0001 L CNN "Family"
F 8 "http://omronfs.omron.com/en_US/ecb/products/pdf/en-g5v_2.pdf" H 4150 3650 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/omron-electronics-inc-emc-div/G5V-2-DC12/Z768-ND/87821" H 4150 3750 60  0001 L CNN "DK_Detail_Page"
F 10 "RELAY GEN PURPOSE DPDT 2A 12V" H 4150 3850 60  0001 L CNN "Description"
F 11 "Omron Electronics Inc-EMC Div" H 4150 3950 60  0001 L CNN "Manufacturer"
F 12 "Active" H 4150 4050 60  0001 L CNN "Status"
	1    3950 2850
	0    -1   -1   0   
$EndComp
$Comp
L Isolator:H11AA1 U?
U 1 1 5BA4B8F1
P 3950 1500
AR Path="/5BA4B8F1" Ref="U?"  Part="1" 
AR Path="/5BA4B80D/5BA4B8F1" Ref="U6"  Part="1" 
F 0 "U6" H 3950 1847 60  0000 C CNN
F 1 "H11AA1" H 3950 1741 60  0000 C CNN
F 2 "Package_DIP:DIP-6_W7.62mm" H 4150 1700 60  0001 L CNN
F 3 "http://www.onsemi.com/pub/Collateral/H11AA4M-D.pdf" H 4150 1800 60  0001 L CNN
F 4 "H11AA1M-ND" H 4150 1900 60  0001 L CNN "Digi-Key_PN"
F 5 "H11AA1" H 4150 2000 60  0001 L CNN "MPN"
F 6 "Isolators" H 4150 2100 60  0001 L CNN "Category"
F 7 "Optoisolators - Transistor, Photovoltaic Output" H 4150 2200 60  0001 L CNN "Family"
F 8 "http://www.onsemi.com/pub/Collateral/H11AA4M-D.pdf" H 4150 2300 60  0001 L CNN "DK_Datasheet_Link"
F 9 "https://www.digikey.com/product-detail/en/on-semiconductor/H11AA1M/H11AA1M-ND/1053602" H 4150 2400 60  0001 L CNN "DK_Detail_Page"
F 10 "OPTOISO 4.17KV TRANS W/BASE 6DIP" H 4150 2500 60  0001 L CNN "Description"
F 11 "ON Semiconductor" H 4150 2600 60  0001 L CNN "Manufacturer"
F 12 "Active" H 4150 2700 60  0001 L CNN "Status"
	1    3950 1500
	-1   0    0    -1  
$EndComp
Wire Wire Line
	3650 2450 2500 2450
Text HLabel 2500 2450 0    50   Input ~ 0
+25VDC_TEST
Text HLabel 2500 2650 0    50   Input ~ 0
-25VDC_TEST
Text HLabel 2500 2850 0    50   Input ~ 0
+130VDC
Text HLabel 2500 3050 0    50   Input ~ 0
-130VDC
Wire Wire Line
	3650 2650 2500 2650
Wire Wire Line
	3650 2850 2500 2850
Wire Wire Line
	3650 3050 2500 3050
$Comp
L 1d_coinctrl_r2-rescue:+12V_RELAY-power #12V_RELAY0102
U 1 1 5BA4BB89
P 3500 3200
F 0 "#12V_RELAY0102" H 3500 3050 50  0001 C CNN
F 1 "+12V_RELAY" H 3150 3250 50  0000 C CNN
F 2 "" H 3500 3200 50  0001 C CNN
F 3 "" H 3500 3200 50  0001 C CNN
	1    3500 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	4250 3250 4400 3250
Wire Wire Line
	4400 3250 4400 3200
$Comp
L Diode:1N4148 D?
U 1 1 5BA4BC0F
P 4000 3800
AR Path="/5BA4BC0F" Ref="D?"  Part="1" 
AR Path="/5BA4B80D/5BA4BC0F" Ref="D4"  Part="1" 
F 0 "D4" V 3954 3879 50  0000 L CNN
F 1 "1N4148" V 4045 3879 50  0000 L CNN
F 2 "Diode_THT:D_DO-35_SOD27_P7.62mm_Horizontal" H 4000 3625 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/1N4148_1N4448.pdf" H 4000 3800 50  0001 C CNN
	1    4000 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	4150 3800 4400 3800
Connection ~ 4400 3250
Text HLabel 2500 4100 0    50   Input ~ 0
REFUND
Text HLabel 8300 2550 2    50   Output ~ 0
COIN_OP
$Comp
L 1d_coinctrl_r2-rescue:G5V-2-DC12-dk_Signal-Relays-Up-to-2-Amps RLY?
U 1 1 5BA4C342
P 7050 2850
AR Path="/5BA4C342" Ref="RLY?"  Part="1" 
AR Path="/5BA4B80D/5BA4C342" Ref="K2"  Part="1" 
F 0 "K2" H 7538 2896 50  0000 L CNN
F 1 "G5V-2-DC12" H 7538 2805 50  0000 L CNN
F 2 "digikey-footprints:Relay_THT_G5V-2" H 7250 3050 50  0001 L CNN
F 3 "http://omronfs.omron.com/en_US/ecb/products/pdf/en-g5v_2.pdf" H 7250 3150 60  0001 L CNN
F 4 "Z768-ND" H 7250 3250 60  0001 L CNN "Digi-Key_PN"
F 5 "G5V-2-DC12" H 7250 3350 60  0001 L CNN "MPN"
F 6 "Relays" H 7250 3450 60  0001 L CNN "Category"
F 7 "Signal Relays, Up to 2 Amps" H 7250 3550 60  0001 L CNN "Family"
F 8 "http://omronfs.omron.com/en_US/ecb/products/pdf/en-g5v_2.pdf" H 7250 3650 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/omron-electronics-inc-emc-div/G5V-2-DC12/Z768-ND/87821" H 7250 3750 60  0001 L CNN "DK_Detail_Page"
F 10 "RELAY GEN PURPOSE DPDT 2A 12V" H 7250 3850 60  0001 L CNN "Description"
F 11 "Omron Electronics Inc-EMC Div" H 7250 3950 60  0001 L CNN "Manufacturer"
F 12 "Active" H 7250 4050 60  0001 L CNN "Status"
	1    7050 2850
	0    -1   -1   0   
$EndComp
$Comp
L 1d_coinctrl_r2-rescue:+12V_RELAY-power #PWR031
U 1 1 5BA4C350
P 6600 3150
F 0 "#PWR031" H 6600 3000 50  0001 C CNN
F 1 "+12V_RELAY" H 6615 3323 50  0000 C CNN
F 2 "" H 6600 3150 50  0001 C CNN
F 3 "" H 6600 3150 50  0001 C CNN
	1    6600 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	7350 3250 7500 3250
$Comp
L Diode:1N4148 D?
U 1 1 5BA4C358
P 7100 3800
AR Path="/5BA4C358" Ref="D?"  Part="1" 
AR Path="/5BA4B80D/5BA4C358" Ref="D5"  Part="1" 
F 0 "D5" V 7054 3879 50  0000 L CNN
F 1 "1N4148" V 7145 3879 50  0000 L CNN
F 2 "Diode_THT:D_DO-35_SOD27_P7.62mm_Horizontal" H 7100 3625 50  0001 C CNN
F 3 "http://www.nxp.com/documents/data_sheet/1N4148_1N4448.pdf" H 7100 3800 50  0001 C CNN
	1    7100 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	7250 3800 7500 3800
Wire Wire Line
	7500 3800 7500 3250
Wire Wire Line
	6950 3800 6600 3800
Wire Wire Line
	6600 3800 6600 3250
Wire Wire Line
	6600 3250 6750 3250
Text HLabel 2500 4500 0    50   Input ~ 0
DISPOSITION
Wire Wire Line
	5250 2650 5250 2950
Wire Wire Line
	5250 2950 4900 2950
Wire Wire Line
	5250 2650 6750 2650
Wire Wire Line
	6750 2450 5250 2450
Wire Wire Line
	4250 1600 4400 1600
Wire Wire Line
	4400 1600 4400 2550
Wire Wire Line
	4400 2550 4250 2550
$Comp
L power:GND #PWR029
U 1 1 5BA4F5C9
P 3500 1700
F 0 "#PWR029" H 3500 1450 50  0001 C CNN
F 1 "GND" H 3505 1527 50  0000 C CNN
F 2 "" H 3500 1700 50  0001 C CNN
F 3 "" H 3500 1700 50  0001 C CNN
	1    3500 1700
	1    0    0    -1  
$EndComp
Wire Wire Line
	3500 1700 3500 1600
Wire Wire Line
	3500 1600 3650 1600
Text HLabel 2450 1500 0    50   Output ~ 0
TEST_STATUS_N
Wire Wire Line
	2450 1500 3050 1500
Wire Wire Line
	5250 2450 5250 1400
Wire Wire Line
	7350 2550 8300 2550
NoConn ~ 6750 2850
NoConn ~ 6750 3050
NoConn ~ 7350 2950
NoConn ~ 3650 1400
$Comp
L Device:R_US R?
U 1 1 5BAC4ED0
P 3300 900
AR Path="/5BAA648F/5BAC4ED0" Ref="R?"  Part="1" 
AR Path="/5BA4B80D/5BAC4ED0" Ref="R5"  Part="1" 
F 0 "R5" V 3095 900 50  0000 C CNN
F 1 "220" V 3186 900 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 3340 890 50  0001 C CNN
F 3 "~" H 3300 900 50  0001 C CNN
	1    3300 900 
	0    1    1    0   
$EndComp
$Comp
L Device:LED D?
U 1 1 5BAC4ED7
P 3050 1150
AR Path="/5BAA648F/5BAC4ED7" Ref="D?"  Part="1" 
AR Path="/5BA4B80D/5BAC4ED7" Ref="D3"  Part="1" 
F 0 "D3" V 3088 1033 50  0000 R CNN
F 1 "LED" V 2997 1033 50  0000 R CNN
F 2 "LED_THT:LED_D5.0mm" H 3050 1150 50  0001 C CNN
F 3 "~" H 3050 1150 50  0001 C CNN
	1    3050 1150
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3050 1500 3050 1300
Wire Wire Line
	3050 1000 3050 900 
Wire Wire Line
	3050 900  3150 900 
$Comp
L power:+5V #PWR?
U 1 1 5BAC4EE1
P 3500 850
AR Path="/5BAA648F/5BAC4EE1" Ref="#PWR?"  Part="1" 
AR Path="/5BA4B80D/5BAC4EE1" Ref="#PWR028"  Part="1" 
F 0 "#PWR028" H 3500 700 50  0001 C CNN
F 1 "+5V" H 3515 1023 50  0000 C CNN
F 2 "" H 3500 850 50  0001 C CNN
F 3 "" H 3500 850 50  0001 C CNN
	1    3500 850 
	1    0    0    -1  
$EndComp
Wire Wire Line
	3450 900  3500 900 
Wire Wire Line
	3500 900  3500 850 
Connection ~ 3050 1500
Wire Wire Line
	3050 1500 3650 1500
Wire Wire Line
	4900 2950 4900 4300
Wire Wire Line
	2500 4300 4900 4300
Connection ~ 4900 2950
Wire Wire Line
	4900 2950 4250 2950
Text HLabel 2500 4300 0    50   Input ~ 0
V_COIN_RELAY
Wire Wire Line
	6600 3250 6600 3150
Connection ~ 6600 3250
Wire Wire Line
	2500 4500 7500 4500
Wire Wire Line
	7500 4500 7500 3800
Connection ~ 7500 3800
Wire Wire Line
	4400 3250 4400 3800
Wire Wire Line
	2500 4100 4400 4100
Connection ~ 4400 3800
Wire Wire Line
	4400 3800 4400 4100
Wire Wire Line
	3650 3250 3500 3250
Wire Wire Line
	3500 3250 3500 3200
Wire Wire Line
	3500 3250 3500 3800
Wire Wire Line
	3500 3800 3850 3800
Connection ~ 3500 3250
$Comp
L Device:R_US R?
U 1 1 5E81A1A6
P 4800 1400
AR Path="/5BAA648F/5E81A1A6" Ref="R?"  Part="1" 
AR Path="/5E81A1A6" Ref="R?"  Part="1" 
AR Path="/5BA47743/5E81A1A6" Ref="R?"  Part="1" 
AR Path="/5BA4B80D/5E81A1A6" Ref="R16"  Part="1" 
F 0 "R16" V 4595 1400 50  0000 C CNN
F 1 "1.5K 1W" V 4686 1400 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 4840 1390 50  0001 C CNN
F 3 "~" H 4800 1400 50  0001 C CNN
	1    4800 1400
	0    1    1    0   
$EndComp
Wire Wire Line
	4950 1400 5250 1400
Wire Wire Line
	4250 1400 4650 1400
Text Notes 7050 6900 0    197  Italic 39
1D Coin Controller
Text Notes 7100 7050 0    50   Italic 10
(c) 2020, Howard M. Harte - WZ2Q
Text Notes 10600 7650 0    50   ~ 0
1
Text Notes 7450 7500 0    50   ~ 0
1D Coin Controller - Common Control
Text Notes 8200 7650 0    50   ~ 0
2020-06-06
$EndSCHEMATC
