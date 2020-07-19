class rpsls{
  private:
    int game_plays = 0;
    int player_wins = 0;
    int pc_wins = 0;
  public:
    rpsls();
    void game_loop();
    void game_instructions();
    void plays();
    int get_plays()
    void player_wins_counter();
    int get_player_wins();
    void pc_wins_counter();
    int get_pc_wins();
    void rock(int computer);
    void paper(int computer);
    void scissors(int computer);
    void lizard(int computer);
    void spock(int computer);
    void overall_score();
}
