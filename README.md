# Game-LED-Shield-Logic
Buttonbox LED shield logic to incorporate into your open source project

DESCRIPTION:
This project controls some logic to represent a game "shield" power states and where shield power is based off your inputs (up, down, left, right) the logic here shows you visually where your shields are the same commands sent to the lights can be sent to your game to give you an indicator of in game shields.  This particular project is only front back and left right for now but maybe further adaptations later.

INTENT:
The code for game/simlulator incorporation is not included as it may vary for your application.  The orginal intent is for use in button box projects(simulator, games, ect.)

APPLICATION:
The code is written for an Atmega microcontroller (arduino compatible) but could be adapted to many other uses.  You can simulate my entire project for freen at wowki.com
REQUIREMENTS:
To run this code in its native form it needs to be run on an an aruino compatible controller.
I used WS2812B LEDs and FASTLED library to make them work.


ABOUT THE AUTHOR:
This is my first Github project and I learned alot making this. That being said are likely glaring ommissions, errors, or lack of efficiency in this code.

FUTURE SCOPE:
I would like to add more features to include possible state readout(oled or 7 segment) in percentage where the "shields are pushed".  Also working on a similiar project about system power diversion that should be out in the coming weeks. They will probably be combined at some point.

CREDITS:
Arduino Master Class by Electronics Programming Acadamey
Arduino Support Page - Documentation there is excellent
I used ChatGPT to explain some of these concepts I couldn't get my head around and it was a double edge sword it can give you some pointers but often send you on race your not prepared to run. However still a handy tool at explaining some parts of the code when I couldn't find proper documentation.
