EESchema Schematic File Version 4
LIBS:Transceiver-cache
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 5
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
L Oscillator:Si5351A-B-GT U?
U 1 1 5E709187
P 1750 1600
F 0 "U?" H 2250 1950 50  0000 C CNN
F 1 "Si5351A-B-GT" H 2300 2050 50  0000 C CNN
F 2 "Package_SO:MSOP-10_3x3mm_P0.5mm" H 1750 800 50  0001 C CNN
F 3 "https://www.silabs.com/documents/public/data-sheets/Si5351-B.pdf" H 1400 1500 50  0001 C CNN
	1    1750 1600
	1    0    0    -1  
$EndComp
$Comp
L SA612A:AD9833 U?
U 1 1 5E70C26E
P 1400 3200
F 0 "U?" H 2200 3150 50  0000 L CNN
F 1 "AD9833" H 2050 3250 50  0000 L CNN
F 2 "" H 2150 3250 50  0001 C CNN
F 3 "https://www.analog.com/media/en/technical-documentation/data-sheets/ad9833.pdf" H 2150 3250 50  0001 C CNN
	1    1400 3200
	1    0    0    -1  
$EndComp
$Comp
L SA612A:SA612A U?
U 1 1 5E70D4F8
P 7350 1450
F 0 "U?" H 7375 1825 50  0000 C CNN
F 1 "SA612A" H 7375 1734 50  0000 C CNN
F 2 "" H 7400 1650 50  0001 C CNN
F 3 "https://www.nxp.com/docs/en/data-sheet/SA612A.pdf" H 7350 1450 50  0001 C CNN
	1    7350 1450
	1    0    0    -1  
$EndComp
NoConn ~ 7800 1400
Wire Wire Line
	7850 1100 7850 1300
Wire Wire Line
	7850 1300 7800 1300
$Comp
L power:+5V #PWR?
U 1 1 5E70CD98
P 7850 1100
F 0 "#PWR?" H 7850 950 50  0001 C CNN
F 1 "+5V" H 7865 1273 50  0000 C CNN
F 2 "" H 7850 1100 50  0001 C CNN
F 3 "" H 7850 1100 50  0001 C CNN
	1    7850 1100
	1    0    0    -1  
$EndComp
Text Notes 6950 1000 0    50   ~ 0
Nota: Vcc 4.5-8.0v
$Sheet
S 3500 1100 1150 200 
U 5E70F6BF
F0 "Si5351 atenuator" 50
F1 "Si5351_Filter.sch" 50
F2 "Clk0_Fi" I L 3500 1200 50 
F3 "Clk0_Fo" I R 4650 1200 50 
$EndSheet
Wire Wire Line
	2250 1400 2400 1400
Wire Wire Line
	7800 1500 7950 1500
Text Label 2400 1400 0    50   ~ 0
Clk0_Fi
Text Label 7950 1500 0    50   ~ 0
Clk0_Fo
$Sheet
S 5950 6500 950  1200
U 5E710609
F0 "MCU" 50
F1 "MCU.sch" 50
$EndSheet
Text Label 3500 1200 2    50   ~ 0
Clk0_Fi
Text Label 4650 1200 0    50   ~ 0
Clk0_Fo
Text Notes 1000 1150 0    50   ~ 0
Nota: Vcc 3.3v
Wire Wire Line
	2350 3700 2250 3700
Text Label 2350 3700 0    50   ~ 0
MClk_Fi
$Sheet
S 3500 3500 1100 300 
U 5E71DA61
F0 "AD9833 Filter" 50
F1 "AD98333 filter.sch" 50
F2 "MClk_Fi" I L 3500 3600 50 
F3 "IN_A_Out" I R 4600 3600 50 
F4 "IN_B_Out" I R 4600 3700 50 
$EndSheet
Text Label 6950 1300 2    50   ~ 0
IN_A_Out
Text Label 6950 1400 2    50   ~ 0
IN_B_Out
Text Label 4600 3600 0    50   ~ 0
IN_A_Out
Text Label 4600 3700 0    50   ~ 0
IN_B_Out
Text Label 3500 3600 2    50   ~ 0
MClk_Fi
Text Label 1300 3600 2    50   ~ 0
SS_AD9833
Text Label 1300 3700 2    50   ~ 0
SCLK_0
Text Label 1300 3800 2    50   ~ 0
MOSI_0
Text Label 1250 1800 2    50   ~ 0
SCL_0
Text Label 1250 1900 2    50   ~ 0
SDA_0
$Comp
L power:GND #PWR?
U 1 1 5E72A503
P 1800 4300
F 0 "#PWR?" H 1800 4050 50  0001 C CNN
F 1 "GND" H 1805 4127 50  0000 C CNN
F 2 "" H 1800 4300 50  0001 C CNN
F 3 "" H 1800 4300 50  0001 C CNN
	1    1800 4300
	1    0    0    -1  
