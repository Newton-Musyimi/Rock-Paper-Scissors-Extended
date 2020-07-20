//Libraries requires for the game including the header file
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "rpsls.hpp" //The function declarations

//Declarations - moved to header file


rpsls::rpsls(){
  game_plays = 0;
  player_wins = 0;
  pc_wins = 0;
  ties = 0;
}//The constructor

rpsls::~rpsls(){
	std::cout << "                   Based on Notes from SAM KASS\n"
		      << "           (http://www.samkass.com/theories/RPSSL.html)"
		      << "\n------------------------------------------------------------------\n"
	          << "                        Closing Game. BYE!"
			  << "\n------------------------------------------------------------------\n";	          
}//The destructor

void rpsls::start(){
  game_instructions(); 
  bool game = true;
  std::cout << "                 =================================\n"
	        << "                 ROCK PAPER SCISSORS LIZARD SPOCK!\n"
			<< "                 =================================\n";

  std::cout << "\nWhen you get the 'GO' pick one of the options provided.\n";
  std::cout << "\n------------------------------------------------------------------\n";
  while(game){
    plays();
    /*
    bool get_instructions = false;
    std::cout<<"Would you like to see the game instructions once again? (1=Yes, 0=No): ";
    std::cin >> get_instructions;
    if(get_instructions){
      game_instructions();
    }
    */
    int computer = rand() % 5 + 1;
    int user = 0;
  
    std::cout << "\nRock, Paper, Scissors, Lizard, Spock, GO!\n"
              << "1) ROCK\n"
			  << "2) PAPER\n"
			  << "3) SCISSORS\n"
			  << "4) LIZARD\n"
			  << "5) SPOCK\n"
	          << "Enter number: ";
    std::cin>> user;
    std::cout << "\n------------------------------------------------------------------\n";
    switch(user){
      case 1:
        rock(computer);
        break;
      case 2:
        paper(computer);
        break;
      case 3:
        scissors(computer);
        break;
      case 4:
        lizard(computer);
        break;
      case 5:
        spock(computer);
        break;
      default:
        std::cout <<"Invalid Input!"<<std::endl;
        break;
    }
    std::cout << "\n------------------------------------------------------------------\n";
    std::cout<<"Play again? (1=Yes, 0=No): ";
    std::cin >> game;
    std::cout << "------------------------------------------------------------------\n";
  }
  overall_score();
  std::cout << "\n------------------------------------------------------------------\n";
}//The game loop

void rpsls::game_instructions(){
  std::cout<< "                 ROCK PAPER SCISSORS LIZARD SPOCK\n"
           << "------------------------------------------------------------------\n"
           << "           Welcome to Rock-Paper-Scissors-Lizard-Spock\n"
           << "------------------------------------------------------------------\n\n"
           << "RPSLS is a text-based video game where you will play against the\n"
		   << "    PC and you get to choose either rock, paper, scissors, lizard\n"
		   << "    or spock.\n"
           << "The rules are simple:\n"
           << "\ta. There are 5 options(1 to 5).\n"
           << "\tb. You can only pick one option during a match.\n"
           << "\tc. When prompted, you will enter its number.\n"
           << "\t For example, if you choose LIZARD, you will enter 4.\n\n"
           << "The options and there abilities are: \n"
           << "\t1) Rock - Crushes Scissors and crushes Lizard\n"
           << "\t2) Paper - Covers Rock and disproves Spock\n"
           << "\t3) Scissors - Cuts paper and decapitates lizard\n"
           << "\t4) Lizard - Poisons Spock and eats Paper\n"
           << "\t5) Spock - Smashes Scissors and vaporizes Rock\n\n"
           << "Both you and the PC will pick a \'hand\' and the winner will be\n"
		   << "    announced\n"
           << "You are allowed to play as many times as you want. An overall\n"
		   << "    score of the game will be given at the end\n\n\n\n\n"           
		   <<"\n------------------------------------------------------------------\n"
		   << "                              ENJOY!"
		   <<"\n------------------------------------------------------------------\n\n\n\n\n\n";
}

void rpsls::plays(){
  game_plays++;
}

int rpsls::get_plays(){
  return game_plays;
}

void rpsls::player_wins_counter(){
  player_wins++;
}

int rpsls::get_player_wins(){
  return player_wins;
}

void rpsls::pc_wins_counter(){
  pc_wins++;
}

int rpsls::get_pc_wins(){
  return pc_wins;
}
void rpsls::ties_counter(){
  ties++;
}
int rpsls::get_ties(){
 return ties;
}

void rpsls::rock(int computer){
  std::string outcome;
  std::string pc;
  switch(computer){
    case 1:
    	ties_counter();
        outcome = "It is a tie";
        pc = "Rock";
        break;
    case 2:
    	pc_wins_counter();
        outcome = "PC wins";
        pc = "Paper";
        break;
    case 3:
    	player_wins_counter();
        outcome = "You have won, congratulations!";
        pc = "Scissors";
        break;
    case 4:
    	player_wins_counter();
        outcome = "You have won, congratulations!";
        pc = "Lizard";
        break;
    case 5:
    	pc_wins_counter();
        outcome = "PC wins!";
        pc = "Spock";
        break;
    default:
        std::cout <<"Invalid Input!"<<std::endl;
        break;
  }
  std::cout <<"You picked Rock and the PC picked "<<pc<<"\n"<<outcome<<std::endl;
}//When user is Rock

