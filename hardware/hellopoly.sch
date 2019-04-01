EESchema Schematic File Version 4
LIBS:hellopoly-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Hello Poly"
Date ""
Rev "1"
Comp "Savage Company"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Modules:Bluepill U1
U 1 1 5C9F8805
P 2100 4350
F 0 "U1" H 2100 4475 50  0000 C CNN
F 1 "Bluepill" H 2100 4384 50  0000 C CNN
F 2 "Module:Maple_Mini" H 2100 4400 50  0001 C CNN
F 3 "" H 2100 4400 50  0001 C CNN
	1    2100 4350
	1    0    0    -1  
$EndComp
$Comp
L Regulator_Linear:L7805 U2
U 1 1 5C9F90CD
P 2150 2050
F 0 "U2" H 2150 2292 50  0000 C CNN
F 1 "L7805" H 2150 2201 50  0000 C CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 2175 1900 50  0001 L CIN
F 3 "http://www.st.com/content/ccc/resource/technical/document/datasheet/41/4f/b3/b0/12/d4/47/88/CD00000444.pdf/files/CD00000444.pdf/jcr:content/translations/en.CD00000444.pdf" H 2150 2000 50  0001 C CNN
	1    2150 2050
	1    0    0    -1  
$EndComp
$Comp
L Isolator:6N138 U3
U 1 1 5C9F9C53
P 2300 3350
F 0 "U3" H 2300 3817 50  0000 C CNN
F 1 "6N138" H 2300 3726 50  0000 C CNN
F 2 "Package_DIP:DIP-8_W7.62mm" H 2590 3050 50  0001 C CNN
F 3 "http://www.onsemi.com/pub/Collateral/HCPL2731-D.pdf" H 2590 3050 50  0001 C CNN
	1    2300 3350
	1    0    0    -1  
$EndComp
Text GLabel 2600 5050 2    50   BiDi ~ 0
I2C1_SDA
Text GLabel 2600 5150 2    50   BiDi ~ 0
I2C1_SCL
Text GLabel 2600 5850 2    50   Output ~ 0
UART_TX
Text GLabel 2600 5750 2    50   Input ~ 0
UART_RX
$Comp
L power:+5V #PWR08
U 1 1 5C9F9D21
P 2700 4350
F 0 "#PWR08" H 2700 4200 50  0001 C CNN
F 1 "+5V" H 2700 4500 50  0000 C CNN
F 2 "" H 2700 4350 50  0001 C CNN
F 3 "" H 2700 4350 50  0001 C CNN
	1    2700 4350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR010
U 1 1 5C9F9D5F
P 2900 4650
F 0 "#PWR010" H 2900 4400 50  0001 C CNN
F 1 "GND" H 2905 4477 50  0000 C CNN
F 2 "" H 2900 4650 50  0001 C CNN
F 3 "" H 2900 4650 50  0001 C CNN
	1    2900 4650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR03
U 1 1 5C9F9DAE
P 1400 6450
F 0 "#PWR03" H 1400 6200 50  0001 C CNN
F 1 "GND" H 1405 6277 50  0000 C CNN
F 2 "" H 1400 6450 50  0001 C CNN
F 3 "" H 1400 6450 50  0001 C CNN
	1    1400 6450
	1    0    0    -1  
$EndComp
Wire Wire Line
	1600 6250 1400 6250
Wire Wire Line
	1400 6250 1400 6350
Wire Wire Line
	1600 6350 1400 6350
Connection ~ 1400 6350
Wire Wire Line
	1400 6350 1400 6450
Text GLabel 1600 5550 0    50   Output ~ 0
SPI1_MOSI
Text GLabel 1600 5350 0    50   Output ~ 0
SPI1_SCK
Text GLabel 1600 5050 0    50   Output ~ 0
DACA_CS
Text GLabel 1600 5150 0    50   Output ~ 0
DACB_CS
Text GLabel 1600 5250 0    50   Output ~ 0
DACC_CS
Text GLabel 1600 5950 0    50   Input ~ 0
MIDI_RX
NoConn ~ 1600 4750
NoConn ~ 1600 4650
NoConn ~ 1600 4550
NoConn ~ 1600 4450
NoConn ~ 2600 4450
NoConn ~ 1600 6150
NoConn ~ 1600 6050
Text GLabel 2600 6050 2    50   Output ~ 0
GATE4
Text GLabel 2600 6150 2    50   Output ~ 0
GATE3
Text GLabel 2600 6250 2    50   Output ~ 0
GATE2
Text GLabel 2600 6350 2    50   Output ~ 0
GATE1
$Comp
L Device:CP C7
U 1 1 5CA09877
P 2650 2200
F 0 "C7" H 2768 2246 50  0000 L CNN
F 1 "47uF" H 2768 2155 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D5.0mm_P2.50mm" H 2688 2050 50  0001 C CNN
F 3 "~" H 2650 2200 50  0001 C CNN
	1    2650 2200
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1
U 1 1 5CA098E7
P 1250 2200
F 0 "C1" H 1365 2246 50  0000 L CNN
F 1 "0.1uF" H 1365 2155 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D5.0mm_W2.5mm_P2.50mm" H 1288 2050 50  0001 C CNN
F 3 "~" H 1250 2200 50  0001 C CNN
	1    1250 2200
	1    0    0    -1  
$EndComp
$Comp
L Device:C C8
U 1 1 5CA099AF
P 3050 2200
F 0 "C8" H 3165 2246 50  0000 L CNN
F 1 "0.1uF" H 3165 2155 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D5.0mm_W2.5mm_P2.50mm" H 3088 2050 50  0001 C CNN
F 3 "~" H 3050 2200 50  0001 C CNN
	1    3050 2200
	1    0    0    -1  
