
#!/bin/sh
ARQUIVODADOS=/home/pi/ESZB026-17-4-2022C/lab07/gnuplot/dados2.txt
ARQUIVOSAIDA=/home/pi/ESZB026-17-4-2022C/lab07/gnuplot/dados2.png

gnuplot << EOF
set title "Gráfico 2"
set ylabel "Sabado"
set xlabel "Domingo"
set terminal png
set output "$ARQUIVOSAIDA"
plot "$ARQUIVODADOS" \
        linecolor rgb '#0000FF' \
        linetype 3 \
        linewidth 1 \
        pointtype 5 \
        pointsize 2 \
        title "dados aleatórios 2" \
        with linespoints
EOF









