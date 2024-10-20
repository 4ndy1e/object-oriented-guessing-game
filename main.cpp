#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>  

using namespace std;

class Player {
  public: 
    // constructors
    Player() : guesses(0) {}
    Player(string name, int guesses): name(name), guesses(guesses){};
    void playGame();

    // getters
    string getName() { return name; }
    int getGuesses() { return guesses; }

  private:
    string name;
    int guesses;
};

void Player::playGame() {
  // declare struct variables with person's info
  cout << "Please enter your name to start: ";
  cin >> name;

  // prompt user for starting guess game
  int randomNum = rand() % (100 - 10 + 1) + 10;
  double sqrtVal = sqrt(randomNum);
  int guess;

  cout << sqrtVal << " is the square root of what number? ";
  cin >> guess;

  // logic for guess
  while(guess != randomNum) {
    if(guess > randomNum) {
      guesses++;
      cout << "Too high, guess again: Guess a value between 10 and 100: ";
      cin >> guess;
    }
    else {
      guesses++;
      cout << "Too low, guess again: Guess a value between 10 and 100: ";
      cin >> guess;
    }
  }

  guesses++;
  printf("You got it, baby! \n You made %d guesses\n", guesses);
}

class Leaderboard {
  public:
    Leaderboard(){this->index = 0;}
    void InsertPlayer(Player& player);
    void ReadLeaders(char fileName[]);
    void printLeaders();
    static int compare(Player& a, Player& b);

  private:
    int index;
    static const int NUM_LEADERS = 5;
    Player leaders[NUM_LEADERS];
};

void Leaderboard::InsertPlayer(Player& player) {
  cout << "Now entering Insert function at index " << index;
  cout << "The player being inserted is " << player.getName() << " with " << player.getGuesses() << " guesses";
  leaders[index] = player;
  index++;
  sort(leaders, leaders+index, compare);
}

void Leaderboard::ReadLeaders(char fileName[]) {
  // add players to struct array
  FILE* file = fopen(fileName, "r");

  // define variables for scanning
  char name[20];
  int guesses;

  // create Player for every person in leaderboard and add to leaders array
  while (fscanf(file, "%19s made %d guesses\n", name, &guesses) == 2 && index < NUM_LEADERS) {
    leaders[index] = Player(name, guesses);
    index++;
  }
}

void Leaderboard::printLeaders() {
  printf("\n");
  printf("Here are the current leaders: \n");

  for(int i = 0; i < index; i++) {
    printf("%s made %d guesses\n", leaders[i].getName().c_str(), leaders[i].getGuesses());
  }
}

int Leaderboard::compare(Player& a, Player& b) {
  return a.getGuesses() - b.getGuesses();
}


int main(int argc, const char* argv[]) {
  // create leaderboard and read current leaders from txt file
  Leaderboard leaderboard;
  char fileName[] = "leaderboard.txt";
  leaderboard.ReadLeaders(fileName);
  leaderboard.printLeaders();

  cout << "Welcome! Press 'q' to quit or any other key to continue:\n";
  char c;
  bool game_over = false;

  while (!game_over) {
    cin >> c;
    if (c == 'q') {
      game_over = true;
      cout << "Bye Bye!\n";
    }
    else {
      // create new player and begin game
      Player current_player;
      current_player.playGame();
      cout << current_player.getGuesses() << " total guesses\n";
      cout << current_player.getName() << " is the name\n";
      leaderboard.InsertPlayer(current_player);
      leaderboard.printLeaders();
    }
  }
}