$EndComp
$Comp
L Device:C C11
U 1 1 5CA09A3A
P 3450 2200
F 0 "C11" H 3565 2246 50  0000 L CNN
F 1 "0.1uF" H 3565 2155 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D5.0mm_W2.5mm_P2.50mm" H 3488 2050 50  0001 C CNN
F 3 "~" H 3450 2200 50  0001 C CNN
	1    3450 2200
	1    0    0    -1  
$EndComp
$Comp
L Device:C C12
U 1 1 5CA09AAE
P 3850 2200
F 0 "C12" H 3965 2246 50  0000 L CNN
F 1 "0.1uF" H 3965 2155 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D5.0mm_W2.5mm_P2.50mm" H 3888 2050 50  0001 C CNN
F 3 "~" H 3850 2200 50  0001 C CNN
	1    3850 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	2150 2350 2650 2350
Connection ~ 2150 2350
Wire Wire Line
	2650 2350 3050 2350
Connection ~ 2650 2350
Wire Wire Line
	3050 2350 3450 2350
Connection ~ 3050 2350
Wire Wire Line
	3450 2350 3850 2350
Connection ~ 3450 2350
Wire Wire Line
	2450 2050 2650 2050
Wire Wire Line
	2650 2050 3050 2050
Connection ~ 2650 2050
Wire Wire Line
	3050 2050 3450 2050
Connection ~ 3050 2050
Wire Wire Line
	3450 2050 3850 2050
Connection ~ 3450 2050
$Comp
L power:GND #PWR07
U 1 1 5CA0AA1B
P 2150 2350
F 0 "#PWR07" H 2150 2100 50  0001 C CNN
F 1 "GND" H 2155 2177 50  0000 C CNN
F 2 "" H 2150 2350 50  0001 C CNN
F 3 "" H 2150 2350 50  0001 C CNN
	1    2150 2350
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR011
U 1 1 5CA0AA5F
P 3850 2050
F 0 "#PWR011" H 3850 1900 50  0001 C CNN
F 1 "+5V" H 3865 2223 50  0000 C CNN
F 2 "" H 3850 2050 50  0001 C CNN
F 3 "" H 3850 2050 50  0001 C CNN
	1    3850 2050
	1    0    0    -1  
$EndComp
Connection ~ 3850 2050
$Comp
L power:+12V #PWR02
U 1 1 5CA0AAB5
P 1250 2050
F 0 "#PWR02" H 1250 1900 50  0001 C CNN
F 1 "+12V" H 1265 2223 50  0000 C CNN
F 2 "" H 1250 2050 50  0001 C CNN
F 3 "" H 1250 2050 50  0001 C CNN
	1    1250 2050
	1    0    0    -1  
$EndComp
Connection ~ 1250 2050
$Comp
L Analog_DAC:MCP4822 U7
U 1 1 5CA0AFA9
P 8500 1850
F 0 "U7" H 8150 2200 50  0000 C CNN
F 1 "MCP4822" H 8700 1400 50  0000 C CNN
F 2 "Package_DIP:DIP-8_W7.62mm" H 9300 1550 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/20002249B.pdf" H 9300 1550 50  0001 C CNN
	1    8500 1850
	1    0    0    -1  
$EndComp
Text GLabel 8000 1750 0    50   Input ~ 0
SPI1_SCK
Text GLabel 8000 2050 0    50   Input ~ 0
DACA_CS
Text GLabel 8000 1950 0    50   Input ~ 0
SPI1_MOSI
$Comp
L power:+5V #PWR015
U 1 1 5CA0C270
P 8500 1450
F 0 "#PWR015" H 8500 1300 50  0001 C CNN
F 1 "+5V" H 8515 1623 50  0000 C CNN
F 2 "" H 8500 1450 50  0001 C CNN
F 3 "" H 8500 1450 50  0001 C CNN
	1    8500 1450
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR016
U 1 1 5CA0C4BB
P 8500 2350
F 0 "#PWR016" H 8500 2100 50  0001 C CNN
F 1 "GND" H 8505 2177 50  0000 C CNN
F 2 "" H 8500 2350 50  0001 C CNN
F 3 "" H 8500 2350 50  0001 C CNN
	1    8500 2350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR012
U 1 1 5CA0C4FD
P 7400 1950
F 0 "#PWR012" H 7400 1700 50  0001 C CNN
F 1 "GND" H 7405 1777 50  0000 C CNN
F 2 "" H 7400 1950 50  0001 C CNN
F 3 "" H 7400 1950 50  0001 C CNN
	1    7400 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	8000 1850 7400 1850
Wire Wire Line
	7400 1850 7400 1950
$Comp
L Device:R R2
U 1 1 5CA0F7B0
P 2700 3400
F 0 "R2" H 2770 3446 50  0000 L CNN
F 1 "10K" H 2770 3355 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 2630 3400 50  0001 C CNN
F 3 "~" H 2700 3400 50  0001 C CNN
	1    2700 3400
	1    0    0    -1  
$EndComp
$Comp
L Device:R R3
U 1 1 5CA0F834
P 3000 3300
F 0 "R3" H 3070 3346 50  0000 L CNN
F 1 "470K" H 3070 3255 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 2930 3300 50  0001 C CNN
F 3 "~" H 3000 3300 50  0001 C CNN
	1    3000 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	2600 3450 3000 3450
