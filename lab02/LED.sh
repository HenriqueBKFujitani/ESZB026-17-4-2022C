#!/bin/bash

#Led vermelho 2s
#Led verde 1s
#Led amarelo 1s
#Definindo varaveis com as portas
LED_GPIO_AMARELO=16
LED_GPIO_VERMELHO=20
LED_GPIO_VERDE=21

#Função que altera valor do LED
#$1 corresponde ao estado e $2 o LED em questao
function setLED
{                                    
	echo $1 >> "/sys/class/gpio/gpio$2/value"
}

#Abrindo portas
echo $LED_GPIO_VERMELHO >> "/sys/class/gpio/export"
sleep 1 
echo "out" >> "/sys/class/gpio/gpio$LED_GPIO_VERMELHO/direction"

echo $LED_GPIO_AMARELO >> "/sys/class/gpio/export"
sleep 1
echo "out" >> "/sys/class/gpio/gpio$LED_GPIO_AMARELO/direction"

echo $LED_GPIO_VERDE >> "/sys/class/gpio/export"
sleep 1
echo "out" >> "/sys/class/gpio/gpio$LED_GPIO_VERDE/direction"

#Contador para while
c=0
while [ $c -le 5 ]
do 
	#LED vermelho
	setLED 1 LED_GPIO_VERMELHO
	sleep 2
	setLED 0 LED_GPIO_VERMELHO

	#LED verde
	setLED 1 LED_GPIO_VERDE
	sleep 1
	setLED 0 LED_GPIO_VERDE

	#LED amarelo
	setLED 1 LED_GPIO_AMARELO
	sleep 1
	setLED 0 LED_GPIO_AMARELO
	#funcao que permite sobrescrever uma var em bash
	let c=c+1
done
#fechando portas
echo $LED_GPIO_AMARELO >> "/sys/class/gpio/unexport"
sleep 1
echo $LED_GPIO_VERDE >> "/sys/class/gpio/unexport"
sleep 1
echo $LED_GPIO_VERMELHO >> "/sys/class/gpio/unexport"
