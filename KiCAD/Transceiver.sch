EESchema Schematic File Version 4
LIBS:Transceiver-cache
EELAYER 30 0
EELAYER END
$Descr A3 16535 11693
encoding utf-8
Sheet 1 5
Title "AM & FM Transceiver"
Date ""
Rev ""
Comp "F4IFB"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
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
S 3050 1200 1150 200 
U 5E70F6BF
F0 "Si5351 atenuator" 50
F1 "Si5351_Filter.sch" 50
F2 "Clk0_Fi" I L 3050 1300 50 
F3 "Clk0_Fo" I R 4200 1300 50 
$EndSheet
Wire Wire Line
	7800 1500 7950 1500
Text Label 1450 1150 2    50   ~ 0
Clk0_Fi
Text Label 7950 1500 0    50   ~ 0
Clk0_Fo
Text Label 3050 1300 2    50   ~ 0
Clk0_Fi
Text Label 4200 1300 0    50   ~ 0
Clk0_Fo
Text Label 1450 2900 2    50   ~ 0
MClk_Fi
Text Label 6950 1300 2    50   ~ 0
IN_A_Out
Text Label 6950 1400 2    50   ~ 0
IN_B_Out
Text Label 1450 2700 2    50   ~ 0
SS_AD9833
Text Label 1450 2600 2    50   ~ 0
SCLK_0
Text Label 1450 2500 2    50   ~ 0
MOSI_0
Text Label 1450 1450 2    50   ~ 0
SCL_0
Text Label 1450 1550 2    50   ~ 0
SDA_0
$Comp
L power:GND #PWR?
U 1 1 5E72A503
P 1200 2400
F 0 "#PWR?" H 1200 2150 50  0001 C CNN
F 1 "GND" H 1205 2227 50  0000 C CNN
F 2 "" H 1200 2400 50  0001 C CNN
F 3 "" H 1200 2400 50  0001 C CNN
	1    1200 2400
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5E72AFA8
P 1150 1650
F 0 "#PWR?" H 1150 1400 50  0001 C CNN
F 1 "GND" H 1155 1477 50  0000 C CNN
F 2 "" H 1150 1650 50  0001 C CNN
F 3 "" H 1150 1650 50  0001 C CNN
	1    1150 1650
	0    1    1    0   
$EndComp
Wire Wire Line
	1350 1750 1450 1750
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
$Sheet
S 3100 3500 1150 450 
U 5E77AF45
F0 "AM Module" 50
F1 "AM Module.sch" 50
F2 "HF" I L 3100 3750 50 
F3 "BF" I L 3100 3650 50 
F4 "Feed_BackBFin" I R 4250 3650 50 
F5 "Feed_BackBFout" I R 4250 3750 50 
$EndSheet
Text Label 1450 1250 2    50   ~ 0
Clk1_Fi
Text Label 3100 3750 2    50   ~ 0
Clk1_Fi
Text Label 4250 3650 0    50   ~ 0
FBBFin
Text Label 4250 3750 0    50   ~ 0
FBBFout
Text Label 3100 2500 2    50   ~ 0
MClk_Fi
Text Label 4200 2500 0    50   ~ 0
IN_A_Out
$Sheet
S 3100 2400 1100 200 
U 5E71DA61
F0 "AD9833 Filter" 50
F1 "AD98333 filter.sch" 50
F2 "MClk_Fi" I L 3100 2500 50 
F3 "IN_A_Out" O R 4200 2500 50 
$EndSheet
Text HLabel 4250 3850 0    50   Input ~ 0
AM_Out
Text Label 4250 3850 0    50   ~ 0
AM_Out
Text Label 3100 3650 2    50   ~ 0
BF_IN_AM
$Sheet
S 3150 5150 1150 250 
U 5E7F5958
F0 "LEDS" 50
F1 "LEDs_indicators.sch" 50
$EndSheet
$Comp
L power:+5V #PWR?
U 1 1 5E863CE3
P 1350 1750
F 0 "#PWR?" H 1350 1600 50  0001 C CNN
F 1 "+5V" H 1365 1923 50  0000 C CNN
F 2 "" H 1350 1750 50  0001 C CNN
F 3 "" H 1350 1750 50  0001 C CNN
	1    1350 1750
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1150 1650 1450 1650
$Comp
L Connector:Conn_01x07_Female J?
U 1 1 5E86DF68
P 1650 1450
F 0 "J?" H 1678 1521 50  0000 L CNN
F 1 "Conn_01x07_Female" H 1678 1430 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x07_P2.54mm_Vertical" H 1650 1450 50  0001 C CNN
F 3 "~" H 1650 1450 50  0001 C CNN
F 4 "Si5351a Module" H 1678 1339 50  0000 L CNN "Ref"
	1    1650 1450
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x07_Female J?
U 1 1 5E8767CB
P 1650 2600
F 0 "J?" H 1678 2671 50  0000 L CNN
F 1 "Conn_01x07_Female" H 1678 2580 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x07_P2.54mm_Vertical" H 1650 2600 50  0001 C CNN
F 3 "~" H 1650 2600 50  0001 C CNN
F 4 "AD9833 Module" H 1678 2489 50  0000 L CNN "Ref"
	1    1650 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	1200 2400 1450 2400
