# Procedure for Building a Braille Display

## Before You Begin
- Review the Engineering Design Process with your teacher to ensure this project is acceptable.  
- Familiarize yourself with how to use an Arduino by completing Tutorials 1 through 3.

## Build Your Circuit
- Assemble the circuit according to the diagrams in the provided document (Figures 4, 5, and 6).  
- A Tinkercad simulation is also available for a more detailed view.

1. **Prepare the Wires**  
   If any wires, such as the solenoid leads, are too flexible, use spring clips to connect them to jumper wires.

2. **Connect the MOSFETs**  
   Each MOSFET has three pins: gate, drain, and source. Ensure each pin is in its own row on the breadboard.  
   - Connect the **gate** pin to an Arduino digital pin (pins 2 through 7 in the diagram).  
   - Connect a diode from the **drain** pin to the +12V from your external power supply, with the stripe on the diode facing +12V.  
   - Connect the **source** pin to a ground bus.

3. **Connect the Solenoids**  
   Each solenoid has a positive and negative wire.  
   - Connect the negative wire of each solenoid to a MOSFET's drain pin.  
   - Connect the positive wire of each solenoid to +12V.

4. **Place the Button**  
   Place the button so it straddles the gap in the middle of the breadboard.  
   - Connect one side of the button to +5V.  
   - Connect the other side to ground through a 10kΩ resistor.  
   - Connect the side with the resistor to an Arduino digital pin (pin 8 in the diagram).

5. **Provide Power**  
   Ensure the entire circuit has a common ground.  
   - Connect the Arduino GND pin to a ground bus on the breadboard.  
   - Connect both breadboard ground buses with a jumper wire.  
   - Connect the negative wire from your external 12V power supply to a ground bus.  
   - Do not short-circuit the 5V from the Arduino to the 12V from the external power supply.  
   - Connect the Arduino's 5V pin to one breadboard power bus and the external 12V supply to the other.  
   - Do not connect these two power buses with a jumper wire, as this can damage your Arduino.

---

## Test Your Circuit
- After assembling the circuit, use the **solenoid_test.ino** program to test it.  
- This program will activate each solenoid one at a time to check for proper function.

If a solenoid does not work or stays on, check the following:
- Double-check all connections, especially those with spring clips, for loose wires.  
- Ensure the MOSFETs are properly oriented on the breadboard, with the writing facing right and the large metal tab facing left.  
- Check for short circuits on the breadboard.  
- Ensure each pin of the MOSFETs is connected separately and that you haven't accidentally connected wires in the same row.

- Once all six solenoids are working, arrange them in a three-row, two-column grid.  
- You can temporarily stick them together with double-sided tape.

---

## Try Displaying Braille Characters
1. Download the **refreshable_braille_display.ino** program and upload it to your Arduino.  
2. The program's default text is "hello". Press the button to cycle through each letter of the word on the display.  
3. Experiment with different words or modify the code to automatically cycle through letters without a button press.  
4. After testing, unplug your Arduino and 12V power supply to prevent the solenoids from overheating.

---

## Build and Test a Better Braille Display
- The solenoids' narrow pins can make it difficult to read. To create a better, more readable display, you can design and build a faceplate:
  - Cut or drill holes in a thin piece of wood or cardboard.  
  - Mount the solenoids to the back, allowing the pins to poke through to the front.  
  - Attach wooden or plastic beads to the ends of the pins to create smoother bumps.  

- Test the prototype yourself to check its sturdiness and whether you can easily run your fingers over the bumps.  
- For further improvement, have someone who can read braille test your display and provide feedback.