Wire Wire Line
	2600 3150 3000 3150
Wire Wire Line
	2600 3250 2700 3250
$Comp
L Device:D D1
U 1 1 5CA10725
P 1800 3350
F 0 "D1" V 1754 3429 50  0000 L CNN
F 1 "1N4148" V 1845 3429 50  0000 L CNN
F 2 "Diode_THT:D_A-405_P7.62mm_Horizontal" H 1800 3350 50  0001 C CNN
F 3 "~" H 1800 3350 50  0001 C CNN
	1    1800 3350
	0    1    1    0   
$EndComp
Wire Wire Line
	2000 3250 2000 3200
Wire Wire Line
	2000 3200 1800 3200
Wire Wire Line
	1800 3500 2000 3500
Wire Wire Line
	2000 3500 2000 3450
$Comp
L Device:R R1
U 1 1 5CA1121F
P 1500 3050
F 0 "R1" V 1293 3050 50  0000 C CNN
F 1 "220R" V 1384 3050 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 1430 3050 50  0001 C CNN
F 3 "~" H 1500 3050 50  0001 C CNN
	1    1500 3050
	0    1    1    0   
$EndComp
$Comp
L power:+5V #PWR09
U 1 1 5CA11812
P 3000 3150
F 0 "#PWR09" H 3000 3000 50  0001 C CNN
F 1 "+5V" H 3015 3323 50  0000 C CNN
F 2 "" H 3000 3150 50  0001 C CNN
F 3 "" H 3000 3150 50  0001 C CNN
	1    3000 3150
	1    0    0    -1  
$EndComp
Text GLabel 3150 3450 2    50   Output ~ 0
MIDI_RX
Wire Wire Line
	2700 3550 2600 3550
Connection ~ 3000 3150
Wire Wire Line
	3000 3450 3150 3450
Connection ~ 3000 3450
$Comp
L Connector:DIN-5_180degree J1
U 1 1 5CA138AB
P 1100 3350
F 0 "J1" V 1054 3120 50  0000 R CNN
F 1 "MIDI" V 1145 3120 50  0000 R CNN
F 2 "" H 1100 3350 50  0001 C CNN
F 3 "http://www.mouser.com/ds/2/18/40_c091_abd_e-75918.pdf" H 1100 3350 50  0001 C CNN
	1    1100 3350
	0    1    1    0   
$EndComp
Wire Wire Line
	1800 3500 1800 3650
Wire Wire Line
	1800 3650 1200 3650
Connection ~ 1800 3500
Wire Wire Line
	1800 3200 1800 3050
Connection ~ 1800 3200
$Comp
L power:GND #PWR04
U 1 1 5CA173E8
P 1500 3350
F 0 "#PWR04" H 1500 3100 50  0001 C CNN
F 1 "GND" H 1505 3177 50  0000 C CNN
F 2 "" H 1500 3350 50  0001 C CNN
F 3 "" H 1500 3350 50  0001 C CNN
	1    1500 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	1500 3350 1400 3350
$Comp
L Connector_Generic:Conn_02x05_Odd_Even J2
U 1 1 5CA1D20E
P 1250 1200
F 0 "J2" H 1300 775 50  0000 C CNN
F 1 "Power BUS" H 1300 866 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x05_P2.54mm_Vertical" H 1250 1200 50  0001 C CNN
F 3 "~" H 1250 1200 50  0001 C CNN
	1    1250 1200
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR01
U 1 1 5CA1D3C7
P 750 1200
F 0 "#PWR01" H 750 950 50  0001 C CNN
F 1 "GND" H 755 1027 50  0000 C CNN
F 2 "" H 750 1200 50  0001 C CNN
F 3 "" H 750 1200 50  0001 C CNN
	1    750  1200
	1    0    0    -1  
$EndComp
Wire Wire Line
	950  1000 950  900 
Wire Wire Line
	950  900  1450 900 
Wire Wire Line
	1450 900  1450 1000
Wire Wire Line
	950  1400 950  1500
Wire Wire Line
	950  1500 1450 1500
Wire Wire Line
	1450 1500 1450 1400
Wire Wire Line
	1450 1100 1450 1200
Wire Wire Line
	1450 1300 1450 1200
Connection ~ 1450 1200
Wire Wire Line
	950  1100 950  1200
Connection ~ 950  1200
Wire Wire Line
	950  1200 950  1300
$Comp
L Device:Polyfuse F2
U 1 1 5CA24D0F
P 1750 1500
F 0 "F2" V 1525 1500 50  0000 C CNN
F 1 "Polyfuse" V 1616 1500 50  0000 C CNN
F 2 "" H 1800 1300 50  0001 L CNN
F 3 "~" H 1750 1500 50  0001 C CNN
	1    1750 1500
	0    1    1    0   
$EndComp
$Comp
L Device:Polyfuse F1
U 1 1 5CA24E1C
P 1750 900
F 0 "F1" V 1525 900 50  0000 C CNN
F 1 "Polyfuse" V 1616 900 50  0000 C CNN
F 2 "" H 1800 700 50  0001 L CNN
F 3 "~" H 1750 900 50  0001 C CNN
	1    1750 900 
	0    1    1    0   