Wire Wire Line
	1350 2300 1450 2300
$Comp
L power:+5V #PWR?
U 1 1 5E887462
P 1350 2300
F 0 "#PWR?" H 1350 2150 50  0001 C CNN
F 1 "+5V" H 1365 2473 50  0000 C CNN
F 2 "" H 1350 2300 50  0001 C CNN
F 3 "" H 1350 2300 50  0001 C CNN
	1    1350 2300
	0    -1   -1   0   
$EndComp
Text Label 1400 3600 0    50   ~ 0
GY-PCM5102
Text Label 1500 4700 2    50   ~ 0
OutL
Text Label 1500 4500 2    50   ~ 0
OutR
Text Label 1500 3850 2    50   ~ 0
I2Sa_CK
Text Label 1500 3950 2    50   ~ 0
I2Sa_WS
Text Label 1500 4050 2    50   ~ 0
I2Sa_SD
$Comp
L Connector:Conn_01x06_Female J?
U 1 1 5E8A3ED8
P 1700 3950
F 0 "J?" H 1650 4250 50  0000 L CNN
F 1 "Conn_01x06_Female" H 1728 3835 50  0001 L CNN
F 2 "" H 1700 3950 50  0001 C CNN
F 3 "~" H 1700 3950 50  0001 C CNN
F 4 "GY-PCM5102 module" H 2100 3600 50  0000 C CNN "Ref"
	1    1700 3950
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5E8A5E94
P 1250 4150
F 0 "#PWR?" H 1250 3900 50  0001 C CNN
F 1 "GND" H 1255 3977 50  0000 C CNN
F 2 "" H 1250 4150 50  0001 C CNN
F 3 "" H 1250 4150 50  0001 C CNN
	1    1250 4150
	0    1    1    0   
$EndComp
Wire Wire Line
	1250 4150 1500 4150
$Comp
L Connector:Conn_01x04_Female J?
U 1 1 5E85D223
P 1700 4600
F 0 "J?" H 1728 4621 50  0000 L CNN
F 1 "Conn_01x04_Female" H 1728 4530 50  0000 L CNN
F 2 "" H 1700 4600 50  0001 C CNN
F 3 "~" H 1700 4600 50  0001 C CNN
F 4 "GY-PCM5102 module" H 1728 4439 50  0000 L CNN "Ref"
	1    1700 4600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5E85EBD4
P 1250 4800
F 0 "#PWR?" H 1250 4550 50  0001 C CNN
F 1 "GND" H 1255 4627 50  0000 C CNN
F 2 "" H 1250 4800 50  0001 C CNN
F 3 "" H 1250 4800 50  0001 C CNN
	1    1250 4800
	0    1    1    0   
$EndComp
Wire Wire Line
	1250 4800 1500 4800
$Comp
L power:GND #PWR?
U 1 1 5E860DAB
P 1250 4600
F 0 "#PWR?" H 1250 4350 50  0001 C CNN
F 1 "GND" H 1255 4427 50  0000 C CNN
F 2 "" H 1250 4600 50  0001 C CNN
F 3 "" H 1250 4600 50  0001 C CNN
	1    1250 4600
	0    1    1    0   
$EndComp
Wire Wire Line
	1250 4600 1500 4600
Text Label 3950 4550 0    50   ~ 0
BF_IN_AM
Text Label 3400 4650 2    50   ~ 0
OutL
Text Label 3400 4550 2    50   ~ 0
OutR
$Comp
L Device:R R?
U 1 1 5E7DE6C9
P 3650 4550
F 0 "R?" V 3443 4550 50  0000 C CNN
F 1 "R" V 3534 4550 50  0000 C CNN
F 2 "" V 3580 4550 50  0001 C CNN
F 3 "~" H 3650 4550 50  0001 C CNN
	1    3650 4550
	0    1    1    0   
