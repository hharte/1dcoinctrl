EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 6
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Sheet
S 6650 4250 1050 900 
U 5BA47743
F0 "Power" 50
F1 "Power.sch" 50
F2 "12VDC" I L 6650 4350 50 
F3 "+25VDC_TEST" O R 7700 4350 50 
F4 "-25VDC_TEST" O R 7700 4500 50 
F5 "+5VDC" O R 7700 5050 50 
F6 "REFUND" I L 6650 4850 50 
F7 "V_COIN_RELAY" O R 7700 4650 50 
$EndSheet
$Sheet
S 1400 4200 2450 1900
U 5BA49F1B
F0 "GPIO" 50
F1 "GPIO.sch" 50
F2 "L1_HOLD_CO" O R 3850 4300 50 
F3 "L2_HOLD_CO" O R 3850 4650 50 
F4 "L3_HOLD_CO" O R 3850 5000 50 
F5 "L4_HOLD_CO" O R 3850 5350 50 
F6 "L1_COIN_CONTROL" O R 3850 4400 50 
F7 "L2_COIN_CONTROL" O R 3850 4750 50 
F8 "L3_COIN_CONTROL" O R 3850 5100 50 
F9 "L4_COIN_CONTROL" O R 3850 5450 50 
F10 "L1_OFF_HOOK" I R 3850 4500 50 
F11 "L2_OFF_HOOK" I R 3850 4850 50 
F12 "L3_OFF_HOOK" I R 3850 5200 50 
F13 "L4_OFF_HOOK" I R 3850 5550 50 
F14 "TEST_STATUS_N" I L 1400 5600 50 
F15 "REFUND" O R 3850 5850 50 
F16 "DISPOSITION" O R 3850 5950 50 
$EndSheet
$Sheet
S 8450 4250 2100 1750
U 5BA4B80D
F0 "Common Control" 50
F1 "ComCtrl.sch" 50
F2 "+25VDC_TEST" I L 8450 4350 50 
F3 "-25VDC_TEST" I L 8450 4500 50 
F4 "+130VDC" I L 8450 5450 50 
F5 "-130VDC" I L 8450 5600 50 
F6 "REFUND" I L 8450 5850 50 
F7 "COIN_OP" O R 10550 4500 50 
F8 "DISPOSITION" I L 8450 5950 50 
F9 "TEST_STATUS_N" O R 10550 5750 50 
F10 "V_COIN_RELAY" I L 8450 4650 50 
$EndSheet
Wire Wire Line
	10800 5750 10800 6250
Wire Wire Line
	10800 6250 1150 6250
Wire Wire Line
	1150 6250 1150 5600
Wire Wire Line
	1150 5600 1400 5600
$Sheet
S 4750 2850 1200 2800
U 5BAA648F
F0 "Coin Line Control" 50
F1 "Lines.sch" 50
F2 "L1_CO_TIP" U L 4750 2950 50 
F3 "L1_CO_RING" U L 4750 3050 50 
F4 "L1_HOLD_CO" I L 4750 4300 50 
F5 "L1_COIN_TIP" U R 5950 2950 50 
F6 "L1_OFF_HOOK_N" O L 4750 4500 50 
F7 "L1_COIN_CONTROL" I L 4750 4400 50 
F8 "L1_COIN_RING" U R 5950 3050 50 
F9 "COIN_OP" I R 5950 4000 50 
F10 "L2_CO_TIP" U L 4750 3200 50 
F11 "L2_CO_RING" U L 4750 3300 50 
F12 "L2_HOLD_CO" I L 4750 4650 50 
F13 "L2_COIN_TIP" U R 5950 3200 50 
F14 "L2_OFF_HOOK_N" O L 4750 4850 50 
F15 "L2_COIN_CONTROL" I L 4750 4750 50 
F16 "L2_COIN_RING" U R 5950 3300 50 
F17 "L3_CO_TIP" U L 4750 3450 50 
F18 "L3_CO_RING" U L 4750 3550 50 
F19 "L3_HOLD_CO" I L 4750 5000 50 
F20 "L3_COIN_TIP" U R 5950 3450 50 
F21 "L3_OFF_HOOK_N" O L 4750 5200 50 
F22 "L3_COIN_CONTROL" I L 4750 5100 50 
F23 "L3_COIN_RING" U R 5950 3550 50 
F24 "L4_CO_TIP" U L 4750 3700 50 
F25 "L4_CO_RING" U L 4750 3800 50 
F26 "L4_HOLD_CO" I L 4750 5350 50 
F27 "L4_COIN_TIP" U R 5950 3700 50 
F28 "L4_OFF_HOOK_N" O L 4750 5550 50 
F29 "L4_COIN_CONTROL" I L 4750 5450 50 
F30 "L4_COIN_RING" U R 5950 3800 50 
$EndSheet
Wire Wire Line
	3850 4300 4750 4300
