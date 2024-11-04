# Guessing Game with Leaderboard


This project is a C++ implementation of a guessing game with a leaderboard feature. Originally written in C, this program has been updated to C++ to make use of object-oriented programming principles.

## Features

- **Guessing Game**: The player attempts to guess a randomly generated number within a set range.
- **Leaderboard**: Player scores (based on number of guesses) are recorded and saved to a file.
- **Persistent Scores**: The leaderboard is saved to a file, allowing scores to persist across game sessions.

## Requirements

- **C++ Compiler** (g++ recommended)
- **Standard C++ Libraries** (for file handling and random number generation)

## Installation

1. Clone the repository or download the source files.
   ```bash
   git clone https://github.com/4ndy1e/object-oriented-guessing-game.git
   cd object-oriented-guessing-game
   ```

2. Compile the code using a C++ compiler:
   ```bash
   g++ -o guessing_game guessing_game.cpp
   ```

3. Run the compiled program:
   ```bash
   ./guessing_game
   ```

## Usage

1. **Game Start**: The program will generate a random number within a specific range (e.g., 1–100).
2. **Player Guesses**: The player is prompted to guess the number, receiving feedback on whether the guess is too high or too low.
3. **Leaderboard Update**: Upon guessing correctly, the player’s score (number of attempts) is added to the leaderboard file.
4. **File Persistence**: The leaderboard is saved to a text file, allowing scores to persist for future sessions.

## File Structure

- `guessing_game.cpp` - Main source code file for the guessing game and leaderboard functionality.
- `leaderboard.txt` - A file where player scores and names are stored.

## Code Details

This C++ implementation makes use of:

- **Classes** to represent the Game and Leaderboard entities.
- **File I/O** for saving and loading the leaderboard.
- **Random Number Generation** using C++ libraries.

## Future Improvements

Some potential enhancements include:

- Adding a difficulty level that adjusts the range of the random number.
- Displaying the top scores from the leaderboard.
- Adding a player name prompt to store names alongside scores.

## License

This project is licensed under the MIT License. See `LICENSE` file for more details.

## Acknowledgments

This project is part of a programming assignment to practice C++ and implement a file-persistent leaderboard for a simple guessing game.