$EndComp
$Comp
L Device:R R?
U 1 1 5E7DEE26
P 3650 4650
F 0 "R?" V 3443 4650 50  0000 C CNN
F 1 "R" V 3534 4650 50  0000 C CNN
F 2 "" V 3580 4650 50  0001 C CNN
F 3 "~" H 3650 4650 50  0001 C CNN
	1    3650 4650
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3950 4550 3900 4550
Wire Wire Line
	3800 4650 3900 4650
Wire Wire Line
	3900 4650 3900 4550
Connection ~ 3900 4550
Wire Wire Line
	3900 4550 3800 4550
Wire Wire Line
	3400 4650 3500 4650
Wire Wire Line
	3400 4550 3500 4550
$Comp
L Connector:Conn_01x20_Female J?
U 1 1 5E85F363
P 1500 7750
F 0 "J?" H 1450 8750 50  0000 L CNN
F 1 "Conn_01x20_Female" H 1400 8750 50  0001 L CNN
F 2 "" H 1500 7750 50  0001 C CNN
F 3 "~" H 1500 7750 50  0001 C CNN
	1    1500 7750
	1    0    0    -1  
$EndComp
Text Notes 1500 6880 0    50   ~ 0
5V
Text Notes 1500 6980 0    50   ~ 0
GND
Text Notes 1500 7080 0    50   ~ 0
3.3V
Text Notes 1500 7180 0    50   ~ 0
PB10
Text Notes 1500 7280 0    50   ~ 0
PB2
Text Notes 1500 7380 0    50   ~ 0
PB1
Text Notes 1500 7480 0    50   ~ 0
PB0
Text Notes 1500 7580 0    50   ~ 0
PA7
Text Notes 1500 7680 0    50   ~ 0
PA6
Text Notes 1500 7780 0    50   ~ 0
PA5
Text Notes 1500 7880 0    50   ~ 0
PA4
Text Notes 1500 7980 0    50   ~ 0
PA3
Text Notes 1500 8080 0    50   ~ 0
PA2
Text Notes 1500 8180 0    50   ~ 0
PA1
Text Notes 1500 8280 0    50   ~ 0
PA0
Text Notes 1500 8380 0    50   ~ 0
RST
Text Notes 1500 8480 0    50   ~ 0
PC15
Text Notes 1500 8580 0    50   ~ 0
PC14
Text Notes 1500 8680 0    50   ~ 0
PC13
Text Notes 1500 8780 0    50   ~ 0
VB
$Comp
L Connector:Conn_01x20_Female J?
U 1 1 5E86FD09
P 2000 7850
F 0 "J?" H 1950 8850 50  0000 L CNN
F 1 "Conn_01x20_Female" H 1900 8850 50  0001 L CNN
F 2 "" H 2000 7850 50  0001 C CNN
F 3 "~" H 2000 7850 50  0001 C CNN
	1    2000 7850
	-1   0    0    1   
$EndComp
Text Notes 2000 8780 2    50   ~ 0
3.3V
Text Notes 2000 8680 2    50   ~ 0
GND
Text Notes 2000 8570 2    50   ~ 0
5V
Text Notes 2000 8480 2    50   ~ 0
PB9
Text Notes 2000 8380 2    50   ~ 0
PB8
Text Notes 2000 8280 2    50   ~ 0
PB7
Text Notes 2000 8180 2    50   ~ 0
PB6
Text Notes 2000 8080 2    50   ~ 0
PB5
Text Notes 2000 7980 2    50   ~ 0
PB4
Text Notes 2000 7880 2    50   ~ 0
PB3
Text Notes 2000 7780 2    50   ~ 0
PA15
Text Notes 2000 7680 2    50   ~ 0
PA12
Text Notes 2000 7580 2    50   ~ 0
PA11
Text Notes 2000 7480 2    50   ~ 0
PA10
Text Notes 2000 7380 2    50   ~ 0
PA9
Text Notes 2000 7280 2    50   ~ 0
PA8
Text Notes 2000 7180 2    50   ~ 0
PB15
Text Notes 2000 7080 2    50   ~ 0
PB14
Text Notes 2000 6980 2    50   ~ 0
PB13
Text Notes 2000 6880 2    50   ~ 0
PB12
$Comp
L power:GND #PWR?
U 1 1 5E8885AE
P 1050 6950
F 0 "#PWR?" H 1050 6700 50  0001 C CNN
F 1 "GND" H 1055 6777 50  0000 C CNN
F 2 "" H 1050 6950 50  0001 C CNN
F 3 "" H 1050 6950 50  0001 C CNN
	1    1050 6950
	0    1    1    0   