$EndComp
Connection ~ 1450 1500
Connection ~ 1450 900 
$Comp
L Device:CP C3
U 1 1 5CA26A57
P 2050 1050
F 0 "C3" H 1850 1100 50  0000 L CNN
F 1 "47u" H 1800 1000 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D6.3mm_P2.50mm" H 2088 900 50  0001 C CNN
F 3 "~" H 2050 1050 50  0001 C CNN
	1    2050 1050
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C4
U 1 1 5CA26ADB
P 2050 1350
F 0 "C4" H 2168 1396 50  0000 L CNN
F 1 "47u" H 2168 1305 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D6.3mm_P2.50mm" H 2088 1200 50  0001 C CNN
F 3 "~" H 2050 1350 50  0001 C CNN
	1    2050 1350
	1    0    0    -1  
$EndComp
Wire Wire Line
	1450 1500 1600 1500
Wire Wire Line
	1450 900  1600 900 
Wire Wire Line
	1900 900  2050 900 
Wire Wire Line
	2050 1500 1900 1500
Wire Wire Line
	1450 1200 2050 1200
Connection ~ 2050 1200
$Comp
L power:+12V #PWR05
U 1 1 5CA2B68A
P 2050 900
F 0 "#PWR05" H 2050 750 50  0001 C CNN
F 1 "+12V" H 2065 1073 50  0000 C CNN
F 2 "" H 2050 900 50  0001 C CNN
F 3 "" H 2050 900 50  0001 C CNN
	1    2050 900 
	1    0    0    -1  
$EndComp
Connection ~ 2050 900 
$Comp
L power:-12V #PWR06
U 1 1 5CA2B704
P 2050 1500
F 0 "#PWR06" H 2050 1600 50  0001 C CNN
F 1 "-12V" H 2065 1673 50  0000 C CNN
F 2 "" H 2050 1500 50  0001 C CNN
F 3 "" H 2050 1500 50  0001 C CNN
	1    2050 1500
	-1   0    0    1   
$EndComp
Connection ~ 2050 1500
Wire Wire Line
	750  1200 950  1200
Text Notes 600  600  0    50   ~ 0
Power
Wire Notes Line
	600  2750 3600 2750
Wire Notes Line
	3600 2750 3600 3850
Wire Notes Line
	3600 3850 600  3850
Wire Notes Line
	600  3850 600  2750
Text Notes 600  2750 0    50   ~ 0
MIDI
Wire Wire Line
	1200 3050 1350 3050
Wire Wire Line
	1650 3050 1800 3050
$Comp
L Amplifier_Operational:TL072 U4
U 1 1 5CA6C418
P 9900 2150
F 0 "U4" H 9950 2300 50  0000 C CNN
F 1 "TL072" H 9900 2150 50  0000 C CNN
F 2 "Package_DIP:DIP-8_W7.62mm" H 9900 2150 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 9900 2150 50  0001 C CNN
	1    9900 2150
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:TL072 U4
U 2 1 5CA6C4FF
P 9900 1450
F 0 "U4" H 9950 1600 50  0000 C CNN
F 1 "TL072" H 9900 1450 50  0000 C CNN
F 2 "Package_DIP:DIP-8_W7.62mm" H 9900 1450 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 9900 1450 50  0001 C CNN
	2    9900 1450
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:TL072 U4
U 3 1 5CA6C5CB
P 2900 1200
F 0 "U4" H 2858 1246 50  0000 L CNN
F 1 "TL072" H 2858 1155 50  0000 L CNN
F 2 "Package_DIP:DIP-8_W7.62mm" H 2900 1200 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 2900 1200 50  0001 C CNN
	3    2900 1200
	1    0    0    -1  
$EndComp
$Comp
L Device:R_POT_TRIM RV1
U 1 1 5CA6DD97
P 9400 1550
F 0 "RV1" V 9286 1550 50  0000 C CNN
F 1 "10K" V 9400 1550 50  0000 C CNN
F 2 "Potentiometer_THT:Potentiometer_Bourns_3296W_Vertical" H 9400 1550 50  0001 C CNN
F 3 "~" H 9400 1550 50  0001 C CNN
	1    9400 1550
	0    1    1    0   
$EndComp
$Comp
L Device:R R4
U 1 1 5CA6DFA5
P 9950 1700
F 0 "R4" V 10050 1700 50  0000 C CNN
F 1 "10K" V 9950 1700 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 9880 1700 50  0001 C CNN
F 3 "~" H 9950 1700 50  0001 C CNN
	1    9950 1700
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR021
U 1 1 5CA72600
P 9400 1700
F 0 "#PWR021" H 9400 1450 50  0001 C CNN
F 1 "GND" H 9400 1550 50  0000 C CNN
F 2 "" H 9400 1700 50  0001 C CNN
F 3 "" H 9400 1700 50  0001 C CNN
	1    9400 1700
	1    0    0    -1  
$EndComp
$Comp
L Device:R_POT_TRIM RV2
U 1 1 5CA7964C
P 9400 2250
F 0 "RV2" V 9286 2250 50  0000 C CNN
F 1 "10K" V 9400 2250 50  0000 C CNN
F 2 "Potentiometer_THT:Potentiometer_Bourns_3296W_Vertical" H 9400 2250 50  0001 C CNN
F 3 "~" H 9400 2250 50  0001 C CNN
	1    9400 2250
	0    1    1    0   
$EndComp
$Comp
L Device:R R5
U 1 1 5CA796CC
P 9950 2400
F 0 "R5" V 10050 2400 50  0000 C CNN
F 1 "10K" V 9950 2400 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 9880 2400 50  0001 C CNN
F 3 "~" H 9950 2400 50  0001 C CNN
	1    9950 2400
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR022
U 1 1 5CA7E58F
P 9400 2400
F 0 "#PWR022" H 9400 2150 50  0001 C CNN
F 1 "GND" H 9405 2227 50  0000 C CNN
F 2 "" H 9400 2400 50  0001 C CNN
F 3 "" H 9400 2400 50  0001 C CNN
	1    9400 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	9000 2050 9600 2050
