This is an example of using C++. It emphasizes Object Oriented Programming principles when related to physics programming. This example was written as part of the Arduino series to discuss the more advanced features of C++ that may not be relevant to basic arduino work, but may be helpful to be aware of for more advanced later work.

This demo simulates several fixed charges particles, and then traces the path of one free charged particles

# Running this demo

To run this demo, cmake and a C++ compiler are needed. For Linux installing cmake from the included package manager should work `sudo apt-get install cmake`. For Windows, CMake has a gui. Find out more info here https://cmake.org/runningcmake/

Create a build directory in the C_C++ code directory. Cd into it and run the make file. For this is `cmake ..` . You will then need to run `make` to compile the code. In Windows, use the GUI, and set "Where is the source code" to the location of the C_C++ directory and set "Where to build the binaries" to the build directory in it.

You can then run the Cpp_demo file. On Linux in the build directory run `./Cpp_demo`. On windows open cmd and go to the build directory, and run `start Cpp_demo.exe`.  It should output

```
0.5, 0.1
0.505514, 0.0178102
0.519331, -0.0560059
0.53909, -0.123791
0.563314, -0.186966
0.590974, -0.246473
0.621291, -0.302968
0.653646, -0.356921
0.687536, -0.408676
0.722537, -0.458487
0.758299, -0.506542
0.794527, -0.552988
0.83098, -0.597937
0.867457, -0.641483
0.903799, -0.683701
0.939876, -0.72466
0.975589, -0.76442
1.01086, -0.803035
1.04563, -0.840558
1.07986, -0.877037
1.11352, -0.912519
1.14659, -0.947048
1.17906, -0.980668
1.21093, -1.01342
1.24219, -1.04534
1.27287, -1.07647
1.30295, -1.10684
1.33246, -1.13649
1.36141, -1.16545
1.3898, -1.19374
1.41767, -1.22141
1.44501, -1.24846
1.47185, -1.27495
1.4982, -1.30087
1.52407, -1.32627
1.54949, -1.35116
1.57446, -1.37556
1.59901, -1.39949
1.62313, -1.42297
1.64686, -1.44602
1.67019, -1.46865
1.69315, -1.49089
1.71574, -1.51274
1.73798, -1.53421
1.75988, -1.55534
1.78145, -1.57612
1.8027, -1.59656
1.82363, -1.61669
1.84427, -1.6365
1.86461, -1.65602
1.88467, -1.67525
1.90445, -1.6942
1.92397, -1.71287
1.94323, -1.73129
1.96224, -1.74945
1.981, -1.76737
1.99953, -1.78504
2.01782, -1.80249
2.03589, -1.81971
2.05375, -1.83671
2.07139, -1.8535
2.08882, -1.87008
2.10605, -1.88647
2.12309, -1.90266
2.13993, -1.91866
2.15659, -1.93447
2.17307, -1.95011
2.18937, -1.96557
2.20549, -1.98086
2.22145, -1.99599
2.23724, -2.01095
2.25287, -2.02575
2.26835, -2.04041
2.28367, -2.05491
2.29884, -2.06926
2.31387, -2.08347
2.32875, -2.09754
2.34349, -2.11147
2.3581, -2.12527
2.37257, -2.13894
2.3869, -2.15248
2.40112, -2.1659
2.4152, -2.17919
2.42916, -2.19237
2.443, -2.20542
2.45672, -2.21836
2.47033, -2.23119
2.48382, -2.24391
2.4972, -2.25652
2.51047, -2.26903
2.52364, -2.28143
2.5367, -2.29373
2.54965, -2.30593
2.56251, -2.31803
2.57526, -2.33004
2.58792, -2.34195
2.60048, -2.35377
2.61295, -2.3655
2.62532, -2.37714
2.63761, -2.38869
```

# Notes

## Vector Class

To make this easier to physics, I begin by implementing the vector as commonly  used in physics.

### Operator Overriding

This process involves defined what all basic operations like multiplying and adding are for Vectors. This process is called overriding an operator. For addition it looks like

```C++
Vector Vector::operator+(const Vector right)
{
    return Vector(x+right.x, y+right.y);
}
```

## More Abstract Classes

This is a lot like the (2nd Python Code Talk)[https://github.com/bagriffith/SPS-Code-Talks/tree/master/Python/2.%20Classes%20and%20Object%20Oriented%20Programming] where I create abstract objects to simulate the elements in the simulation.