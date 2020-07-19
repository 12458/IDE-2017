EESchema Schematic File Version 2
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
LIBS:battery-cr2032
LIBS:Carlolib-disc
LIBS:cr2032
LIBS:dc-dc
LIBS:Dispositivos_I2C
LIBS:freetronics_schematic
LIBS:hc-05
LIBS:hc-05_breakout
LIBS:nRF24L01+
LIBS:oled
LIBS:open-project
LIBS:TLC5940
LIBS:VIN
LIBS:w_relay
LIBS:74xgxx
LIBS:ac-dc
LIBS:actel
LIBS:allegro
LIBS:Altera
LIBS:analog_devices
LIBS:battery_management
LIBS:bbd
LIBS:brooktre
LIBS:cmos_ieee
LIBS:diode
LIBS:elec-unifil
LIBS:ESD_Protection
LIBS:ftdi
LIBS:gennum
LIBS:graphic
LIBS:hc11
LIBS:ir
LIBS:Lattice
LIBS:logo
LIBS:maxim
LIBS:mechanical
LIBS:microchip_dspic33dsc
LIBS:microchip_pic10mcu
LIBS:microchip_pic12mcu
LIBS:microchip_pic16mcu
LIBS:microchip_pic18mcu
LIBS:microchip_pic32mcu
LIBS:motor_drivers
LIBS:motors
LIBS:msp430
LIBS:nordicsemi
LIBS:nxp_armmcu
LIBS:onsemi
LIBS:Oscillators
LIBS:Power_Management
LIBS:powerint
LIBS:pspice
LIBS:references
LIBS:relays
LIBS:rfcom
LIBS:sensors
LIBS:silabs
LIBS:stm8
LIBS:stm32
LIBS:supertex
LIBS:switches
LIBS:transf
LIBS:ttl_ieee
LIBS:video
LIBS:wiznet
LIBS:Worldsemi
LIBS:Xicor
LIBS:zetex
LIBS:Zilog
LIBS:NRF_Transmitter-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "IDE 2017 Wireless Emergcy Stop Transmitter"
Date "2017-03-09"
Rev "1.0.0"
Comp "Done by Sim Shang En"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L ARDUINO_FOOTPRINT SHIELD?
U 1 1 58C13334
P 5150 4000
F 0 "SHIELD?" H 4700 5150 60  0001 C CNN
F 1 "Arduino Pro Mini" H 5200 3050 60  0000 C CNN
F 2 "FT:ARDUINO_SHIELD" H 5150 3800 50  0001 C CNN
F 3 "" H 5150 4000 60  0000 C CNN
	1    5150 4000
	1    0    0    -1  
$EndComp
$Comp
L nRF24L01+ U?
U 1 1 58C1365F
P 7850 3100
F 0 "U?" H 7850 2800 50  0001 C CNN
F 1 "nRF24L01+" H 7850 3400 50  0000 C CNN
F 2 "MODULE" H 7850 3200 50  0001 C CNN
F 3 "DOCUMENTATION" H 7850 3050 50  0001 C CNN
	1    7850 3100
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 58C1368C
P 7100 2900
F 0 "#PWR?" H 7100 2650 50  0001 C CNN
F 1 "GND" H 7100 2750 50  0000 C CNN
F 2 "" H 7100 2900 50  0000 C CNN
F 3 "" H 7100 2900 50  0000 C CNN
	1    7100 2900
	-1   0    0    1   
