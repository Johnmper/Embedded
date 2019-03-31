G0 G90 G40 G21 G17 G94 G80
G54 X-75 Y-75 S500 M3  (Position 6)
G43 Z100 H1
Z5
G1 Z-20 F100
X-40                   (Position 1)
Y40 M8                 (Position 2)
X40                    (Position 3)
Y-40                   (Position 4)
X-75                   (Position 5)
Y-75                   (Position 6)
G0 Z100
M30
G0 G49 G40  G17 G80 G50 G90
M6 T0(TOOL DIA.0.75)
G64
G20 (Inch)
M04 S0
G00 G43 H0  Z0.1
X0 Y0
G01 Z-0.25 F1
G2 Y0 X0.15 R0.075 F30
Y0 X-0.15 R0.15
Y0 X0.3 R0.225
Y0 X-0.3 R0.3
Y0 X0.45 R0.375
Y0 X-0.45 R0.45
Y0 X0.6 R0.525
Y0 X-0.6 R0.6
Y0 X0.75 R0.675
Y0 X-0.75 R0.75
Y0 X0.9 R0.825
Y0 X-0.9 R0.9
Y0 X1.05 R0.975
Y0 X-1.05 R1.05
Y0 X1.125 R1.0875
Y0 X-1.125 R1.125
X1.125 Y0 R1.125
