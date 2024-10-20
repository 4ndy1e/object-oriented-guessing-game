#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

class Player {
  public: 
    // constructors
    Player() {}
    Player(string name, int guesses): name(name), guesses(guesses){};

    // getters
    string getName() { return name; }
    int getGuesses() { return guesses; }

  private:
    string name;
    int guesses;
};

class Leaderboard {
  public:
    Leaderboard(){this->index = 0;}
    void InsertPlayer(Player player);
    void ReadLeaders(char fileName[]);
    void printLeaders();

  private:
    int index;
    static const int NUM_LEADERS = 5;
    Player leaders[NUM_LEADERS];
};

void Leaderboard::InsertPlayer(Player player) {

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


int main(int argc, const char* argv[]) {
  Leaderboard leaderboard;
  char fileName[] = "leaderboard.txt";
  leaderboard.ReadLeaders(fileName);
  leaderboard.printLeaders();

  // cout << "Welcome! Press 'q' to quit or any other key to continue:\n";
  // char c;
  // bool game_over = false;

  // while (!game_over) {
  //   cin >> c;
  //   if (c == 'q') {
  //     game_over = true;
  //     cout << "Bye Bye!\n";
  //   }
  //   else {
  //     Player current_player;
  //   }
}