Wire Wire Line
	3850 4400 4750 4400
Wire Wire Line
	3850 4500 4750 4500
Wire Wire Line
	3850 4650 4750 4650
Wire Wire Line
	4750 4750 3850 4750
Wire Wire Line
	3850 4850 4750 4850
Wire Wire Line
	3850 5000 4750 5000
Wire Wire Line
	3850 5100 4750 5100
Wire Wire Line
	3850 5200 4750 5200
Wire Wire Line
	3850 5550 4750 5550
Wire Wire Line
	10550 4500 10800 4500
Wire Wire Line
	10800 4500 10800 4000
Wire Wire Line
	10800 4000 5950 4000
$Comp
L Connector:8P8C J2
U 1 1 5BB8478F
P 3000 2200
F 0 "J2" V 3009 2730 50  0000 L CNN
F 1 "CO LINE" V 3100 2730 50  0000 L CNN
F 2 "Connector_RJ:RJ45_Amphenol_RJHSE5380" V 3000 2225 50  0000 C CNN
F 3 "~" V 3000 2225 50  0001 C CNN
	1    3000 2200
	0    1    1    0   
$EndComp
$Comp
L Connector:8P8C J5
U 1 1 5BB847E4
P 7850 2200
F 0 "J5" V 7859 1770 50  0000 R CNN
F 1 "COIN LINE" V 7950 1770 50  0000 R CNN
F 2 "Connector_RJ:RJ45_Amphenol_RJHSE5380" V 7850 2225 50  0001 C CNN
F 3 "~" V 7850 2225 50  0001 C CNN
	1    7850 2200
	0    -1   1    0   
$EndComp
Wire Wire Line
	3100 2600 3100 2950
Wire Wire Line
	3000 2600 3000 3050
Wire Wire Line
	3200 3300 3200 2600
Wire Wire Line
	2900 3200 2900 2600
Wire Wire Line
	2700 2600 2700 3450
Wire Wire Line
	2800 3550 2800 2600
Wire Wire Line
	3300 2600 3300 3700
Wire Wire Line
	3400 3800 3400 2600
Wire Wire Line
	7750 2950 7750 2600
Wire Wire Line
	7850 2600 7850 3050
Wire Wire Line
	7950 3200 7950 2600
Wire Wire Line
	7650 3300 7650 2600
Wire Wire Line
	8150 3450 8150 2600
Wire Wire Line
	8050 3550 8050 2600
Wire Wire Line
	7550 3700 7550 2600
Wire Wire Line
	7450 3800 7450 2600
Wire Wire Line
	10550 5750 10800 5750
$Comp
L Connector_Generic:Conn_02x10_Odd_Even J4
U 1 1 5E61544C
P 5200 1550
F 0 "J4" V 5204 962 50  0000 R CNN
F 1 "TEL LINE" V 5295 962 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x10_P2.54mm_Vertical" H 5200 1550 50  0001 C CNN
F 3 "~" H 5200 1550 50  0001 C CNN
	1    5200 1550
	0    -1   1    0   
