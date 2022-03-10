PROJECT DESCRIPTION: 

This is a replica of the the game “2048,” a single-player computer game written by Gabriele Cirulli, and based on an earlier game “1024” by Veewo Studio.

The rules are as follows: It’s played on a 4×4 grid of squares, each of which can either be empty or contain a tile bearing an integer–a power of 2 greater 
than or equal to 2. Before the first move, the application adds a tile containing either 2 or 4 to a random square on the initially empty board. The choice 
of 2 or 4 is random, with a 75% chance of choosing 2 and a 25% chance of choosing 4.

The player then chooses a direction via their arrow keys to tilt the board: north, south, east, or west. All tiles slide in that direction until there is no 
empty space left in the direction of motion (there might not be any to start with). A tile can possibly merge with another tile which earns the player points.



RUN EXAMPLE:

exe/./PC04 
Initial Location: (1, 1)
SCORE: 0
---------
| | | | |
---------
| |2| | |
---------
| | | | |
---------
| | | | |
---------
ELIGIBLE TO MAKE A MOVE
New 2 place at: (2, 0)
SCORE: 0
---------
| | | | |
---------
| |2| | |
---------
|2| | | |
---------
| | | | |
---------
MAKE A MOVE CHOICE
l for left, r for right, u for up, d for down: d
SCORE: 0
---------
| | | | |
---------
| | | | |
---------
| | | | |
---------
|2|2| | |
---------
Do you wish to con continue? (y/n): y
ELIGIBLE TO MAKE A MOVE
New 2 place at: (1, 2)
SCORE: 0
---------
| | | | |
---------
| | |2| |
---------
| | | | |
---------
|2|2| | |
---------
MAKE A MOVE CHOICE
l for left, r for right, u for up, d for down: d
SCORE: 0
---------
| | | | |
---------
| | | | |
---------
| | | | |
---------
|2|2|2| |
---------
Do you wish to con continue? (y/n): y
ELIGIBLE TO MAKE A MOVE
New 2 place at: (1, 2)
SCORE: 0
---------
| | | | |
---------
| | |2| |
---------
| | | | |
---------
|2|2|2| |
---------
MAKE A MOVE CHOICE
l for left, r for right, u for up, d for down: l
SCORE: 4
---------
| | | | |
---------
|2| | | |
---------
| | | | |
---------
|4|2| | |
---------
Do you wish to con continue? (y/n): n