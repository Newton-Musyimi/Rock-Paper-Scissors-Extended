/*
This is Rock-Papers-Scissors-Lizard-Spock;a spin-off ot the original RPS game that reduces the chance of player's having a tie.
For more, check out the README file on https://github.com/Newton-Musyimi/Learning-C-and-CPP
compilation: `g++ rpslsGAME.cpp rpsls.cpp`
*/
#include <cstdlib>
#include <ctime>
#include "rpsls.hpp"

int main(){
  srand(time(NULL));
  rpsls rock_paper_scissors_lizard_spock;
  rock_paper_scissors_lizard_spock.start();
}