$EndComp
Wire Wire Line
	1050 6950 1300 6950
$Comp
L power:GND #PWR?
U 1 1 5E88D8BA
P 2450 8650
F 0 "#PWR?" H 2450 8400 50  0001 C CNN
F 1 "GND" H 2455 8477 50  0000 C CNN
F 2 "" H 2450 8650 50  0001 C CNN
F 3 "" H 2450 8650 50  0001 C CNN
	1    2450 8650
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2450 8650 2200 8650
Wire Wire Line
	1200 6850 1300 6850
$Comp
L power:+5V #PWR?
U 1 1 5E8936A3
P 1200 6850
F 0 "#PWR?" H 1200 6700 50  0001 C CNN
F 1 "+5V" H 1215 7023 50  0000 C CNN
F 2 "" H 1200 6850 50  0001 C CNN
F 3 "" H 1200 6850 50  0001 C CNN
	1    1200 6850
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2300 8550 2200 8550
$Comp
L power:+5V #PWR?
U 1 1 5E89A2B8
P 2300 8550
F 0 "#PWR?" H 2300 8400 50  0001 C CNN
F 1 "+5V" H 2315 8723 50  0000 C CNN
F 2 "" H 2300 8550 50  0001 C CNN
F 3 "" H 2300 8550 50  0001 C CNN
	1    2300 8550
	0    1    1    0   
$EndComp
NoConn ~ 1300 8550
NoConn ~ 1300 8450
NoConn ~ 1300 8250
$Comp
L Connector:Conn_01x06_Female J?
U 1 1 5E8C251C
P 1750 5850
F 0 "J?" H 1700 6150 50  0000 L CNN
F 1 "Conn_01x06_Female" H 1778 5735 50  0001 L CNN
F 2 "" H 1750 5850 50  0001 C CNN
F 3 "~" H 1750 5850 50  0001 C CNN
F 4 "INMP441 module" H 1850 5450 50  0000 C CNN "Ref"
	1    1750 5850
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5E8CBC3A
P 1300 5950
F 0 "#PWR?" H 1300 5700 50  0001 C CNN
F 1 "GND" H 1305 5777 50  0000 C CNN
F 2 "" H 1300 5950 50  0001 C CNN
F 3 "" H 1300 5950 50  0001 C CNN
	1    1300 5950
	0    1    1    0   
$EndComp
Wire Wire Line
	1300 5950 1550 5950
Text Label 1550 6150 2    50   ~ 0
I2Sb_CK
$Comp
L power:+3.3V #PWR?
U 1 1 5E8DADE0
P 1500 5750
F 0 "#PWR?" H 1500 5600 50  0001 C CNN
F 1 "+3.3V" V 1515 5878 50  0000 L CNN
F 2 "" H 1500 5750 50  0001 C CNN
F 3 "" H 1500 5750 50  0001 C CNN
	1    1500 5750
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1500 5750 1550 5750
Text Notes 1750 5850 0    50   ~ 0
SD_DATA
Text Notes 1750 5950 0    50   ~ 0
LR
Text Notes 1750 6050 0    50   ~ 0
WS_L/R
Text Notes 1750 6150 0    50   ~ 0
SCK_CLK
$Comp
L power:GND #PWR?
U 1 1 5E8FFE74
P 1300 5650
F 0 "#PWR?" H 1300 5400 50  0001 C CNN
F 1 "GND" H 1305 5477 50  0000 C CNN
F 2 "" H 1300 5650 50  0001 C CNN
F 3 "" H 1300 5650 50  0001 C CNN
	1    1300 5650
	0    1    1    0   
$EndComp
Wire Wire Line
	1300 5650 1550 5650
Text Label 1550 6050 2    50   ~ 0
I2Sb_WS
Wire Wire Line
	1400 4250 1500 4250
$Comp
L power:+5V #PWR?
U 1 1 5E927384
P 1400 4250
F 0 "#PWR?" H 1400 4100 50  0001 C CNN
F 1 "+5V" H 1415 4423 50  0000 C CNN
F 2 "" H 1400 4250 50  0001 C CNN
F 3 "" H 1400 4250 50  0001 C CNN
	1    1400 4250
	0    -1   -1   0   
