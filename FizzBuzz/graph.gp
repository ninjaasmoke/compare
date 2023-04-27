set terminal png
set output "plot.png"
set datafile separator "\t"
set xlabel "Time"
set ylabel "Seconds"
set style data boxes
plot "./speed/c_time.txt" using 2:xticlabels(1) title "Execution Time"