Wire Wire Line
	9000 1750 9100 1750
Wire Wire Line
	9100 1750 9100 1350
Wire Wire Line
	9100 1350 9600 1350
$Comp
L Device:C C6
U 1 1 5CA8F77B
P 2600 1350
F 0 "C6" H 2450 1450 50  0000 L CNN
F 1 "0.1uF" H 2300 1350 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D5.0mm_W2.5mm_P2.50mm" H 2638 1200 50  0001 C CNN
F 3 "~" H 2600 1350 50  0001 C CNN
	1    2600 1350
	1    0    0    -1  
$EndComp
$Comp
L Device:C C5
U 1 1 5CA8F841
P 2600 1050
F 0 "C5" H 2400 1100 50  0000 L CNN
F 1 "0.1uF" H 2300 1000 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D5.0mm_W2.5mm_P2.50mm" H 2638 900 50  0001 C CNN
F 3 "~" H 2600 1050 50  0001 C CNN
	1    2600 1050
	1    0    0    -1  
$EndComp
Wire Wire Line
	2600 900  2800 900 
Wire Wire Line
	2800 1500 2600 1500
Text GLabel 10300 1450 2    50   Output ~ 0
DAC1_CV
Text GLabel 10300 2150 2    50   Output ~ 0
DAC2_CV
Wire Wire Line
	10300 1450 10200 1450
Wire Wire Line
	10300 2150 10200 2150
$Comp
L Analog_DAC:MCP4822 U8
U 1 1 5CA9B82A
P 8500 3450
F 0 "U8" H 8150 3800 50  0000 C CNN
F 1 "MCP4822" H 8700 3000 50  0000 C CNN
F 2 "Package_DIP:DIP-8_W7.62mm" H 9300 3150 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/20002249B.pdf" H 9300 3150 50  0001 C CNN
	1    8500 3450
	1    0    0    -1  
$EndComp
Text GLabel 8000 3350 0    50   Input ~ 0
SPI1_SCK
Text GLabel 8000 3650 0    50   Input ~ 0
DACB_CS
Text GLabel 8000 3550 0    50   Input ~ 0
SPI1_MOSI
$Comp
L power:+5V #PWR017
U 1 1 5CA9B834
P 8500 3050
F 0 "#PWR017" H 8500 2900 50  0001 C CNN
F 1 "+5V" H 8515 3223 50  0000 C CNN
F 2 "" H 8500 3050 50  0001 C CNN
F 3 "" H 8500 3050 50  0001 C CNN
	1    8500 3050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR018
U 1 1 5CA9B83A
P 8500 3950
F 0 "#PWR018" H 8500 3700 50  0001 C CNN
F 1 "GND" H 8505 3777 50  0000 C CNN
F 2 "" H 8500 3950 50  0001 C CNN
F 3 "" H 8500 3950 50  0001 C CNN
	1    8500 3950
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR013
U 1 1 5CA9B840
P 7400 3550
F 0 "#PWR013" H 7400 3300 50  0001 C CNN
F 1 "GND" H 7405 3377 50  0000 C CNN
F 2 "" H 7400 3550 50  0001 C CNN
F 3 "" H 7400 3550 50  0001 C CNN
	1    7400 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	8000 3450 7400 3450
Wire Wire Line
	7400 3450 7400 3550
$Comp
L Amplifier_Operational:TL072 U5
U 3 1 5CA9B856
P 3700 1200
F 0 "U5" H 3658 1246 50  0000 L CNN
F 1 "TL072" H 3658 1155 50  0000 L CNN
F 2 "Package_DIP:DIP-8_W7.62mm" H 3700 1200 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 3700 1200 50  0001 C CNN
	3    3700 1200
	1    0    0    -1  
$EndComp
$Comp
L Device:C C10
U 1 1 5CA9B899
P 3400 1350
F 0 "C10" H 3250 1450 50  0000 L CNN
F 1 "0.1uF" H 3100 1350 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D5.0mm_W2.5mm_P2.50mm" H 3438 1200 50  0001 C CNN
F 3 "~" H 3400 1350 50  0001 C CNN
	1    3400 1350
	1    0    0    -1  
$EndComp
$Comp
L Device:C C9
U 1 1 5CA9B8A0
P 3400 1050
F 0 "C9" H 3250 1150 50  0000 L CNN
F 1 "0.1uF" H 3100 1050 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D5.0mm_W2.5mm_P2.50mm" H 3438 900 50  0001 C CNN
F 3 "~" H 3400 1050 50  0001 C CNN
	1    3400 1050
	1    0    0    -1  
$EndComp
Wire Wire Line
	3400 900  3600 900 
Wire Wire Line
	3600 1500 3400 1500
Text GLabel 10300 3050 2    50   Output ~ 0
DAC3_CV
Text GLabel 10300 3750 2    50   Output ~ 0
DAC4_CV
$Comp
L Analog_DAC:MCP4822 U9
U 1 1 5CA9E67C
P 8500 5050
F 0 "U9" H 8150 5400 50  0000 C CNN
F 1 "MCP4822" H 8700 4600 50  0000 C CNN
F 2 "Package_DIP:DIP-8_W7.62mm" H 9300 4750 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/20002249B.pdf" H 9300 4750 50  0001 C CNN
	1    8500 5050
	1    0    0    -1  
