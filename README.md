# Electronic Dice

An **Arduino-powered electronic dice**: press a button to generate a pseudo-random number from **1 to 6**, then light up the LEDs to display the corresponding face of a dice.

The project has two stages:
1. A **breadboard prototype** to test the wiring and code.
2. A **soldered version** to make the dice compact and battery-powered.

## Components

- Arduino Uno (breadboard prototype)
- Arduino Nano (planned soldered version)
- 7 LEDs
- 7 current-limiting resistors (1 kΩ for softer LED brightness)
- 1 momentary push button
- Breadboard and jumper wires
- Perfboard and soldering equipment (final version)
- 9 V battery, battery clip, and ON/OFF switch (final version)

## 🔌 Pin Connections

 <img src="images/circuit-image.jpg" alt="Circuit" />

| Component | Arduino Pin |
| --- | --- |
| Top-left LED | D2 |
| Top-right LED | D3 |
| Middle-left LED | D4 |
| Center LED | D5 |
| Middle-right LED | D6 |
| Bottom-left LED | D7 |
| Bottom-right LED | D8 |
| Roll button | D9 |

The button uses `INPUT_PULLUP`, so it is connected between **D9 and GND**. Each LED has **its own series resistor**. Pin **A0** is left unconnected and used for the pseudo-random seed with `randomSeed(analogRead(A0))`.

## 1. Breadboard Prototype

The first version uses an **Arduino Uno** and a breadboard. It lets me test the connections and all six dice faces before soldering the final circuit.

### 📸 Prototype Photos

<p align="center">
  <img src="images/prototype-1.jpg" alt="Breadboard prototype — overview" width="30%" />
  <img src="images/prototype-2.jpg" alt="Breadboard prototype — wiring" width="30%" />
  <img src="images/prototype-3.jpg" alt="Breadboard prototype — LEDs on" width="30%" />
</p>

### Prototype Video


### How It Works

1. The Arduino waits for the button to be pressed.
2. It picks a number using `random(1, 7)` (1 through 6 inclusive).
3. It turns off all LEDs to clear the previous result.
4. A `switch` statement turns on the LEDs for the selected dice face.
5. It waits for the button to be released before accepting another roll.

## 2. Soldered Version

> **Coming soon** — this section will be updated once the soldered version has been built and tested.

The goal is to move the circuit onto **perfboard**, use a compact **Arduino Nano**, and power it with a battery and an **ON/OFF switch**.

For a classic 5 V Arduino Nano powered by a 9 V battery, the battery's positive lead goes through the switch to **VIN**, and the negative lead goes to **GND**. **Never connect 9 V directly to the 5V pin.**

### 📸 Soldered Version Photos

*Photos will be added after soldering.*

<!-- Uncomment this section after adding the photos:
<p align="center">
  <img src="images/soldered-1.jpg" alt="Soldered version — components" width="30%" />
  <img src="images/soldered-2.jpg" alt="Soldered version — solder joints" width="30%" />
  <img src="images/soldered-3.jpg" alt="Soldered version — finished dice" width="30%" />
</p>
-->

### ✅ Final Assembly Checklist

- [ ] Test every LED after soldering
- [ ] Check that the roll button works
- [ ] Verify power connections before connecting the battery
- [ ] Test all six dice faces
- [ ] Add photos of the finished build

## 💻 Arduino Code

The sketch uses `pinMode()`, `digitalRead()`, `digitalWrite()`, `random()`, `randomSeed()`, and a `switch` statement to control the LEDs.

<!-- Optional: add your .ino file to a code/ directory and uncomment this link: -->
<!-- [View the Arduino sketch](code/electronic-dice.ino) -->

## 📁 Project Structure

```text
.
├── README.md
├── Dice.ino
├── images/
│   ├── circuit-image.png
│   ├── prototype-1.jpg
│   ├── prototype-2.jpg
│   ├── prototype-3.jpg
│   ├── soldered-1.jpg       # to be added
│   ├── soldered-2.jpg       # to be added
│   └── soldered-3.jpg       # to be added
└── videos/
    └── prototype.mp4
```

*The soldered build photos will be added once the final version is complete.*
