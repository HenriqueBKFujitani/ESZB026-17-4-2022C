#!/usr/bin/python3

#importando bibliotecas 
import sys
from time import sleep
#declarando variáveis para indicar o caminho de cada porta
LED_PATH_AMARELO = "/sys/class/gpio/gpio16/"
SYSFS_DIR = "/sys/class/gpio/"
LED_NUMBER_AMARELO = "16"

LED_PATH_VERMELHO = "/sys/class/gpio/gpio20/"
LED_NUMBER_VERMELHO = "20"

LED_PATH_VERDE = "/sys/class/gpio/gpio21/"
LED_NUMBER_VERDE = "21"

#Função que cria um arquivo de txt adicionando e escreve um valor atribuindo ao caminho
def writeLED (filename, value, path):
	fo = open(path+filename,"w")
	fo.write(value)
	fo.close()
	return

#Abrindo portas dos leds
writeLED (filename="export", value=LED_NUMBER_VERMELHO, path=SYSFS_DIR)
sleep(0.1)
writeLED (filename="direction", value="out", path=LED_PATH_VERMELHO)

writeLED (filename="export", value=LED_NUMBER_AMARELO, path=SYSFS_DIR)
sleep(0.1)
writeLED (filename="direction", value="out", path=LED_PATH_AMARELO)

writeLED (filename="export", value=LED_NUMBER_VERDE, path=SYSFS_DIR)
sleep(0.1)
writeLED (filename="direction", value="out", path=LED_PATH_VERDE)

c = 0
#Contador e fcao while para executar 5x
while c <= 5:

#comando LED vermelho
	writeLED (filename="value", value="1", path=LED_PATH_VERMELHO)
	sleep(2)
	writeLED (filename="value", value="0", path=LED_PATH_VERMELHO)
	
#Comando LED amarelo
	writeLED (filename="value", value="1", path=LED_PATH_AMARELO)
	sleep(1)
	writeLED (filename="value", value="0", path=LED_PATH_AMARELO)
	 
#comando LED verde
	writeLED (filename="value", value="1", path=LED_PATH_VERDE)
	sleep(1)
	writeLED (filename="value", value="0", path=LED_PATH_VERDE)
	 
	c = c+1
	#Contador para repetição da funcao while
	
#Fechando portas
writeLED (filename="unexport", value=LED_NUMBER_VERMELHO, path=SYSFS_DIR)
writeLED (filename="unexport", value=LED_NUMBER_AMARELO, path=SYSFS_DIR)
writeLED (filename="unexport", value=LED_NUMBER_VERDE, path=SYSFS_DIR)