$EndComp
Text GLabel 8000 4950 0    50   Input ~ 0
SPI1_SCK
Text GLabel 8000 5250 0    50   Input ~ 0
DACC_CS
Text GLabel 8000 5150 0    50   Input ~ 0
SPI1_MOSI
$Comp
L power:+5V #PWR019
U 1 1 5CA9E686
P 8500 4650
F 0 "#PWR019" H 8500 4500 50  0001 C CNN
F 1 "+5V" H 8515 4823 50  0000 C CNN
F 2 "" H 8500 4650 50  0001 C CNN
F 3 "" H 8500 4650 50  0001 C CNN
	1    8500 4650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR020
U 1 1 5CA9E68C
P 8500 5550
F 0 "#PWR020" H 8500 5300 50  0001 C CNN
F 1 "GND" H 8505 5377 50  0000 C CNN
F 2 "" H 8500 5550 50  0001 C CNN
F 3 "" H 8500 5550 50  0001 C CNN
	1    8500 5550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR014
U 1 1 5CA9E692
P 7400 5150
F 0 "#PWR014" H 7400 4900 50  0001 C CNN
F 1 "GND" H 7405 4977 50  0000 C CNN
F 2 "" H 7400 5150 50  0001 C CNN
F 3 "" H 7400 5150 50  0001 C CNN
	1    7400 5150
	1    0    0    -1  
$EndComp
Wire Wire Line
	8000 5050 7400 5050
Wire Wire Line
	7400 5050 7400 5150
$Comp
L Amplifier_Operational:TL072 U6
U 3 1 5CA9E6A8
P 4500 1200
F 0 "U6" H 4458 1246 50  0000 L CNN
F 1 "TL072" H 4458 1155 50  0000 L CNN
F 2 "Package_DIP:DIP-8_W7.62mm" H 4500 1200 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 4500 1200 50  0001 C CNN
	3    4500 1200
	1    0    0    -1  
$EndComp
$Comp
L Device:C C14
U 1 1 5CA9E6EB
P 4200 1350
F 0 "C14" H 4050 1450 50  0000 L CNN
F 1 "0.1uF" H 3900 1350 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D5.0mm_W2.5mm_P2.50mm" H 4238 1200 50  0001 C CNN
F 3 "~" H 4200 1350 50  0001 C CNN
	1    4200 1350
	1    0    0    -1  
$EndComp
$Comp
L Device:C C13
U 1 1 5CA9E6F2
P 4200 1050
F 0 "C13" H 4050 1150 50  0000 L CNN
F 1 "0.1uF" H 3900 1050 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D5.0mm_W2.5mm_P2.50mm" H 4238 900 50  0001 C CNN
F 3 "~" H 4200 1050 50  0001 C CNN
	1    4200 1050
	1    0    0    -1  
$EndComp
Wire Wire Line
	4200 900  4400 900 
Wire Wire Line
	4400 1500 4200 1500
Text GLabel 10300 4650 2    50   Output ~ 0
DAC5_CV
Text GLabel 10300 5350 2    50   Output ~ 0
DAC6_CV
Wire Wire Line
	2050 900  2600 900 
Connection ~ 2600 900 
Wire Wire Line
	2800 900  3400 900 
Connection ~ 2800 900 
Connection ~ 3400 900 
Wire Wire Line
	3600 900  4200 900 
Connection ~ 3600 900 
Connection ~ 4200 900 
Wire Wire Line
	4200 1500 3600 1500
Connection ~ 4200 1500
Connection ~ 3600 1500
Wire Wire Line
	3400 1500 2800 1500
Connection ~ 3400 1500
Connection ~ 2800 1500
Wire Wire Line
	2600 1500 2050 1500
Connection ~ 2600 1500
Wire Notes Line
	600  2600 4750 2600
Wire Notes Line
	600  600  4750 600 
Wire Notes Line
	4750 600  4750 2600
Wire Notes Line
	600  600  600  2600
Wire Wire Line
	9250 1700 9250 1550
Wire Wire Line
	9400 1700 9250 1700
Wire Wire Line
	9600 1700 9800 1700
Wire Wire Line
	9600 1550 9600 1700
Wire Wire Line
	10100 1700 10200 1700
Wire Wire Line
	10200 1700 10200 1450
Connection ~ 10200 1450
Wire Wire Line
	9550 1550 9600 1550
Connection ~ 9600 1550
Connection ~ 9400 1700
Wire Wire Line
	9550 2250 9600 2250
Wire Wire Line
	9250 2250 9250 2400
Wire Wire Line
	9250 2400 9400 2400
Connection ~ 9400 2400
Wire Wire Line
	10100 2400 10200 2400
Wire Wire Line
	10200 2400 10200 2150
Connection ~ 10200 2150
Wire Wire Line
	9800 2400 9600 2400
Wire Wire Line
	9600 2400 9600 2250
Connection ~ 9600 2250
$Comp
L Amplifier_Operational:TL072 U5
U 1 1 5CA5BE3F
P 9900 3750
F 0 "U5" H 9950 3900 50  0000 C CNN
F 1 "TL072" H 9900 3750 50  0000 C CNN
F 2 "Package_DIP:DIP-8_W7.62mm" H 9900 3750 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 9900 3750 50  0001 C CNN
	1    9900 3750
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:TL072 U5
U 2 1 5CA5BE46
P 9900 3050
F 0 "U5" H 9950 3200 50  0000 C CNN
F 1 "TL072" H 9900 3050 50  0000 C CNN
F 2 "Package_DIP:DIP-8_W7.62mm" H 9900 3050 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 9900 3050 50  0001 C CNN
	2    9900 3050
	1    0    0    -1  
