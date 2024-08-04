# Tic-Tac-Toe Game

## Overview
Welcome to the Tic-Tac-Toe game implemented in C++! This is a console-based version of the classic game where two players take turns to mark the cells in a 3×3 grid with 'X' or 'O'. The player who succeeds in placing three of their marks in a horizontal, vertical, or diagonal row wins the game.

## Features
- *Two-player mode*: Allows two players to play against each other.
- *Winner List*: Displays a list of winners from previous games.
- *Replay option*: Players can choose to play again after a game is over.
- *Clear board*: Resets the board for a new game.
- *Exit option*: Allows players to exit the game.

### Game Instructions
1. Upon running the game, you will be presented with a welcome screen and a menu with three options:
   - Play Game
   - Show Winners List
   - Exit Game

2. Choose "Play Game" to start a new game. Enter the names of Player X and Player O.

3. The game board will be displayed, and Player X will be prompted to make their move first. Enter the number corresponding to the cell where you want to place your mark.

4. Players take turns until the game is over, either by one player winning or the game ending in a draw.

5. After the game, you can choose to play again, view the winners list, or exit the game.

## Code Structure
- **main()**: The main function that initializes the game and handles the game loop.
- **displayboard()**: Function to display the current state of the game board.
- **playerchoice()**: Function to handle the current player's move.
- **blockreset()**: Function to reset the game board.
- **exit_game()**: Function to display the exit message.
- **show_winners_list()**: Function to display the list of winners.
- **gameover()**: Function to check if the game is over (win or draw).

## Note
- The system("cls") command is used to clear the screen, which works on Windows. For Unix-like systems, use system("clear").