$EndComp
Wire Wire Line
	5600 1350 5600 1050
Wire Wire Line
	5600 1050 6900 1050
Wire Wire Line
	5500 950  5500 1350
Wire Wire Line
	5400 850  5400 1350
Wire Wire Line
	5200 750  5200 1350
Wire Wire Line
	5100 850  5100 1350
Wire Wire Line
	5000 950  5000 1350
Wire Wire Line
	7700 4650 8450 4650
Wire Wire Line
	7700 4500 8450 4500
Wire Wire Line
	7700 4350 8450 4350
Wire Wire Line
	6450 4850 6650 4850
Wire Wire Line
	3850 5850 6450 5850
Wire Wire Line
	3850 5950 8450 5950
Wire Wire Line
	6450 4850 6450 5850
Connection ~ 6450 5850
Wire Wire Line
	6450 5850 8450 5850
Wire Wire Line
	2900 3200 4050 3200
Wire Wire Line
	3200 3300 4450 3300
Wire Wire Line
	3400 3800 4550 3800
Wire Wire Line
	3000 3050 4350 3050
Wire Wire Line
	3100 2950 3950 2950
Wire Wire Line
	2700 3450 4150 3450
Wire Wire Line
	2800 3550 4250 3550
Wire Wire Line
	4150 3450 4150 1050
Wire Wire Line
	4150 1050 4900 1050
Wire Wire Line
	4900 1050 4900 1350
Connection ~ 4150 3450
Wire Wire Line
	4150 3450 4750 3450
Wire Wire Line
	4050 3200 4050 950 
Wire Wire Line
	4050 950  5000 950 
Connection ~ 4050 3200
Wire Wire Line
	4050 3200 4750 3200
Wire Wire Line
	3300 3700 3850 3700
Wire Wire Line
	3950 2950 3950 850 
Connection ~ 3950 2950
Wire Wire Line
	3950 2950 4750 2950
Wire Wire Line
	3950 850  5100 850 
Wire Wire Line
	3850 3700 3850 750 
Wire Wire Line
	3850 750  5200 750 
Connection ~ 3850 3700
Wire Wire Line
	3850 3700 4750 3700
Wire Wire Line
	4250 3550 4250 2250
Wire Wire Line
	4250 2250 4900 2250
Wire Wire Line
	4900 2250 4900 1850
Connection ~ 4250 3550
Wire Wire Line
	4250 3550 4750 3550
Wire Wire Line
	4350 3050 4350 2350
Wire Wire Line
	4350 2350 5000 2350
Wire Wire Line
	5000 1850 5000 2350
Connection ~ 4350 3050
Wire Wire Line
	4350 3050 4750 3050
Wire Wire Line
	4450 3300 4450 2450
Wire Wire Line
	4450 2450 5100 2450
Wire Wire Line
	5100 1850 5100 2450
Connection ~ 4450 3300
Wire Wire Line
	4450 3300 4750 3300
Wire Wire Line
	4550 3800 4550 2550
Wire Wire Line
	4550 2550 5200 2550
Wire Wire Line
	5200 1850 5200 2550
Connection ~ 4550 3800
Wire Wire Line
	4550 3800 4750 3800
Wire Wire Line
	5950 3050 6450 3050
Wire Wire Line
	5950 2950 7000 2950
Wire Wire Line
	5950 3450 7200 3450
Wire Wire Line
	5950 3550 6350 3550
Wire Wire Line
	5950 3300 6550 3300
Wire Wire Line
	5950 3200 7100 3200
Wire Wire Line
	5950 3700 6900 3700
Wire Wire Line
	5950 3800 6650 3800
Wire Wire Line
	7200 3450 7200 750 
Wire Wire Line
	7200 750  5300 750 
Wire Wire Line
	5300 750  5300 1350
Connection ~ 7200 3450
Wire Wire Line
	7200 3450 8150 3450
