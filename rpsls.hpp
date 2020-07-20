class rpsls{
  private:
    int game_plays;
    int player_wins;
    int pc_wins;
    int ties;
  public:
    rpsls();
    ~rpsls();
    void start();
    void game_instructions();
    void plays();
    int get_plays();
    void player_wins_counter();
    int get_player_wins();
    void pc_wins_counter();
    int get_pc_wins();
    void ties_counter();
    int get_ties();
    void rock(int computer);
    void paper(int computer);
    void scissors(int computer);
    void lizard(int computer);
    void spock(int computer);
    void overall_score();
};