$EndComp
$Comp
L Device:R_POT_TRIM RV3
U 1 1 5CA5BE4D
P 9400 3150
F 0 "RV3" V 9286 3150 50  0000 C CNN
F 1 "10K" V 9400 3150 50  0000 C CNN
F 2 "Potentiometer_THT:Potentiometer_Bourns_3296W_Vertical" H 9400 3150 50  0001 C CNN
F 3 "~" H 9400 3150 50  0001 C CNN
	1    9400 3150
	0    1    1    0   
$EndComp
$Comp
L Device:R R6
U 1 1 5CA5BE54
P 9950 3300
F 0 "R6" V 10050 3300 50  0000 C CNN
F 1 "10K" V 9950 3300 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 9880 3300 50  0001 C CNN
F 3 "~" H 9950 3300 50  0001 C CNN
	1    9950 3300
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR023
U 1 1 5CA5BE5B
P 9400 3300
F 0 "#PWR023" H 9400 3050 50  0001 C CNN
F 1 "GND" H 9400 3150 50  0000 C CNN
F 2 "" H 9400 3300 50  0001 C CNN
F 3 "" H 9400 3300 50  0001 C CNN
	1    9400 3300
	1    0    0    -1  
$EndComp
$Comp
L Device:R_POT_TRIM RV4
U 1 1 5CA5BE61
P 9400 3850
F 0 "RV4" V 9286 3850 50  0000 C CNN
F 1 "10K" V 9400 3850 50  0000 C CNN
F 2 "Potentiometer_THT:Potentiometer_Bourns_3296W_Vertical" H 9400 3850 50  0001 C CNN
F 3 "~" H 9400 3850 50  0001 C CNN
	1    9400 3850
	0    1    1    0   
$EndComp
$Comp
L Device:R R7
U 1 1 5CA5BE68
P 9950 4000
F 0 "R7" V 10050 4000 50  0000 C CNN
F 1 "10K" V 9950 4000 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 9880 4000 50  0001 C CNN
F 3 "~" H 9950 4000 50  0001 C CNN
	1    9950 4000
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR024
U 1 1 5CA5BE6F
P 9400 4000
F 0 "#PWR024" H 9400 3750 50  0001 C CNN
F 1 "GND" H 9405 3827 50  0000 C CNN
F 2 "" H 9400 4000 50  0001 C CNN
F 3 "" H 9400 4000 50  0001 C CNN
	1    9400 4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	9000 3650 9600 3650
Wire Wire Line
	9000 3350 9100 3350
Wire Wire Line
	9100 3350 9100 2950
Wire Wire Line
	9100 2950 9600 2950
Wire Wire Line
	10300 3050 10200 3050
Wire Wire Line
	10300 3750 10200 3750
Wire Wire Line
	9250 3300 9250 3150
Wire Wire Line
	9400 3300 9250 3300
Wire Wire Line
	9600 3300 9800 3300
Wire Wire Line
	9600 3150 9600 3300
Wire Wire Line
	10100 3300 10200 3300
Wire Wire Line
	10200 3300 10200 3050
Connection ~ 10200 3050
Wire Wire Line
	9550 3150 9600 3150
Connection ~ 9600 3150
Connection ~ 9400 3300
Wire Wire Line
	9550 3850 9600 3850
Wire Wire Line
	9250 3850 9250 4000
Wire Wire Line
	9250 4000 9400 4000
Connection ~ 9400 4000
Wire Wire Line
	10100 4000 10200 4000
Wire Wire Line
	10200 4000 10200 3750
Connection ~ 10200 3750
Wire Wire Line
	9800 4000 9600 4000
Wire Wire Line
	9600 4000 9600 3850
Connection ~ 9600 3850
$Comp
L Amplifier_Operational:TL072 U6
U 1 1 5CA5F1A3
P 9900 5350
F 0 "U6" H 9950 5500 50  0000 C CNN
F 1 "TL072" H 9900 5350 50  0000 C CNN
F 2 "Package_DIP:DIP-8_W7.62mm" H 9900 5350 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 9900 5350 50  0001 C CNN
	1    9900 5350
	1    0    0    -1  
$EndComp
$Comp
L Amplifier_Operational:TL072 U6
U 2 1 5CA5F1AA
P 9900 4650
F 0 "U6" H 9950 4800 50  0000 C CNN
F 1 "TL072" H 9900 4650 50  0000 C CNN
F 2 "Package_DIP:DIP-8_W7.62mm" H 9900 4650 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/tl071.pdf" H 9900 4650 50  0001 C CNN
	2    9900 4650
	1    0    0    -1  
$EndComp
$Comp
L Device:R_POT_TRIM RV5
U 1 1 5CA5F1B1
P 9400 4750
F 0 "RV5" V 9286 4750 50  0000 C CNN
F 1 "10K" V 9400 4750 50  0000 C CNN
F 2 "Potentiometer_THT:Potentiometer_Bourns_3296W_Vertical" H 9400 4750 50  0001 C CNN
F 3 "~" H 9400 4750 50  0001 C CNN
	1    9400 4750
	0    1    1    0   