Wire Wire Line
	7100 3200 7100 850 
Wire Wire Line
	5400 850  7100 850 
Connection ~ 7100 3200
Wire Wire Line
	7100 3200 7950 3200
Wire Wire Line
	7000 2950 7000 950 
Wire Wire Line
	5500 950  7000 950 
Connection ~ 7000 2950
Wire Wire Line
	7000 2950 7750 2950
Wire Wire Line
	6900 1050 6900 3700
Connection ~ 6900 3700
Wire Wire Line
	6900 3700 7550 3700
Wire Wire Line
	5300 2550 6350 2550
Wire Wire Line
	6350 2550 6350 3550
Wire Wire Line
	5300 1850 5300 2550
Connection ~ 6350 3550
Wire Wire Line
	6350 3550 8050 3550
Wire Wire Line
	5400 2450 6450 2450
Wire Wire Line
	6450 2450 6450 3050
Wire Wire Line
	5400 1850 5400 2450
Connection ~ 6450 3050
Wire Wire Line
	6450 3050 7850 3050
Wire Wire Line
	5500 2350 6550 2350
Wire Wire Line
	6550 2350 6550 3300
Wire Wire Line
	5500 1850 5500 2350
Connection ~ 6550 3300
Wire Wire Line
	6550 3300 7650 3300
Wire Wire Line
	5600 2250 6650 2250
Wire Wire Line
	6650 2250 6650 3800
Wire Wire Line
	5600 1850 5600 2250
Connection ~ 6650 3800
Wire Wire Line
	6650 3800 7450 3800
Text Label 4550 2550 0    50   ~ 0
L4_CO_RING
Text Label 4450 2450 0    50   ~ 0
L2_CO_RING
Text Label 4350 2350 0    50   ~ 0
L1_CO_RING
Text Label 4250 2250 0    50   ~ 0
L3_CO_RING
Text Label 5700 2450 0    50   ~ 0
L1_COIN_RING
Text Label 5700 2550 0    50   ~ 0
L3_COIN_RING
Text Label 5700 2350 0    50   ~ 0
L2_COIN_RING
Text Label 5700 2250 0    50   ~ 0
L4_COIN_RING
Text Label 4300 750  0    50   ~ 0
L4_CO_TIP
Text Label 4300 850  0    50   ~ 0
L1_CO_TIP
Text Label 4300 950  0    50   ~ 0
L2_CO_TIP
Text Label 4300 1050 0    50   ~ 0
L3_CO_TIP
Text Label 5850 750  0    50   ~ 0
L3_COIN_TIP
Text Label 5850 850  0    50   ~ 0
L2_COIN_TIP
Text Label 5850 950  0    50   ~ 0
L1_COIN_TIP
Text Label 5850 1050 0    50   ~ 0
L4_COIN_TIP
$Comp
L power:GND #PWR06
U 1 1 5EB75B48
P 5700 1950
F 0 "#PWR06" H 5700 1700 50  0001 C CNN
F 1 "GND" H 5705 1777 50  0000 C CNN
F 2 "" H 5700 1950 50  0001 C CNN
F 3 "" H 5700 1950 50  0001 C CNN
	1    5700 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	5700 1850 5700 1900
Wire Wire Line
	5700 1350 5700 1250
Wire Wire Line
	5700 1250 5900 1250
Wire Wire Line
	5900 1250 5900 1900
Wire Wire Line
	5900 1900 5700 1900
Connection ~ 5700 1900
Wire Wire Line
	5700 1900 5700 1950
