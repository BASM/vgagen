EESchema Schematic File Version 2  date Чт. 09 мая 2013 00:07:53
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:special
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:vga
LIBS:vga-conn-cache
EELAYER 25  0
EELAYER END
$Descr A4 11700 8267
encoding utf-8
Sheet 1 1
Title ""
Date "8 may 2013"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Label 6950 4600 0    60   ~ 0
SCL
Text Label 6950 4800 0    60   ~ 0
SDA
Wire Wire Line
	6800 4500 6800 4000
Wire Wire Line
	6800 4500 7250 4500
Wire Wire Line
	7250 4500 7250 4600
Wire Wire Line
	6800 4950 6800 4800
Wire Wire Line
	6800 4800 6700 4800
Wire Wire Line
	8100 5050 8050 5050
Wire Wire Line
	8050 5050 8050 5150
Connection ~ 5400 4900
Wire Wire Line
	5500 4900 5400 4900
Connection ~ 5400 4500
Wire Wire Line
	5500 4500 5400 4500
Connection ~ 5400 4100
Wire Wire Line
	5500 4100 5400 4100
Wire Wire Line
	7300 4400 6700 4400
Wire Wire Line
	5500 4400 4900 4400
Wire Wire Line
	4900 4400 4900 4500
Wire Wire Line
	4900 4500 4300 4500
Wire Wire Line
	5500 4600 4300 4600
Wire Wire Line
	5500 4800 4900 4800
Wire Wire Line
	4900 4800 4900 4700
Wire Wire Line
	4900 4700 4300 4700
Wire Wire Line
	7300 4200 6700 4200
Wire Wire Line
	5400 5000 5400 4000
Wire Wire Line
	5400 4000 5500 4000
Wire Wire Line
	5500 4300 5400 4300
Connection ~ 5400 4300
Wire Wire Line
	5500 4700 5400 4700
Connection ~ 5400 4700
Wire Wire Line
	6800 4000 6700 4000
Wire Wire Line
	5100 2900 5100 3000
Wire Wire Line
	7250 4800 6950 4800
Wire Wire Line
	6950 4800 6950 4600
Wire Wire Line
	6950 4600 6700 4600
$Comp
L CONN_2 P3
U 1 1 518A92D2
P 7600 4700
F 0 "P3" V 7550 4700 40  0000 C CNN
F 1 "I2C" V 7650 4700 40  0000 C CNN
	1    7600 4700
	1    0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG1
U 1 1 518A902F
P 5100 2900
F 0 "#FLG1" H 5100 2995 30  0001 C CNN
F 1 "PWR_FLAG" H 5100 3080 30  0000 C CNN
	1    5100 2900
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR1
U 1 1 518A8FFF
P 5100 3000
F 0 "#PWR1" H 5100 3000 30  0001 C CNN
F 1 "GND" H 5100 2930 30  0001 C CNN
	1    5100 3000
	1    0    0    -1  
$EndComp
Text Label 6900 4400 0    60   ~ 0
H-SYNC
Text Label 6900 4150 0    60   ~ 0
V-SYNC
Text Label 4350 4500 0    60   ~ 0
BLUE
Text Label 4350 4600 0    60   ~ 0
GREEN
Text Label 4350 4700 0    60   ~ 0
RED
$Comp
L GND #PWR2
U 1 1 518A8F79
P 5400 5000
F 0 "#PWR2" H 5400 5000 30  0001 C CNN
F 1 "GND" H 5400 4930 30  0001 C CNN
	1    5400 5000
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR3
U 1 1 518A8F75
P 6800 4950
F 0 "#PWR3" H 6800 4950 30  0001 C CNN
F 1 "GND" H 6800 4880 30  0001 C CNN
	1    6800 4950
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR4
U 1 1 518A8FF5
P 8050 5150
F 0 "#PWR4" H 8050 5150 30  0001 C CNN
F 1 "GND" H 8050 5080 30  0001 C CNN
	1    8050 5150
	1    0    0    -1  
$EndComp
$Comp
L CONN_1 P1
U 1 1 518A8FF6
P 8250 5050
F 0 "P1" H 8330 5050 40  0000 L CNN
F 1 "GND" H 8250 5105 30  0001 C CNN
	1    8250 5050
	1    0    0    -1  
$EndComp
$Comp
L CONN_2 P2
U 1 1 518A8FF7
P 7650 4300
F 0 "P2" V 7600 4300 40  0000 C CNN
F 1 "HV-SYNC" V 7700 4300 40  0000 C CNN
	1    7650 4300
	1    0    0    -1  
$EndComp
NoConn ~ 5500 4200
$Comp
L CONN_3 K1
U 1 1 518A8FF8
P 3950 4600
F 0 "K1" V 3900 4600 50  0000 C CNN
F 1 "RGB" V 4000 4600 40  0000 C CNN
	1    3950 4600
	-1   0    0    1   
$EndComp
$Comp
L VGA J1
U 1 1 00000000
P 6100 4450
F 0 "J1" H 5850 5250 60  0000 C CNN
F 1 "VGA" H 6100 3700 60  0000 C CNN
	1    6100 4450
	1    0    0    -1  
$EndComp
$EndSCHEMATC
