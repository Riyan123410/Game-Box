# Game-Box
A circuit made with an arduino and an LCD (I2C) that can play three different games. Video showcasing all the features: https://www.youtube.com/watch?v=oeP2pHyIK9Y 

## Features: 
- 3 playable games:
  - Dino Game
  - Wack a Mole
  - Simon Says
- Settings menu options:
  - Enable/disable music
  - Make the T-rex fly
  - Change Wack a Mole difficulty
- Background music

## Code Installation:
1. Download main/gameBox folder
2. Open the sketch through Arduino IDE
3. Install the following librarys:
   - Wire.h
   - LiquidCrystal_I2C.h
   - pitches.h
4. Change the pin numbers in constants.ino depending on your circuit

## Materials:
- Arduino Uno R3
- Piezo Buzzer
- 5 Push Buttons
- 9 Resisters
- LCD 16 x 2 (I2C)
- Potentiometer
- 1 Breadboard Small and 1 Breadbard Mini
- Wires

## Circuit:
The right four buttons corespond to the 4 LEDs left to right
![circuit drawing](https://github.com/Riyan123410/Game-Box/blob/main/GameBoxLayout.png)

## Tinkercad Simulation:
Simulation differences:
- Only has playable 1 game(dino game)
- No music and settings

The BRS file can be downloaded [here](https://github.com/Riyan123410/Game-Box/blob/main/game%20box.brd)
Or use the simulation online [here](https://www.tinkercad.com/things/kHQZ5K2lTOZ-simulated-game-box?sharecode=y5nIe05luYwXFF-voKwsmAcUryRnGv_LbI6rn2tPDvk)

## Dino Game:

https://github.com/user-attachments/assets/3cbe0207-2547-4cd8-8fd3-ab2fe115972f

Pterodactyl:

https://github.com/user-attachments/assets/4fb99204-c38c-4cf3-a958-652ab74721a3

## Wack A Mole:

https://github.com/user-attachments/assets/74727405-f719-40be-8c7b-ab0680016501

## Simone Says:

https://github.com/user-attachments/assets/ba02d615-3b81-4bd7-b941-1ac13e21cb9b

## Credits:
Music: https://projecthub.arduino.cc/tmekinyan/playing-popular-songs-with-arduino-and-a-buzzer-546f4a 









