# Game-LED-Shield-Logic
Buttonbox LED shield logic to incorporate into your open source project

DESCRIPTION:
This project controls some logic to represent a game "shield" power states (Currently build for Star Citizen) using WS2812 addressable LED's.  Using a directional pad, joystick, or 4 buttons that can be used to move the shields in any direction represeted by bolstoring  shields (color change) in the direction you specify and depleting the opposite (color change).    This current iteration has two steps for example one step in any direction turns the shield selected to blue and the opposite to yellow if you press again it turns the shield cyan and opposite red representing a full shield shift.  This particular project is only front back and left right for now but maybe evolve in the future.

INTENT:
The code for game/simlulator incorporation is not included as it may vary for your application.  The orginal intent is for use in a Star Citizen button box but could be used in many space simulator style games.

APPLICATION:
The code is written for an Atmega microcontroller (arduino compatible) but could be adapted to many other compute.  You can simulate my entire project for freen at wowki.com

REQUIREMENTS:
To run this code as written without modification it was run on an an arduino compatible controller.
I used WS2812B LEDs and FASTLED library to make them work.
I simulated everythig at wowki.com before building the actual parts. 


ABOUT THE AUTHOR:
This is my first Github project and I learned alot making this. That being said are likely glaring ommissions, errors, or lack of efficiency in this code.

FUTURE SCOPE:
I would like to add more features to include possible state readout(oled or 7 segment) in percentage where the "shields are pushed".  Also working on a similiar project about system power diversion that should be out in the coming weeks. They will probably be combined at some point.

CREDITS:
FastLED Library
Arduino Master Class - by Electronics Programming Acadamey
Arduino Support Page - Documentation there is excellent
I used ChatGPT to explain some of these concepts I couldn't get my head around and it was a double edge sword it can give you some pointers but often send you on race your not prepared to run. However still a handy tool at explaining some parts of the code when I couldn't find proper documentation.