$Comp
L 1d_coinctrl_r2-rescue:PJ-202A-dk_Barrel-Power-Connectors J?
U 1 1 5EBCDBAC
P 1250 1100
AR Path="/5BA47743/5EBCDBAC" Ref="J?"  Part="1" 
AR Path="/5EBCDBAC" Ref="J1"  Part="1" 
F 0 "J1" H 1183 1325 50  0000 C CNN
F 1 "+12V INPUT" H 1183 1234 50  0000 C CNN
F 2 "digikey-footprints:Barrel_Jack_5.5mmODx2.1mmID_PJ-202A" H 1450 1300 60  0001 L CNN
F 3 "https://www.cui.com/product/resource/digikeypdf/pj-202a.pdf" H 1450 1400 60  0001 L CNN
F 4 "CP-202A-ND" H 1450 1500 60  0001 L CNN "Digi-Key_PN"
F 5 "PJ-202A" H 1450 1600 60  0001 L CNN "MPN"
F 6 "Connectors, Interconnects" H 1450 1700 60  0001 L CNN "Category"
F 7 "Barrel - Power Connectors" H 1450 1800 60  0001 L CNN "Family"
F 8 "https://www.cui.com/product/resource/digikeypdf/pj-202a.pdf" H 1450 1900 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/cui-inc/PJ-202A/CP-202A-ND/252007" H 1450 2000 60  0001 L CNN "DK_Detail_Page"
F 10 "CONN PWR JACK 2X5.5MM KINKED PIN" H 1450 2100 60  0001 L CNN "Description"
F 11 "CUI Inc." H 1450 2200 60  0001 L CNN "Manufacturer"
F 12 "Active" H 1450 2300 60  0001 L CNN "Status"
	1    1250 1100
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR02
U 1 1 5EBD25AB
P 1500 1450
F 0 "#PWR02" H 1500 1200 50  0001 C CNN
F 1 "GND" H 1505 1277 50  0000 C CNN
F 2 "" H 1500 1450 50  0001 C CNN
F 3 "" H 1500 1450 50  0001 C CNN
	1    1500 1450
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR01
U 1 1 5EBD2C6A
P 1500 800
F 0 "#PWR01" H 1500 650 50  0001 C CNN
F 1 "+12V" H 1515 973 50  0000 C CNN
F 2 "" H 1500 800 50  0001 C CNN
F 3 "" H 1500 800 50  0001 C CNN
	1    1500 800 
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR07
U 1 1 5EBD349B
P 6450 4250
F 0 "#PWR07" H 6450 4100 50  0001 C CNN
F 1 "+12V" H 6465 4423 50  0000 C CNN
F 2 "" H 6450 4250 50  0001 C CNN
F 3 "" H 6450 4250 50  0001 C CNN
	1    6450 4250
	1    0    0    -1  
$EndComp
Wire Wire Line
	6450 4250 6450 4350
Wire Wire Line
	6450 4350 6650 4350
Wire Wire Line
	1350 1100 1500 1100
Wire Wire Line
	1500 1100 1500 900 
Wire Wire Line
	1350 1200 1500 1200
Wire Wire Line
	1500 1200 1500 1300
Wire Wire Line
	1350 1300 1500 1300
Connection ~ 1500 1300
Wire Wire Line
	1500 1300 1500 1450
$Comp
L 1d_coinctrl_r2-rescue:+12V_RELAY-power #PWR?
U 1 1 5EC0EC95
P 2550 1000
AR Path="/5BA4B80D/5EC0EC95" Ref="#PWR?"  Part="1" 
AR Path="/5BA47743/5EC0EC95" Ref="#PWR?"  Part="1" 
AR Path="/5EC0EC95" Ref="#12V_RELAY0101"  Part="1" 
F 0 "#12V_RELAY0101" H 2550 850 50  0001 C CNN
F 1 "+12V_RELAY" H 2565 1173 50  0000 C CNN
F 2 "" H 2550 1000 50  0001 C CNN
F 3 "" H 2550 1000 50  0001 C CNN
	1    2550 1000
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x03 J?
U 1 1 5EC0EC9B
P 3250 1200
AR Path="/5BA47743/5EC0EC9B" Ref="J?"  Part="1" 
AR Path="/5EC0EC9B" Ref="J3"  Part="1" 
F 0 "J3" H 3330 1242 50  0000 L CNN
F 1 "V_RLY_SEL" H 3330 1151 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 3250 1200 50  0001 C CNN
F 3 "~" H 3250 1200 50  0001 C CNN
	1    3250 1200
	1    0    0    -1  
