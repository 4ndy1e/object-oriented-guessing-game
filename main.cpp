int main(int argc, const char* argv[]) {

}

class Player {
  public: 

  private:
    int name, guesses;
};

class Leaderboard {
  public:
    Leaderboard();
    void InsertPlayer(Player player);

  private:
    static const int NUM_LEADERS = 5;
    Player leader[NUM_LEADERS];
};