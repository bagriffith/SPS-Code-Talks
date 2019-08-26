Fortran is a language created in the 50s for use by scientists and related mathematically heavy work. It was commonly the language taught to physicists in computational physics courses until recently. Although it is now widely considered to be a legacy tool, it is still incredible useful because of the enormous volume of legacy code written to work with it. A basic familiarity of Fortran is valuable because you may find a problem where the best tool to work on it with is a Fortran exclusive library.

# Demo Problem and Context

This project supposes some square has been restricted to the the boundary condition that 3 sides have a temperature of 0&#176;C, and the 4th side has a constant tempurature of 100&#176;C. We would like to show what the steady state temperature of a unit square of metal restricted to these constraints would look like.

First, the problem is analytically solved. A steady state temperature must conform to the boundary conditions and the Laplace Equation.

### laplacian T(x,y) = 0
and the Boundary Conditions
### T(x, 0) = 100&#176;C
### T(x, 1) = T(0, y) = T(1, y) = 0&#176;C

As is typical with PDEs we assume seperability, i.e. the solution takes the form
T(x,y) = X(x)Y(y)
and then to meet the boundary conitions
### X(x) = C_k * sin(k*x)
for k = i*pi with i being any integer > 1, and an arbitrary constant 
and
### Y(y) = C_k * exp(-k*y)

So T(x, y) = C_k * exp(-k*y) * sin(k*x)

A fourier series is used to meet the final boundary condition, determining C_k for the sum over all k.
C_k = 1 / pi int_0^1 (sin(k_m*x)) dx
C_k = (cos(k_m) - 1) / (k_m * pi)

# Running this Demo

To run this demo the gfortran Fortran compiler, LaTeX, and gnuplot are needed. This also serves as a demo of using gnuplot to form LaTeX PDFs. This was for a long time the best way to form high quality vector pgraphs, but now is really just something to understand for legacy purposes.

First, compile the Fortran code. Execute `gfortran -o plotter plotter.f90` . Then execute it by running `./plotter`. Then render the LaTeX into a PDF with the command `pdflatex graph.tex`

# Notes