$EndComp
Wire Wire Line
	2550 1000 2550 1200
Wire Wire Line
	2550 1200 3050 1200
Wire Wire Line
	2950 1100 3050 1100
Wire Wire Line
	3050 1300 2150 1300
Wire Wire Line
	2150 1300 2150 1000
$Comp
L power:+12V #PWR05
U 1 1 5EC1AB59
P 2950 1000
F 0 "#PWR05" H 2950 850 50  0001 C CNN
F 1 "+12V" H 2965 1173 50  0000 C CNN
F 2 "" H 2950 1000 50  0001 C CNN
F 3 "" H 2950 1000 50  0001 C CNN
	1    2950 1000
	1    0    0    -1  
$EndComp
Wire Wire Line
	2950 1100 2950 1000
$Comp
L power:+5V #PWR03
U 1 1 5EC4118D
P 2150 1000
F 0 "#PWR03" H 2150 850 50  0001 C CNN
F 1 "+5V" H 2165 1173 50  0000 C CNN
F 2 "" H 2150 1000 50  0001 C CNN
F 3 "" H 2150 1000 50  0001 C CNN
	1    2150 1000
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR08
U 1 1 5EC5435B
P 7850 4950
F 0 "#PWR08" H 7850 4800 50  0001 C CNN
F 1 "+5V" H 7865 5123 50  0000 C CNN
F 2 "" H 7850 4950 50  0001 C CNN
F 3 "" H 7850 4950 50  0001 C CNN
	1    7850 4950
	1    0    0    -1  
$EndComp
Wire Wire Line
	7700 5050 7850 5050
Wire Wire Line
	7850 5050 7850 4950
$Comp
L Device:R_US R?
U 1 1 5EC9C37A
P 1500 2250
AR Path="/5BAA648F/5EC9C37A" Ref="R?"  Part="1" 
AR Path="/5EC9C37A" Ref="R14"  Part="1" 
F 0 "R14" V 1295 2250 50  0000 C CNN
F 1 "220" V 1386 2250 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 1540 2240 50  0001 C CNN
F 3 "~" H 1500 2250 50  0001 C CNN
	1    1500 2250
	-1   0    0    1   
$EndComp
$Comp
L Device:LED D?
U 1 1 5EC9C380
P 1500 2650
AR Path="/5BAA648F/5EC9C380" Ref="D?"  Part="1" 
AR Path="/5EC9C380" Ref="D18"  Part="1" 
F 0 "D18" V 1538 2533 50  0000 R CNN
F 1 "POWER_LED" V 1447 2533 50  0000 R CNN
F 2 "LED_THT:LED_D5.0mm" H 1500 2650 50  0001 C CNN
F 3 "~" H 1500 2650 50  0001 C CNN
	1    1500 2650
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1500 2500 1500 2400
$Comp
L power:+5V #PWR0101
U 1 1 5ECB61B7
P 1500 1950
F 0 "#PWR0101" H 1500 1800 50  0001 C CNN
F 1 "+5V" H 1515 2123 50  0000 C CNN
F 2 "" H 1500 1950 50  0001 C CNN
F 3 "" H 1500 1950 50  0001 C CNN
	1    1500 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	1500 2100 1500 1950
$Comp
L power:GND #PWR0102
U 1 1 5ECC3CBA
P 1500 2950
F 0 "#PWR0102" H 1500 2700 50  0001 C CNN
F 1 "GND" H 1505 2777 50  0000 C CNN
F 2 "" H 1500 2950 50  0001 C CNN
F 3 "" H 1500 2950 50  0001 C CNN
	1    1500 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	1500 2950 1500 2800
