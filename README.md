### **Refreshable Braille Display (Arduino)**

### **Description**
This project is an open-source, low-cost prototype of a refreshable braille display. It utilizes an Arduino microcontroller and a custom-designed array of solenoids to actuate a single braille cell. The display can be programmed to translate and present text characters into their corresponding braille patterns. This project aims to demonstrate an accessible and economical alternative to the expensive refreshable braille displays currently on the market, which typically use piezoelectric actuators.

---
# IHMMC Challenge Submission

This project was our team's submission for the [Innovative Hardware Model Making Competition (IHMMC)](https://www.aechardwareclub.in/), a flagship event of the Asansol Engineering College Hardware Club.  

The competition encourages participants to design and build original hardware or hardware-software models. Our project was required to be an original creation and was evaluated based on:  
- Creativity  
- Functionality  
- Aesthetics  
- A 5-minute presentation  

The event is internationally recognized and has attracted over 1100 participants.

## Team Members
- Ankit Raj  
- Aastha Baranwal  
- Abhinav Burnwal  
- Barsa
- Manish
- Aryan Biswas

---

### **Motivation**
The primary motivation for this project is to address the high cost of existing refreshable braille technology. By using readily available and inexpensive components, such as solenoids, we can create a functional prototype that can serve as a foundation for more affordable assistive technology. This makes the project ideal for students, hobbyists, and researchers interested in building accessible hardware solutions.

---

### **Features**
* **Solenoid-based Actuation**: Employs an array of six solenoids to create a single, dynamic braille cell.
* **Arduino Control**: Uses an Arduino-compatible microcontroller for simple and reliable control of the display.
* **Modular Design**: The circuit is designed to be easily scalable, allowing for the addition of more braille cells to create a multi-character display.
* **Open-Source**: All schematics, code, and design files are open-source and available for community use and improvement.

---

### **Getting Started**

#### **Prerequisites**
Before you begin, ensure you have the following:
* Arduino IDE installed
* A basic understanding of Arduino programming and electronics

#### **Hardware**
The following components are required to build the display:
* Arduino-compatible microcontroller (e.g., Arduino Uno)
* Solenoids (6x)
* Breadboard
* Jumper wires
* 10kΩ resistors
* 12V power supply with a minimum of 1.2A current
* MOSFETs (6x)
* 1N4001 diodes (6x)
* Pushbutton switch

#### **Assembly**
Follow these steps to assemble the prototype:
1.  **Circuit Construction**: Connect the solenoids, MOSFETs, and other components to the Arduino on a breadboard. Refer to the provided schematic for proper wiring.
2.  **Physical Layout**: Arrange the solenoids in a 3x2 grid to form a single braille cell. Secure them in place using an enclosure or a simple mounting plate.
3.  **Code Upload**: Download the Arduino sketch and upload it to your microcontroller.

---

### **Usage**
The Arduino code is configured to display a predefined string of text. The push button is used to advance to the next character in the sequence. You can modify the code to display any custom text you wish.

### **Future Work**
Potential improvements and next steps for this project include:
* **User Input**: Implement a system to allow real-time text input from a computer keyboard or a mobile device via Bluetooth or serial communication.
* **Multiple Braille Cells**: Expand the design to include multiple braille cells to create a full display that can render entire words and sentences.
* **Power Optimization**: Explore methods to reduce power consumption, such as latching mechanisms or lower-power actuators, to prevent the solenoids from overheating and to improve battery life.
* **Enclosure Design**: Create a professional 3D-printable or laser-cut enclosure to house the components and provide a smooth, tactile surface for the braille dots.

---

### **License**
This project is licensed under the [MIT License]. See the LICENSE.md file for details.
