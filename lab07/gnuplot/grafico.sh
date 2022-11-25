#!/bin/sh
ARQUIVODADOS=/home/pi/ESZB026-17-4-2022C/lab07/gnuplot/dados1.txt
ARQUIVOSAIDA=/home/pi/ESZB026-17-4-2022C/lab07/gnuplot/dados1.png

gnuplot << EOF
set title "Gráfico 1"
set ylabel "Eixo Y"
set xlabel "Eixo X"
set terminal png
set output "$ARQUIVOSAIDA"
plot "$ARQUIVODADOS" \
	linecolor rgb '#0060ad' \
	linetype 2 \
	linewidth 2 \
	pointtype 2 \
	pointsize 1.0 \
	title "dados aleatórios 1" \
	with linespoints
EOF


