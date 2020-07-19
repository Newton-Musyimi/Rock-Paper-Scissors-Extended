/*
This is Rock-Papers-Scissors-Lizard-Spock;a spin-off ot the original RPS game that reduces the chance of player's having a tie.
For more, check out the README file on 
*/
#include "rpsls.hpp"

int main(){
  srand(time(NULL));
  rpsls rock_paper_scissors_lizard_spock = new rpsls();
  rock_paper_scissors_lizard_spock.game_instructions();
  rock_paper_scissors_lizard_spock.game_loop(game);
  rock_paper_scissors_lizard_spock.overall_score();
}