$EndComp
$Comp
L Device:R R8
U 1 1 5CA5F1B8
P 9950 4900
F 0 "R8" V 10050 4900 50  0000 C CNN
F 1 "10K" V 9950 4900 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 9880 4900 50  0001 C CNN
F 3 "~" H 9950 4900 50  0001 C CNN
	1    9950 4900
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR025
U 1 1 5CA5F1BF
P 9400 4900
F 0 "#PWR025" H 9400 4650 50  0001 C CNN
F 1 "GND" H 9400 4750 50  0000 C CNN
F 2 "" H 9400 4900 50  0001 C CNN
F 3 "" H 9400 4900 50  0001 C CNN
	1    9400 4900
	1    0    0    -1  
$EndComp
$Comp
L Device:R_POT_TRIM RV6
U 1 1 5CA5F1C5
P 9400 5450
F 0 "RV6" V 9286 5450 50  0000 C CNN
F 1 "10K" V 9400 5450 50  0000 C CNN
F 2 "Potentiometer_THT:Potentiometer_Bourns_3296W_Vertical" H 9400 5450 50  0001 C CNN
F 3 "~" H 9400 5450 50  0001 C CNN
	1    9400 5450
	0    1    1    0   
$EndComp
$Comp
L Device:R R9
U 1 1 5CA5F1CC
P 9950 5600
F 0 "R9" V 10050 5600 50  0000 C CNN
F 1 "10K" V 9950 5600 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P5.08mm_Horizontal" V 9880 5600 50  0001 C CNN
F 3 "~" H 9950 5600 50  0001 C CNN
	1    9950 5600
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR026
U 1 1 5CA5F1D3
P 9400 5600
F 0 "#PWR026" H 9400 5350 50  0001 C CNN
F 1 "GND" H 9405 5427 50  0000 C CNN
F 2 "" H 9400 5600 50  0001 C CNN
F 3 "" H 9400 5600 50  0001 C CNN
	1    9400 5600
	1    0    0    -1  
$EndComp
Wire Wire Line
	9000 5250 9600 5250
Wire Wire Line
	9000 4950 9100 4950
Wire Wire Line
	9100 4950 9100 4550
Wire Wire Line
	9100 4550 9600 4550
Wire Wire Line
	10300 4650 10200 4650
Wire Wire Line
	10300 5350 10200 5350
Wire Wire Line
	9250 4900 9250 4750
Wire Wire Line
	9400 4900 9250 4900
Wire Wire Line
	9600 4900 9800 4900
Wire Wire Line
	9600 4750 9600 4900
Wire Wire Line
	10100 4900 10200 4900
Wire Wire Line
	10200 4900 10200 4650
Connection ~ 10200 4650
Wire Wire Line
	9550 4750 9600 4750
Connection ~ 9600 4750
Connection ~ 9400 4900
Wire Wire Line
	9550 5450 9600 5450
Wire Wire Line
	9250 5450 9250 5600
Wire Wire Line
	9250 5600 9400 5600
Connection ~ 9400 5600
Wire Wire Line
	10100 5600 10200 5600
Wire Wire Line
	10200 5600 10200 5350
Connection ~ 10200 5350
Wire Wire Line
	9800 5600 9600 5600
Wire Wire Line
	9600 5600 9600 5450
Connection ~ 9600 5450
Wire Wire Line
	2700 4350 2700 4650
Wire Wire Line
	2700 4650 2600 4650
Wire Wire Line
	2900 4650 2900 4550
Wire Wire Line
	2900 4550 2600 4550
NoConn ~ 2600 4750
NoConn ~ 2600 4850
NoConn ~ 2600 4950
NoConn ~ 2600 5250
NoConn ~ 2600 5350
NoConn ~ 2600 5450
NoConn ~ 2600 5550
NoConn ~ 2600 5650
NoConn ~ 2600 5950
NoConn ~ 1600 5750
NoConn ~ 1600 5650
NoConn ~ 1600 5450
NoConn ~ 1600 4950
NoConn ~ 1600 4850
Wire Wire Line
	1250 2050 1850 2050
Wire Wire Line
	1250 2350 2150 2350
NoConn ~ 1100 3650
NoConn ~ 1100 3050
NoConn ~ 1600 5850
NoConn ~ 1950 4300
NoConn ~ 2050 4300
NoConn ~ 2150 4300
NoConn ~ 2250 4300
$Comp
L Modules:SSD1306_128x64 D2
U 1 1 5CAA37C3
P 4150 4900
F 0 "D2" H 3750 5300 50  0000 L CNN
F 1 "SSD1306_128x64" H 3800 4400 50  0000 L CNN
F 2 "" H 3600 5400 50  0001 C CNN
F 3 "" H 3600 5400 50  0001 C CNN
	1    4150 4900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 5CAA4329
P 3800 4150
F 0 "#PWR0101" H 3800 3900 50  0001 C CNN
F 1 "GND" H 3805 3977 50  0000 C CNN
F 2 "" H 3800 4150 50  0001 C CNN
F 3 "" H 3800 4150 50  0001 C CNN
	1    3800 4150
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0102
U 1 1 5CAA4408
P 4100 4150
F 0 "#PWR0102" H 4100 4000 50  0001 C CNN
F 1 "+5V" H 4115 4323 50  0000 C CNN
F 2 "" H 4100 4150 50  0001 C CNN
F 3 "" H 4100 4150 50  0001 C CNN
	1    4100 4150
	1    0    0    -1  
$EndComp
Wire Wire Line
	3800 4150 4000 4150
Wire Wire Line
	4000 4150 4000 4450
Wire Wire Line
	4100 4450 4100 4150
Text GLabel 4300 4450 1    50   BiDi ~ 0
I2C1_SDA
Text GLabel 4200 4450 1    50   BiDi ~ 0
I2C1_SCL
$EndSCHEMATC