$EndComp
Text Label 8600 2900 0    60   ~ 0
SCK
Text Label 6100 3400 0    60   ~ 0
SCK
Text Label 6100 3500 0    60   ~ 0
MISO
Text Label 6100 3600 0    60   ~ 0
MOSI
Text Label 8600 3200 0    60   ~ 0
MOSI
Text Label 8600 3050 0    60   ~ 0
MISO
Text Label 7100 3350 2    60   ~ 0
SS
Text Label 6100 3900 0    60   ~ 0
SS
Text Label 7100 3200 2    60   ~ 0
CE
Text Label 6100 4100 0    60   ~ 0
CE
$Comp
L +3.3V #PWR?
U 1 1 58C1396F
P 7000 3050
F 0 "#PWR?" H 7000 2900 50  0001 C CNN
F 1 "+3.3V" H 7000 3190 50  0000 C CNN
F 2 "" H 7000 3050 50  0000 C CNN
F 3 "" H 7000 3050 50  0000 C CNN
	1    7000 3050
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR?
U 1 1 58C13A15
P 4050 3700
F 0 "#PWR?" H 4050 3550 50  0001 C CNN
F 1 "+3.3V" H 4050 3840 50  0000 C CNN
F 2 "" H 4050 3700 50  0000 C CNN
F 3 "" H 4050 3700 50  0000 C CNN
	1    4050 3700
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 58C13B42
P 4100 3900
F 0 "#PWR?" H 4100 3650 50  0001 C CNN
F 1 "GND" H 4100 3750 50  0000 C CNN
F 2 "" H 4100 3900 50  0000 C CNN
F 3 "" H 4100 3900 50  0000 C CNN
	1    4100 3900
	1    0    0    -1  
$EndComp
$Comp
L SW_SPST SW?
U 1 1 58C13B61
P 7350 4250
F 0 "SW?" H 7250 4350 70  0001 C CNN
F 1 "SW_SPST" H 7350 4150 70  0000 C CNN
F 2 "" H 7350 4250 60  0000 C CNN
F 3 "" H 7350 4250 60  0000 C CNN
	1    7350 4250
	0    -1   -1   0   
$EndComp
$Comp
L C_Small C?
U 1 1 58C13BFB
P 7800 4300
F 0 "C?" H 7810 4370 50  0001 L CNN
F 1 "50nF" H 7810 4220 50  0000 L CNN
F 2 "" H 7800 4300 50  0000 C CNN
F 3 "" H 7800 4300 50  0000 C CNN
	1    7800 4300
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 58C13C42
P 7550 3750
F 0 "R?" V 7630 3750 50  0001 C CNN
F 1 "10kΩ" V 7550 3750 50  0000 C CNN
F 2 "" V 7480 3750 50  0000 C CNN
F 3 "" H 7550 3750 50  0000 C CNN
	1    7550 3750
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR?
U 1 1 58C13E2A
P 7600 4750
F 0 "#PWR?" H 7600 4500 50  0001 C CNN
F 1 "GND" H 7600 4600 50  0000 C CNN
F 2 "" H 7600 4750 50  0000 C CNN
F 3 "" H 7600 4750 50  0000 C CNN
	1    7600 4750
	1    0    0    -1  
$EndComp
Text Label 7900 3750 0    60   ~ 0
Switch
Text Label 6100 4600 0    60   ~ 0
Switch
$Comp
L Battery BT?
U 1 1 58C140C5
P 3250 4000
F 0 "BT?" H 3350 4100 50  0001 L CNN
F 1 "3V" H 3350 4000 50  0000 L CNN
F 2 "" V 3250 4060 50  0000 C CNN
F 3 "" V 3250 4060 50  0000 C CNN
	1    3250 4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	7000 3050 7100 3050
Wire Wire Line
	4050 3700 4200 3700
Wire Wire Line
	4100 3900 4200 3900
Wire Wire Line
	7800 3750 7800 4200
Wire Wire Line
	7350 4750 7800 4750
Wire Wire Line
	7800 4750 7800 4400
Connection ~ 7600 4750
Wire Wire Line
	7350 3750 7400 3750
Wire Wire Line
	7700 3750 7900 3750
Connection ~ 7800 3750
Wire Wire Line
	3250 3800 4200 3800
$Comp
L GND #PWR?
U 1 1 58C1415E
P 3250 4200
F 0 "#PWR?" H 3250 3950 50  0001 C CNN
F 1 "GND" H 3250 4050 50  0000 C CNN
F 2 "" H 3250 4200 50  0000 C CNN
F 3 "" H 3250 4200 50  0000 C CNN
	1    3250 4200
	1    0    0    -1  
$EndComp
$EndSCHEMATC
