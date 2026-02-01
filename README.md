# Arduino2osu
a rlly budget osu keypad but with arduino uno :/


========================================
oipoi – DIY osu! Keypad (Arduino + Python)
========================================

Release Version
---------------
This is a RELEASE build of oipoi.


Author / Credits
----------------
Created by: radhhdhd
All credit goes to me.


Description
-----------
oipoi is a DIY osu! keypad built using an Arduino Uno and a Python-based
USB keyboard (HID) emulator.

The Arduino reads button inputs and sends them over Serial.
A Python program running on the PC converts those inputs into real
keyboard presses that osu! can recognize.

The project includes a standalone .exe and optional Python-based tools.


Project Structure
-----------------
- for_the_real_shi.ino              -> Arduino sketch
- oipoi.exe                          -> Standalone executable (recommended)
- oipoi.py                           -> Python source code
- oipoi.bat                          -> Optional launcher
- cmd command (for .bat use).txt     -> Python dependency install command
- The interesting one/               -> Python-related folder
    - PyInstaller files
    - Used to build the .exe
    - Exists mainly for .bat compatibility


How It Works
------------
1. Arduino Uno runs "for_the_real_shi.ino".
2. Buttons connected to the Arduino are pressed.
3. The Arduino sends data over Serial.
4. The Python program asks the user to type the COM port name.
5. The program connects to the Arduino Uno.
6. Serial input is converted into keyboard presses.
7. The PC sees the Arduino as a keyboard.


Pin Mapping
-----------
Arduino pin bindings:

- Pin 2  -> A key
- Pin 3  -> S key


⚠️ Keybind Warning
------------------
Default keybinds are:

- A
- S

Keybinds are NOT changed in the .exe.

To change keybinds:
- Open "for_the_real_shi.ino" in the Arduino IDE
- Locate the section near:
  // Handle button 2 (a key)
- Modify the key values there
- Re-upload the sketch to the Arduino


COM Port Selection
------------------
- When oipoi starts, the user manually types the COM port name.
- The port must match the connected Arduino Uno.
- No COM ports are hardcoded.


.exe vs .bat (Important)
------------------------
- Use oipoi.exe if you DO NOT have Python installed.
- The .exe is standalone and easiest to use.
- The .exe may have slight input lag compared to the .bat.
- The .bat is OPTIONAL and intended for Python users or very
  lightweight (kilobyte-friendly) setups.
- The .bat requires Python to be installed.


cmd command (for .bat use).txt
------------------------------
This file contains the command required for the .bat to work:

py -m pip install pyserial pynput

This installs the required Python dependencies.
ONLY required when using oipoi.bat.
Not required for the .exe.


Python Source (Advanced Users)
------------------------------
- The main Python file is "oipoi.py".
- Coders can modify this file to:
  - Change key behavior
  - Adjust timing
  - Improve performance
  - Add features
- PyInstaller is located inside "The interesting one" folder.
- That folder exists mainly for building the .exe and .bat compatibility.


Requirements
------------
- Arduino Uno
- DIY keypad/buttons
- USB cable
- Windows PC
- Arduino IDE
- oipoi.exe (or Python + .bat)


Setup Instructions
------------------
1. Open "for_the_real_shi.ino" in the Arduino IDE.
2. Upload the sketch to the Arduino Uno.
3. Plug the Arduino into the PC.
4. Find the Arduino COM port using Device Manager.
5. Run oipoi.exe (or oipoi.bat if using Python).
6. Type the COM port name when prompted.
7. Launch osu! and play.


Important Notes
---------------
- Arduino Uno does NOT natively support USB HID.
- Keyboard emulation is handled entirely by Python.
- Antivirus software may flag HID-related executables.
- DIY project — expect tinkering.


Use Case
--------
- osu! keypad
- Rhythm games
- Custom input devices
- Serial + HID experimentation


Disclaimer
----------
This project is for educational and personal use.
I am not responsible for misuse of this software.


click circles responsibly
- radhhdhd
