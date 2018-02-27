# Navy

## Authorized functions:
open, close, read, write, lseek, malloc, free, getpid, kill, signal,
sigaction, sigemptyset, setcontext, getcontext, usleep, nanosleep, pause

You are allowed to use one (and only one) global variable, if you can justify it

## Subject

You all know the very famous Battleship game. Well, I hope
so.
You must code a terminal version of this game.
The two players are ONLY allowed to comunicate using the
signals SIGUSER1 and SIGUSER2.
The map size is 8x8. On each turn, you must display your
positions, and then your enemy’s positions.
At the end of the game (when all the ships of a player have
been hit), you must display whether “I won” (and return 0) or
“Enemy won” (and return 1).
