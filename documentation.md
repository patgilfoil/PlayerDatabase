| Patrick Gilfoil |
:-
| s198018 |
| Intro to C++ |
| Player Database |

## I. Requirements

1. Description of the problem

    - **Name:** Player Database

    - **Problem Statement:** Create a program that will create, modify and save player profiles to a random-access binary file.

    - **Problem Specifications:** The program must store a name and high score for a player profile to a binary file and be able to read from it. It should sort profiles by alphabetical order, and be able to update scores with a binary search function

2. Input Information

    - The keyboard is used to perform input.

3. Output Information

    - The menu of options is shown on startup
    - Selecting the "View All Scores" option will show all player scores to the user
    - Entering a profile allows the user to give an associated name and score to the program to create a player profile
    - Updating a profile allows the user to return a new score to the profile with the associated name they wish to choose
    - Player profile data is stored in a .dat file called "save.dat"; if the program starts up when player data is detected, it will load from this file

4. User Interface Information

    - Information is output to the user through the console

## II. Design

1. System Arcitecture

- Type: Container

    - Name: playerList[]
        - Description: The entire list of players
        - Type: Player array

    - Name: dataSize
        - Description: the current size of the player list array
        - Type: int

    - Name: save()
        - Description: function to save player data to an external file
        - Return Type: void

    - Name: load()
        - Description: function to load player data from an external file if present, returns true if data is successfully loaded
        - Return Type: bool

    - Name: optionSelection()
        - Description: function to load a user interface menu to select options such as creating profiles and saving data
        - Input Variable: bool active
        - Return Type: void

    - Name: add()
        - Description: function to add players to current player list
        - Input Variable: Player player
        - Return Type: void

    - Name: updatePlayer
        - Description: function to update a player score from a search term; if the search term matches any associated profile, it will allow the user to update the score for that profile
        - Return Type: void

    - Name: sort()
        - Description: function to sort all player scores in the player list by name in alphabetical order
        - Return Type: void

- Type: Player

    - Name: name[30]
        - Description: variable to store the player's name, fixed length character array of 30
        - Type: char

    - Name: score
        - Description: variable that stores the player's score
        - Type: int

    - Name: getName()
        - Description: function to return the name of a player profile
        - Return Type: char*

    - Name: getScore()
        - Description: function to return the score from a player profile
        - Return Type: int

    - Name: setName()
        - Description: function to set the name of a player profile to the name sent through the function parameters
        - Input Variable: char pName[30]
        - Return Type: void

    - Name: setScore()
        - Description: function to set the score of a player profile to the score sent through the function parameters, primarilty used in the updatePlayer function in Container
        - Input Variable: int pScore
        - Return Type: void

    - Name: save()
        - Description: function to save associated data of a player to the save file, called in the Container's save function
        - Input Variable: std::ofstream& o
        - Return Type: void

    - Name: load()
        - Description: function to load player data from a save file, called in the Container's load function, returns true when successfully loaded
        - Input Variable: std::ifstream& i
        - Return Type: bool

    - Name: addPlayer()
        - Description: function used to create a new profile for a player, gets a name and a score associated
        - Return Type: void