# -*- coding: utf-8 -*-
"""LED.ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/1KnjYFLTncX7v2hpu7kVZa0T66h50v-sz
"""

#!/usr/bin/python3
#Nosso
#led_y= gpio16
#led_r = gpio20
#led_g = gpio21

#led vermelho 2s
#led verde 1s
#led amarelo 1s
#5x


import sys
from time import sleep
LED_PATH_AMARELO = "/sys/class/gpio/gpio16/"
SYSFS_DIR = "/sys/class/gpio/"
LED_NUMBER_AMARELO = "16"

LED_PATH_VERMELHO = "/sys/class/gpio/gpio20/"
LED_NUMBER_VERMELHO = "20"

LED_PATH_VERDE = "/sys/class/gpio/gpio21/"
LED_NUMBER_VERDE = "21"


def writeLED ( filename, value, path ):
	"Esta funcao escreve o valor 'value' no arquivo 'path+filename'"
	fo = open( path + filename,"w")
	fo.write(value)
	fo.close()
	return

c = 0

while c <= 5:

#comando LED vermelho
  writeLED (filename="export", value=LED_NUMBER_VERMELHO, path=SYSFS_DIR)
	sleep(0.1)
  writeLED (filename="direction", value="out", path=LED_PATH_VERMELHO)
	
  writeLED (filename="value", value="1", path=LED_PATH_VERMELHO)
  sleep(2)
	writeLED (filename="value", value="0", path=LED_PATH_VERMELHO)
	writeLED (filename="unexport", value=LED_NUMBER_VERMELHO, path=SYSFS_DIR)

#Comando LED amarelo
  writeLED (filename="export", value=LED_NUMBER_AMARELO, path=SYSFS_DIR)
	sleep(0.1)
 	writeLED (filename="direction", value="out", path=LED_PATH_AMARELO)
	writeLED (filename="value", value="1", path=LED_PATH_AMARELO)
  sleep(1)
	writeLED (filename="value", value="0", path=LED_PATH_AMARELO)
	writeLED (filename="unexport", value=LED_NUMBER_AMARELO, path=SYSFS_DIR)
 
#comando LED verde
  writeLED (filename="export", value=LED_NUMBER_VERDE, path=SYSFS_DIR)
	sleep(0.1)
  writeLED (filename="direction", value="out", path=LED_PATH_VERDE)
	
  writeLED (filename="value", value="1", path=LED_PATH_VERDE)
  sleep(1)
	writeLED (filename="value", value="0", path=LED_PATH_VERDE)
	writeLED (filename="unexport", value=LED_NUMBER_VERDE, path=SYSFS_DIR)
 
  c = c+1