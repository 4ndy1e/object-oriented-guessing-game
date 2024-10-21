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
  cout << "Please enter your name to start: ";

  // Clear the input buffer and get user's name
  cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
  getline(cin, name); 

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
    void WriteLeaders(char fileName[]);
    void printLeaders();
    static bool compare(Player& a, Player& b);

  private:
    int index;
    static const int NUM_LEADERS = 5;
    Player leaders[NUM_LEADERS];
};

void Leaderboard::InsertPlayer(Player& player) {
  // insert player at tracked index and sort leaderboard
  leaders[index] = player;
  index++;
  sort(leaders, leaders+index, compare);
}

void Leaderboard::ReadLeaders(char fileName[]) {
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

void Leaderboard::WriteLeaders(char fileName[]) {
  FILE* file = fopen(fileName, "w");

  for(int i = 0; i < index; i++) {
    fprintf(file, "%s made %d guesses\n", leaders[i].getName().c_str(), leaders[i].getGuesses());
  }
}

void Leaderboard::printLeaders() {
  cout << "\nHere are the current leaders: \n";

  for(int i = 0; i < index; i++) {
    cout << leaders[i].getName() << " made " << leaders[i].getGuesses() << " guesses\n";
  }
}

bool Leaderboard::compare(Player& a, Player& b) {
  // sort leaderboard in ascending order
  return a.getGuesses() < b.getGuesses();
}


int main(int argc, const char* argv[]) {
  // create leaderboard and read current leaders from txt file
  Leaderboard leaderboard;
  char fileName[] = "leaderboard.txt";
  leaderboard.ReadLeaders(fileName);
  
  cout << "Welcome! Press 'q' to quit or any other key to continue:\n";
  char c;
  bool game_over = false;

  while (!game_over) {
    cin >> c;
    if (c == 'q') {
      // write players to leaderboard to store for next game
      leaderboard.WriteLeaders(fileName);
      game_over = true;
      cout << "Bye Bye!\n";
    }
    else {
      // create new player and begin game
      Player current_player;
      current_player.playGame();
      leaderboard.InsertPlayer(current_player);
      leaderboard.printLeaders();
    }
    cout << "Press 'q' to quit or any other key to continue: ";
  }
}