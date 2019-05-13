# Navy
A terminal version of the famous "Battleship" game

*This is a school project*

### Description

This is a terminal version of the "Battleship" game, where the goal is to sink the enemy's boats on a board by 'shooting' at precise coordinates to try to hit every parts of the said boats, but their positions and orientations are unknown.

## How to test it

`./navy [first_player_pid] myboard.txt`

#### Connecting
Passing a value as the `first_player_pid` will make navy try to connect to that said PID (process ID).

If no PID is passed, the program will simply wait for a connection.

#### Boards
The board size is 8x8.
Player boards that are passed as arguments are describe in text files.

**You will find find two test boards in the repository's root.**

The boards must contain 4 boats of length 2 to 5.

They are formated the following way:

*BOAT_LENGTH:BOAT_HEAD:BOAT_TAIL*

For exemple:

*2:C1:C2*

Here *C1* and *C2* repectively represent *BOAT_HEAD* and *BOAT_TAIL*.

Translatting *C1* in XY coordinates would give us :

X = 'C' = 3

Y = '1' = 1