$EndComp
Wire Wire Line
	1750 4150 1750 4250
Wire Wire Line
	1750 4250 1800 4250
Wire Wire Line
	1800 4250 1800 4300
Wire Wire Line
	1800 4250 1850 4250
Wire Wire Line
	1850 4250 1850 4150
Connection ~ 1800 4250
$Comp
L power:GND #PWR?
U 1 1 5E72AFA8
P 1750 2250
F 0 "#PWR?" H 1750 2000 50  0001 C CNN
F 1 "GND" H 1755 2077 50  0000 C CNN
F 2 "" H 1750 2250 50  0001 C CNN
F 3 "" H 1750 2250 50  0001 C CNN
	1    1750 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	1750 2100 1750 2250
Text Label 5850 6600 2    50   ~ 0
SCL_0
Text Label 5850 6700 2    50   ~ 0
SDA_0
Text Label 5850 6800 2    50   ~ 0
SS_AD9833
Text Label 5850 6900 2    50   ~ 0
SCLK_0
Text Label 5850 7000 2    50   ~ 0
MOSI_0
$Comp
L power:+3.3V #PWR?
U 1 1 5E72FC33
P 1650 900
F 0 "#PWR?" H 1650 750 50  0001 C CNN
F 1 "+3.3V" H 1665 1073 50  0000 C CNN
F 2 "" H 1650 900 50  0001 C CNN
F 3 "" H 1650 900 50  0001 C CNN
	1    1650 900 
	1    0    0    -1  
$EndComp
Wire Wire Line
	1650 900  1650 1000
Wire Wire Line
	1850 1100 1850 1000
Wire Wire Line
	1850 1000 1650 1000
Connection ~ 1650 1000
Wire Wire Line
	1650 1000 1650 1100
$Comp
L power:GND #PWR?
U 1 1 5E73217F
P 6550 1650
F 0 "#PWR?" H 6550 1400 50  0001 C CNN
F 1 "GND" H 6555 1477 50  0000 C CNN
F 2 "" H 6550 1650 50  0001 C CNN
F 3 "" H 6550 1650 50  0001 C CNN
	1    6550 1650
	1    0    0    -1  
$EndComp
Wire Wire Line
	6550 1500 6550 1650
Wire Wire Line
	6950 1500 6550 1500
$Comp
L Audio:PCM5102 U?
U 1 1 5E73A0A6
P 1800 5800
F 0 "U?" H 1800 6581 50  0000 C CNN
F 1 "PCM5102" H 1800 6490 50  0000 C CNN
F 2 "Package_SO:TSSOP-20_4.4x6.5mm_P0.65mm" H 1750 6550 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/pcm5102.pdf" H 1750 6550 50  0001 C CNN
	1    1800 5800
	1    0    0    -1  
$EndComp
Text Notes 2000 5200 0    50   ~ 0
Nota : replaced by PCM5102A\nUSE a board ?
Text Label 2300 5400 0    50   ~ 0
OutL
Text Label 2300 5500 0    50   ~ 0
OutR
Text Label 6900 2300 2    50   ~ 0
OutL
Text Label 6900 2400 2    50   ~ 0
OutR
Text Label 1300 5700 2    50   ~ 0
SAI_MCLK
Text Label 1300 5600 2    50   ~ 0
SAI_SCK
Text Label 1300 5500 2    50   ~ 0
SAI_SD
Text Label 1300 5400 2    50   ~ 0
SAI_FS
Text Label 5850 7400 2    50   ~ 0
SAI_MCLK
Text Label 5850 7300 2    50   ~ 0
SAI_SCK
Text Label 5850 7200 2    50   ~ 0
SAI_SD
Text Label 5850 7100 2    50   ~ 0
SAI_FS
Text Notes 4550 3450 0    50   ~ 0
Nota : IN_A & IN_B are biased internally, They are symmetrical.\nEquivalent AC impédance 1.5Khos 3pF 50MHz.\n
$Comp
L Device:Q_NPN_BCE Q?
U 1 1 5E76FBFD
P 9700 1750
F 0 "Q?" H 9891 1796 50  0000 L CNN
F 1 "Q_NPN_BCE" H 9891 1705 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-323_SC-70_Handsoldering" H 9900 1850 50  0001 C CNN
F 3 "~" H 9700 1750 50  0001 C CNN
	1    9700 1750
	1    0    0    -1  
$EndComp
$Sheet
S 4000 4450 1350 600 
U 5E77AF45
F0 "AM Module" 50
F1 "AM Module.sch" 50
$EndSheet
$EndSCHEMATC
