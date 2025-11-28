# Refreshable Braille Display (ESP32 Edition)

## 🔍 Description
A low‑cost, open‑source *single‑cell refreshable braille display* built using six 12V solenoids and an ESP32 microcontroller. This upgraded version supports *Bluetooth SPP wireless text input*, making it more practical, modern, and user-friendly. The project demonstrates a functional prototype of assistive technology that is significantly cheaper than commercial solutions.

---

## 🏆 Achievements & Competitions
### *IHMMC – Innovative Hardware Model Making Competition*  
*Status:* Top 20 (International Hardware Event)  
Held by the Asansol Engineering College Hardware Club, IHMMC is an *international innovation challenge* focused on original hardware designs and rapid prototyping.

### *Technova – National Tech Event (Asansol Engineering College)*  
*Award:* 🥇 *1st Prize (Hardware Category)*  
A national-level tech fest where participants compete with projects related to *hardware, software, apps, and web innovations. The **ESP32 + Bluetooth upgraded version* of this Braille display won 1st place.

### *Hack-O-Hire – National Event (Kolkata)*  
*Award:* 🥈 *2nd Prize (Level 1)* and *Qualified for Level 2*  
A multi-level national event, co-powered by *Trikaya* and *Beetle X, designed so that winners in Level 3 receive internship opportunities. Our project secured **2nd place in Level 1* and moved forward to Level 2.

---

## 🔄 Upgraded Version (ESP32)
This version includes major improvements over the Arduino prototype:
- *ESP32 DevKit v1* used as the main controller
- *Bluetooth SPP-based wireless text input* from mobile
- *Removed physical buttons* → fully wireless operation
- *More stable power distribution* (ESP32 via USB-C, solenoids via 12V)
- *Cleaner control logic* with improved timing and responsiveness
- Same *2×3 solenoid braille cell*, now more robust

---

## ✨ Features
- *6-solenoid braille cell* capable of rendering any braille character
- *Wireless input via Bluetooth (SPP)*
- *Cost-effective components* readily available for students and hobbyists
- *Open-source design* suitable for scaling into multi-cell displays

---

## 🚀 Getting Started
### Requirements
- ESP32 DevKit v1
- Arduino IDE with ESP32 Board Manager installed
- Bluetooth Terminal App (Android)
- 12V solenoids, P55NF06 MOSFETs, 1N4001 diodes

### Basic Usage
1. Power ESP32 via USB-C.
2. Power solenoids using a separate 12V supply.
3. Connect via Bluetooth using any SPP terminal.
4. Send text to display braille characters one by one.

---

## 📌 License
This project is released under the *MIT License*.

---

## 📘 Notes
This upgraded version replaces the older Arduino-based design. A brief history of the original version may be added later if required.
