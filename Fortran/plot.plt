set term epslatex size 4.5in, 3in
set title "Temperature with Terms up to $n=".n."$"
set format x '%1.1f'
set format y '%1.1f'
set format z '%100.1f'
set output "surf".n.".tex"
set zrange [0:1.2]
set xyplane at 0
unset arrow
unset label
unset key
set style data lines
set dgrid3d 100, 100
set view 40, 220, 1, 1
splot "POINTS.TXT" u 1:2:3 lc "black