void rpsls::paper(int computer){
  std::string outcome;
  std::string pc;
  switch(computer){
    case 1:
    	player_wins_counter();
        outcome = "You have won, congratulations!";
        pc = "Rock";
        break;
    case 2:
    	ties_counter();
        outcome = "It is a tie";
        pc = "Paper";
        break;
    case 3:
    	pc_wins_counter();
        outcome = "PC wins!";
        pc = "Scissors";
        break;
    case 4:
    	pc_wins_counter();
        outcome = "PC wins";
        pc = "Lizard";
        break;
    case 5:
    	player_wins_counter();
        outcome = "You have won, congratulations!";
        pc = "Spock";
        break;
    default:
        std::cout <<"Invalid Input!"<<std::endl;
        break;
  }
  std::cout <<"You picked Paper and the PC picked "<<pc<<"\n"<<outcome<<std::endl;
}//When user is Paper

void rpsls::scissors(int computer){
  std::string outcome;
  std::string pc;
  switch(computer){
    case 1:
    	pc_wins_counter();
        outcome = "PC Wins";
        pc = "Rock";
        break;
    case 2:
    	player_wins_counter();
        outcome = "You have won, congratulations!";
        pc = "Paper";
        break;
    case 3:
    	ties_counter();
        outcome = "It is a tie";
        pc = "Scissors";
        break;
    case 4:
    	player_wins_counter();
        outcome = "You have won, congratulations!";
        pc = "Lizard";
        break;
    case 5:
    	pc_wins_counter();
        outcome = "PC wins";
        pc = "Spock";
        break;
    default:
        std::cout <<"Invalid Input!"<<std::endl;
        break;
  }
  std::cout <<"You picked Scissors and the PC picked "<<pc<<"\n"<<outcome<<std::endl;
}//When user is scissors

void rpsls::lizard(int computer){
  std::string outcome;
  std::string pc;
  switch(computer){
    case 1:
    	pc_wins_counter();
        outcome = "PC wins";
        pc = "Rock";
        break;
    case 2:
    	player_wins_counter();
        outcome = "You have won, congratulations!";
        pc = "Paper";
        break;
    case 3:
    	pc_wins_counter();
        outcome = "PC wins";
        pc = "Scissors";
        break;
    case 4:
    	ties_counter();
        outcome = "It is a tie";
        pc = "Lizard";
        break;
    case 5:
    	player_wins_counter();
        outcome = "You have won, congratulations!";
        pc = "Spock";
        break;
    default:
        std::cout <<"Invalid Input!"<<std::endl;
        break;
  }
  std::cout <<"You picked Lizard and the PC picked "<<pc<<"\n"<<outcome<<std::endl;
}//When user is lizard

void rpsls::spock(int computer){
  std::string outcome;
  std::string pc;
  switch(computer){
    case 1:
    	player_wins_counter();
        outcome = "You have won, congratulations!";
        pc = "Rock";
        break;
    case 2:
    	pc_wins_counter();
        outcome = "PC wins";
        pc = "Paper";
        break;
    case 3:
    	player_wins_counter();
        outcome = "You have won, congratulations!";
        pc = "Scissors";
        break;
    case 4:
    	pc_wins_counter();
        outcome = "PC wins";
        pc = "Lizard";
        break;
    case 5:
    	ties_counter();
        outcome = "It is a tie";
        pc = "Spock";
        break;
    default:
        std::cout <<"Invalid Input!"<<std::endl;
        break;
  }
  std::cout <<"You picked Spock and the PC picked "<<pc<<"\n"<<outcome<<std::endl;
}//When the user is spock

void rpsls::overall_score(){
  int plays = get_plays();
  int player = get_player_wins();
  int pc = get_pc_wins();
  int draw = get_ties();
  std::string result = " ";
  if(player>pc){
    std::cout<< "Out of the "<<plays<<" matches played:\n"
	         << "\tYou won: "<<player<<"\n"
	         << "\tPC won: "<<pc<<"\n";
	if(draw>0)
	  std::cout << "\tTies: "<<draw<<"\n";       
	std::cout<< "You are the overall WINNER of the game, CONGRATULATIONS!"<<std::endl;
  }else if(player == pc){
    std::cout<< "Out of the "<<plays<<" matches played:\n"
	         << "\tYou won: "<<player<<"\n"
	         << "\tPC won: "<<pc<<"\n";
	if(draw>0)
	  std::cout << "\tTies: "<<draw<<"\n";
	std::cout<< "It was a TIE, BETTER LUCK NEXT TIME!"<<std::endl;
  }else{
    std::cout<< "Out of the "<<plays<<" matches played:\n"
	         << "\tYou won: "<<player<<"\n"
	         << "\tPC won: "<<pc<<"\n";
	if(draw>0)
	  std::cout << "\tTies: "<<draw<<"\n";          
	std::cout<< "You are the overall LOOSER of the game, BETTER LUCK NEXT TIME!"<<std::endl;
  }
}