$Comp
L Device:CP1 C?
U 1 1 5F047684
P 1800 1100
AR Path="/5BA47743/5F047684" Ref="C?"  Part="1" 
AR Path="/5F047684" Ref="C14"  Part="1" 
F 0 "C14" H 1915 1146 50  0000 L CNN
F 1 "1000uF 25V" H 1915 1055 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D12.5mm_P5.00mm" H 1800 1100 50  0001 C CNN
F 3 "~" H 1800 1100 50  0001 C CNN
	1    1800 1100
	1    0    0    -1  
$EndComp
Wire Wire Line
	1500 1300 1800 1300
Wire Wire Line
	1800 1300 1800 1250
Wire Wire Line
	1800 950  1800 900 
Wire Wire Line
	1500 900  1800 900 
Connection ~ 1500 900 
Wire Wire Line
	1500 900  1500 800 
Wire Wire Line
	3850 5350 4750 5350
Wire Wire Line
	3850 5450 4750 5450
NoConn ~ 4800 1350
NoConn ~ 4800 1850
$Comp
L Connector_Generic:Conn_01x02 J7
U 1 1 5F18B6F9
P 7950 5500
F 0 "J7" H 7868 5717 50  0000 C CNN
F 1 "Conn_01x02" H 7868 5626 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 7950 5500 50  0001 C CNN
F 3 "~" H 7950 5500 50  0001 C CNN
	1    7950 5500
	-1   0    0    -1  
$EndComp
Wire Wire Line
	8150 5600 8450 5600
Wire Wire Line
	8150 5500 8300 5500
Wire Wire Line
	8300 5500 8300 5450
Wire Wire Line
	8300 5450 8450 5450
$Comp
L Mechanical:MountingHole H2
U 1 1 5F1F4ECC
P 1050 7200
F 0 "H2" H 1150 7246 50  0000 L CNN
F 1 "MountingHole" H 1150 7155 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.7mm_Pad" H 1050 7200 50  0001 C CNN
F 3 "~" H 1050 7200 50  0001 C CNN
	1    1050 7200
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H3
U 1 1 5F1F5584
P 1050 7400
F 0 "H3" H 1150 7446 50  0000 L CNN
F 1 "MountingHole" H 1150 7355 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.7mm_Pad" H 1050 7400 50  0001 C CNN
F 3 "~" H 1050 7400 50  0001 C CNN
	1    1050 7400
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H4
U 1 1 5F1F5E9B
P 1050 7600
F 0 "H4" H 1150 7646 50  0000 L CNN
F 1 "MountingHole" H 1150 7555 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.7mm_Pad" H 1050 7600 50  0001 C CNN
F 3 "~" H 1050 7600 50  0001 C CNN
	1    1050 7600
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H1
U 1 1 5F1F6082
P 1050 7000
F 0 "H1" H 1150 7046 50  0000 L CNN
F 1 "MountingHole" H 1150 6955 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.7mm_Pad" H 1050 7000 50  0001 C CNN
F 3 "~" H 1050 7000 50  0001 C CNN
	1    1050 7000
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:MountingHole H6
U 1 1 5F30BE6B
P 2350 7000
F 0 "H6" H 2450 7046 50  0000 L CNN
F 1 "MountingHole" H 2450 6955 50  0000 L CNN
F 2 "MountingHole:MountingHole_3.7mm_Pad" H 2350 7000 50  0001 C CNN
F 3 "~" H 2350 7000 50  0001 C CNN
	1    2350 7000
	1    0    0    -1  
$EndComp
Text Notes 7050 6900 0    197  Italic 39
1D Coin Controller
Text Notes 7100 7050 0    50   Italic 10
(c) 2020, Howard M. Harte - WZ2Q
Text Notes 10600 7650 0    50   ~ 0
1
Text Notes 7400 7500 0    50   ~ 0
1D Coin Controller - Connectors
Text Notes 8150 7650 0    50   ~ 0
2020-06-06
$EndSCHEMATC
