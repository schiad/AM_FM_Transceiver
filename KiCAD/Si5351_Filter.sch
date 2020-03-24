EESchema Schematic File Version 4
LIBS:Transceiver-cache
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 5
Title "AM & FM Transceiver"
Date ""
Rev ""
Comp "F4IFB"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Notes 7000 1400 0    50   ~ 0
Nota : IN_A & IN_B are biased internally, They are symmetrical.\nEquivalent AC impédance 1.5Khos 3pF 50MHz.\n
Text HLabel 2950 1100 0    50   Input ~ 0
Clk0_Fi
Text HLabel 4250 1100 2    50   Input ~ 0
Clk0_Fo
$Comp
L Device:C C?
U 1 1 5E724D9F
P 4000 1100
F 0 "C?" V 3748 1100 50  0000 C CNN
F 1 "100n" V 3839 1100 50  0000 C CNN
F 2 "" H 4038 950 50  0001 C CNN
F 3 "~" H 4000 1100 50  0001 C CNN
	1    4000 1100
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5E725253
P 3600 1100
F 0 "R?" V 3393 1100 50  0000 C CNN
F 1 "100" V 3484 1100 50  0000 C CNN
F 2 "" V 3530 1100 50  0001 C CNN
F 3 "~" H 3600 1100 50  0001 C CNN
	1    3600 1100
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5E725401
P 3800 1300
F 0 "R?" H 3870 1346 50  0000 L CNN
F 1 "100" H 3870 1255 50  0000 L CNN
F 2 "" V 3730 1300 50  0001 C CNN
F 3 "~" H 3800 1300 50  0001 C CNN
	1    3800 1300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5E726822
P 3800 1550
F 0 "#PWR?" H 3800 1300 50  0001 C CNN
F 1 "GND" H 3805 1377 50  0000 C CNN
F 2 "" H 3800 1550 50  0001 C CNN
F 3 "" H 3800 1550 50  0001 C CNN
	1    3800 1550
	1    0    0    -1  
$EndComp
$Comp
L Device:C C?
U 1 1 5E7270D7
P 3200 1100
F 0 "C?" V 2948 1100 50  0000 C CNN
F 1 "100n" V 3039 1100 50  0000 C CNN
F 2 "" H 3238 950 50  0001 C CNN
F 3 "~" H 3200 1100 50  0001 C CNN
	1    3200 1100
	0    1    1    0   
$EndComp
Wire Wire Line
	2950 1100 3050 1100
Wire Wire Line
	3350 1100 3450 1100
Wire Wire Line
	3750 1100 3800 1100
Wire Wire Line
	3800 1150 3800 1100
Connection ~ 3800 1100
Wire Wire Line
	3800 1100 3850 1100
Wire Wire Line
	3800 1450 3800 1550
Wire Wire Line
	4150 1100 4250 1100
$EndSCHEMATC
