# Project Title

Tic Tac Toe game made in c for Task Phase Manas 2022.

## Description

This game has two mode Player vs Player and Player vs Computer in which the computer generates random random moves.
Follow the instruction on screen to play the game.

## Getting Started

### Installing

* You will need a C compiler to do this already installed, I use GCC. https://gcc.gnu.org/. If you are on a Windows computer, you can run the command gcc -v to check if it’s already installed.
```
gcc -v
```
* Open notepad and paste the entire source code on it then save the file as tictac.c on the desktop.
* Open the command prompt by clicking start button → All Apps → Windows System folder → Click Command Prompt.
* Change our directory to where you have your C program (tictac.c) which is the desktop. Paste the following command onto the cmd.
```
cd Desktop
```
* Run the command “gcc”(the C-compiler ) followed by the full name of your program (tictac.c) in the command prompt. This will compile your source code and create an executable file on your desktop. Paste the following command on the cmd and hit enter.
```
gcc -o <name_of_executable> <name_of_source_code>
```
```
gcc -o tictac tictac.c
```
### Executing program

* In this step we will run our program (the executable file) in command prompt, then type the name of the executable file without the extension (my executable file name was tictac.exe) so I typed the following:
```
tictac
```

### Descriptions of the Functions in the program
* resetBoard() - This function clears the board for new game.
* printBoard() - Prints the current Board.
* checkFree() - Checks for free spaces in the board and return the no free spaces.
* playerMove()- User input for both player 1 and player 2
* computerMove() - Randomly generates the moves for the Player vs Computer mode
* checkWin() - Checks for the winner symbol and returns the symbol
* main() - Mode selector for game calls the functions according to the logic of game, in the end checks for the winner and displays the winner.


## Acknowledgments

Inspiration, code snippets
* [BroCode-Youtube](https://www.youtube.com/watch?v=_889aB2D1KI&t=57s)
