| Patrick Gilfoil |
:-
| s198018 |
| Intro to C++ |
| Tic-Tac-Toe |

## I. Requirements

1. Description of the problem

    - **Name:** Tic-Tac-Toe

    - **Problem Statement:** Recreate the game of Tic-Tac-Toe in C++.

    - **Problem Specifications:** The program must use 

2. Input Information

    - The keyboard is used to perform input.

3. Output Information

    - Every turn will show the board and the spaces where a mark can be placed.
    - The console will output for each player turn on where to set a mark
    - When someone wins, it will declare that user as the winner and show the final resulting board.

4. User Interface Information

    - Information is output to the user through the console

## II. Design

1. System Arcitecture

    Type: Game

    - Name: grid
        - Description: character array of the tic-tac-toe "board"
        - Type: char [3][3]

    - Name: gameOver
        - Description: variable to control the game loop
        - Type: bool

    - Name: mapWidth
        - Description: fixed integer of the width of the game board used in printing the game board
        - Type: int

    - Name: mapHeight
        - Description: fixed integer of the height of the game board used in printing the game board
        - Type: int

    - Name: player1Turn
        - Description: variable to control the turn of player 1
        - Type: bool

    - Name: player2Turn
        - Description: variable to control the turn of player 2
        - Type: bool

    - Name: player1Win
        - Description: variable to determine the win condition of player 1
        - Type: bool

    - Name: player2Win
        - Description: variable to determine the win condition of player 2
        - Type: bool

    - Name: getInput()
        - Description: function to get the input of the players
        - Return Type: void

    - Name: checkForWin()
        - Description: function to check the win conditions for both players
        - Return Type: void

    - Name: draw()
        - Description: function to draw the game board
        - Return Type: void

    - Name: isGameOver()
        - Description: function to return the status of the gameOver variable
        - Return Type: bool
