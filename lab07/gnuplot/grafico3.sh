
#!/bin/sh
ARQUIVODADOS=/home/pi/ESZB026-17-4-2022C/lab07/gnuplot/dados3.txt
ARQUIVOSAIDA=/home/pi/ESZB026-17-4-2022C/lab07/gnuplot/dados3.png

gnuplot << EOF
set title "Gráfico 3"
set ylabel "Belgica"
set xlabel "Canda"
set terminal png
set output "$ARQUIVOSAIDA"
plot "$ARQUIVODADOS" \
        linecolor rgb '#008000' \
        linetype 1 \
        linewidth 1 \
        pointtype 4 \
        pointsize 2 \
        title "dados aleatórios 3" \
        with linespoints
EOF