$EndComp
Text Notes 1700 3850 0    50   ~ 0
BCK
Text Notes 1700 4050 0    50   ~ 0
DIN
Text Notes 1700 3950 0    50   ~ 0
LCK
Text Notes 1700 3750 0    50   ~ 0
SCK
Text Label 1550 5850 2    50   ~ 0
I2Sb_SD
$Comp
L power:GND #PWR?
U 1 1 5E973E96
P 1250 3750
F 0 "#PWR?" H 1250 3500 50  0001 C CNN
F 1 "GND" H 1255 3577 50  0000 C CNN
F 2 "" H 1250 3750 50  0001 C CNN
F 3 "" H 1250 3750 50  0001 C CNN
	1    1250 3750
	0    1    1    0   
$EndComp
Wire Wire Line
	1250 3750 1500 3750
Text Label 2200 8350 0    50   ~ 0
SCL_0
Text Label 2200 8450 0    50   ~ 0
SDA_0
Text Label 1300 7850 2    50   ~ 0
SS_AD9833
Text Label 1300 7750 2    50   ~ 0
SCLK_0
Text Label 1300 7550 2    50   ~ 0
MOSI_0
Text Label 2200 8250 0    50   ~ 0
USART1_RX
Text Label 2200 7350 0    50   ~ 0
USART1_TX
Text Label 1300 8650 2    50   ~ 0
LED
Text Label 1300 7150 2    50   ~ 0
I2Sa_CK
Text Label 2200 6850 0    50   ~ 0
I2Sa_WS
Text Label 2200 7150 0    50   ~ 0
I2Sa_SD
Text Label 2200 7850 0    50   ~ 0
I2Sb_CK
Text Label 2200 7750 0    50   ~ 0
I2Sb_WS
Text Label 2200 8050 0    50   ~ 0
I2Sb_SD
Text Label 2200 7450 0    50   ~ 0
SPI5_MOSI
Text Label 1300 7450 2    50   ~ 0
SPI5_SCK
Text Label 1300 7350 2    50   ~ 0
SPI5_NSS
$Comp
L Connector:Conn_01x08_Female J?
U 1 1 5EA0DFA0
P 3700 7500
F 0 "J?" H 3650 7900 50  0000 L CNN
F 1 "Conn_01x08_Female" H 3728 7385 50  0001 L CNN
F 2 "" H 3700 7500 50  0001 C CNN
F 3 "~" H 3700 7500 50  0001 C CNN
F 4 "Nokia 5110" H 3850 7000 50  0000 C CNN "Ref"
	1    3700 7500
	1    0    0    -1  
$EndComp
Text Notes 3700 7200 0    50   ~ 0
RST
Text Notes 3700 7300 0    50   ~ 0
CE
Text Notes 3700 7400 0    50   ~ 0
DC
Text Notes 3700 7500 0    50   ~ 0
DIN
Text Notes 3700 7600 0    50   ~ 0
CLK
Text Notes 3700 7700 0    50   ~ 0
VCC
Text Notes 3700 7800 0    50   ~ 0
LIGHT
Text Notes 3700 7900 0    50   ~ 0
GND
Text Label 3500 7500 2    50   ~ 0
SPI5_MOSI
Text Label 3500 7600 2    50   ~ 0
SPI5_SCK
Text Label 3500 7300 2    50   ~ 0
SPI5_NSS
Text Label 2200 7250 0    50   ~ 0
I2C3_SCL
Text Label 2200 7950 0    50   ~ 0
I2C3_SDA
Text Label 1300 8050 2    50   ~ 0
USART2_TX
Text Label 1300 7950 2    50   ~ 0
USART2_RX
Text Label 3500 7200 2    50   ~ 0
Nokia_RST
Text Label 3500 7400 2    50   ~ 0
Nokia_DC
Text Label 3500 7800 2    50   ~ 0
Nokia_Light
Text Label 1300 8150 2    50   ~ 0
FBBFin
Text Label 1300 7650 2    50   ~ 0
FBBFout
$Comp
L power:GND #PWR?
U 1 1 5EA53416
P 3250 7900
F 0 "#PWR?" H 3250 7650 50  0001 C CNN
F 1 "GND" H 3255 7727 50  0000 C CNN
F 2 "" H 3250 7900 50  0001 C CNN
F 3 "" H 3250 7900 50  0001 C CNN
	1    3250 7900
	0    1    1    0   
$EndComp
Wire Wire Line
	3250 7900 3500 7900
$Comp
L power:+3.3V #PWR?
U 1 1 5EA5B51F
P 3450 7700
F 0 "#PWR?" H 3450 7550 50  0001 C CNN
F 1 "+3.3V" V 3465 7828 50  0000 L CNN
F 2 "" H 3450 7700 50  0001 C CNN
F 3 "" H 3450 7700 50  0001 C CNN
	1    3450 7700
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3450 7700 3500 7700
$EndSCHEMATC
