Arduinos are an approachable and abundant microcontroller. They are a small chip that can read digital and analog signals, control output voltages, and respond according to a flashed program. They are plentiful in physics labs because it is easy to program and connect them to instruments. They are progrgrammed with C++ and a library that facilitates the hardware control.

# Running this demo
Ideally, this demo would be run on a physical arduino. For each of the two examples, when it it run, wire it as shown in the notes below and upload it from the Arduino IDE. More info can be found at https://www.arduino.cc/en/main/howto

Alternatively, no hardware is needed to use a software simulator.  [Tinkedcad](https://www.tinkercad.com) is a free online example. This is what I recomended people following along with the talks use. You can switch to their "Circuits" sections and select "Create a new Circuit". Circuits can be assembled and an Arduino programed vy hitting "Code". To program it using C++, in the top drop down menu, "Blocks" should be changed to "Text". Hitting "Start Simulation will run the program and simulate hardware.

# Notes

## Analog Read

Arduinos are comonly used to log or respond to some sensor value. In this demo, a photoresistor is measured. Suppose that there was some lab instrument that whould only switched on when the light in a room is low enough, the control for that device could be connected pin 13 of the Arduino. (This pin was convieniently selected because it is tied to the build in LED on the Arduino Uno)

A Photoresistor has a resisitance that decreases when the intensity of light on it increases. It is wired up as shown in the setup diagram so that the voltage connected to A0 increases with brighter light.

![Diagram for Analog Read Demo](https://github.com/bagriffith/code_talks/blob/master/Arduino/Basic/Analog%20Read%20Diagram.png)

In the init(), which is run once at startup, the difference between `int` and `byte` and rollovers are explored. This is important to be aware of before writing even basic arduino scripts because it is easy to accidentally rollover an `int` in a lab setting.

```C++
// Some number magic
byte n = 300;
Serial.print("300 as a byte: ");
Serial.println(n);
  
int m = 300;
Serial.print("300 as an int: ");
Serial.println(m);
```

In `loop()` the internal LED through Pin 13 is switched on is the light is low enough. The blocks are shown to behave identically because `digitalWrite()` accepts a logical value, not just `HIGH` or `` LOW.

```C++
if (light_level < 512) {
    digitalWrite(13, HIGH);
} else {
    digitalWrite(13, LOW);
}
```

```C++
digitalWrite(13, light_level < 512);
```

Slower Interval and Serial output for debugging are included and commented out.

```C++
delay(1000);
Serial.println(light_level;)
```

## Counter

It is commonly needed to count a number of digital pulses with an arduino. An example that prints to the Serial connection when 1000 pulses are counted is presented as the second example.

![Diagram for Counter Demo](https://github.com/bagriffith/code_talks/blob/master/Arduino/Basic/Counter%20Diagram.png)
