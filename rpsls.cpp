//Libraries requires for the game including the header file
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "rpsls.hpp" //The function declarations

//Declarations - moved to header file

//The game loop
rpsls::rpsls(){
  game_plays = 0;
  player_wins = 0;
  pc_wins = 0;
}
rpsls::~rpsls(){
	std::cout <<"Closing Game. BYE!";
}
void rpsls::game_loop(){    
  bool game = true;
  while(game){
    plays();
    bool get_instructions = false;
    std::cout<<"Would you like to see the game instructions once again? (1=Yes, 0=No): ";
    std::cin >> get_instructions;
    if(get_instructions){
      game_instructions();
    }
    int computer = rand() % 5 + 1;
    int user = 0;
    std::cout << "=================================\n"
	          << "rock paper scissors lizard spock!\n"
			  << "=================================\n";

    std::cout << "When you get the 'GO' pick one of the options below:\n"
	<< "1) ROCK\n"
	<< "2) PAPER\n"
	<< "3) SCISSORS\n"
	<< "4) LIZARD\n"
	<< "5) SPOCK\n";
  
    std::cout << "Rock, Paper, Scissors, Lizard, Spock, GO!\n"
	             "Enter number: ";
    std::cin>> user;
    std::cout << "\n=================================\n"
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
        std::cout <<"Invalid Input!<<std::endl";
        break;
    }
    std::cout<<"Play again? (1=Yes, 0=No): ";
    std::cin >> game;
  }
 
}

void rpsls::game_instructions(){
  std::cout<< "\t\t\t\t\tROCK PAPER SCISSORS LIZARD SPOCK\n"
           << "\t\tWelcome to the Rock-Paper-Scissors-Lizard-Spock text-based video game\n\n"
           << "You will play against the PC and you get to choose either rock, paper, scissors, lizard or spock.\n"
           << "The rules are simple:\n"
           << "\ta.\tThere are 5 options(1 to 5).\n"
           << "\tb.\tYou can only pick one option during a match.\n"
           << "\tc.\tWhen prompted, you will enter its number (position on the list) into the console.\n"
           << "\t  \tFor example, if your choice is LIZARD, you will enter 4.\n\n"
           << "The options and there abilities are: \n"
           << "\t1)\tRock\t\t- Crushes Scissors and crushes Lizard\n"
           << "\t2)\tPaper\t\t- Covers Rock and disproves Spock\n"
           << "\t3)\tScissors\t\t- Cuts paper and decapitates lizard\n"
           << "\t4)\tLizard\t\t- Poisons Spock and eats Paper\n"
           << "\t5)\tSpock\t\t- Smashes Scissors and vaporizes Rock\n\n"
           << "Both you and the PC will pick a \'hand\' and the winner will be announced\n"
           << "You are allowed to play as many times as possible;there will be a prompt where you enter 1 for YES and 0 for NO\n"
           << "\t\t\tENJOY!!\n\n\n"
           << "Based on Notes from SAM KASS (http://www.samkass.com/theories/RPSSL.html)\n\n\n\n";
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

void rpsls::rock(int computer){
  std::string outcome;
  std::string pc;
  switch(computer){
    case 1:
        outcome = "It is a tie";
        pc = "Rock";
        break;
    case 2:
    	pc_wins_counter();
        outcome = "Computer wins";
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
        outcome = "Computer wins!";
        pc = "Spock";
        break;
    default:
        std::cout <<"Invalid Input!<<std::endl";
        break;
  }
  std::cout <<"You picked Rock and the computer picked "<<pc<<"\n"<<outcome<<std::endl;
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
        outcome = "It is a tie";
        pc = "Paper";
        break;
    case 3:
    	pc_wins_counter();
        outcome = "Computer wins!";
        pc = "Scissors";
        break;
    case 4:
    	pc_wins_counter();
        outcome = "Computer wins";
        pc = "Lizard";
        break;
    case 5:
    	player_wins_counter();
        outcome = "You have won, congratulations!";
        pc = "Spock";
        break;
    default:
        std::cout <<"Invalid Input!<<std::endl";
        break;
  }
  std::cout <<"You picked Paper and the computer picked "<<pc<<"\n"<<outcome<<std::endl;
}//When user is Paper

void rpsls::scissors(int computer){
  std::string outcome;
  std::string pc;
  switch(computer){
    case 1:
    	pc_wins_counter();
        outcome = "Computer Wins";
        pc = "Rock";
        break;
    case 2:
    	player_wins_counter();
        outcome = "You have won, congratulations!";
        pc = "Paper";
        break;
    case 3:
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
        outcome = "Computer wins";
        pc = "Spock";
        break;
    default:
        std::cout <<"Invalid Input!<<std::endl";
        break;
  }
  std::cout <<"You picked Scissors and the computer picked "<<pc<<"\n"<<outcome<<std::endl;
}//When user is scissors

void rpsls::lizard(int computer){
  std::string outcome;
  std::string pc;
  switch(computer){
    case 1:
    	pc_wins_counter();
        outcome = "Computer wins";
        pc = "Rock";
        break;
    case 2:
    	player_wins_counter();
        outcome = "You have won, congratulations!";
        pc = "Paper";
        break;
    case 3:
    	pc_wins_counter();
        outcome = "Computer wins";
        pc = "Scissors";
        break;
    case 4:
        outcome = "It is a tie";
        pc = "Lizard";
        break;
    case 5:
    	player_wins_counter();
        outcome = "You have won, congratulations!";
        pc = "Spock";
        break;
    default:
        std::cout <<"Invalid Input!<<std::endl";
        break;
  }
  std::cout <<"You picked Lizard and the computer picked "<<pc<<"\n"<<outcome<<std::endl;
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
        outcome = "Computer wins";
        pc = "Paper";
        break;
    case 3:
    	player_wins_counter();
        outcome = "You have won, congratulations!";
        pc = "Scissors";
        break;
    case 4:
    	pc_wins_counter();
        outcome = "Computer wins";
        pc = "Lizard";
        break;
    case 5:
        outcome = "It is a tie";
        pc = "Spock";
        break;
    default:
        std::cout <<"Invalid Input!<<std::endl";
        break;
  }
  std::cout <<"You picked Spock and the computer picked "<<pc<<"\n"<<outcome<<std::endl;
}//When the user is spock

void rpsls::overall_score(){
  int plays = get_plays();
  int player = get_player_wins();
  int pc = get_pc_wins();
  std::string result = " ";
  if(player>pc){
    std::cout<< "Out of the "<<plays<< "matches played:\n"
	         << "\tYou won "<<player<<" matches\n"
	         << "\tPC won "<<pc<<" matches\n"
			 << "You are the overall WINNER of all the plays, CONGRATULATIONS!"
			 <<std::endl;
  }else if(player == pc){
    std::cout<< "Out of the "<<plays<< "matches played:\n"
	         << "\tYou won "<<player<<" matches\n"
	         << "\tPC won "<<pc<<" matches\n"
			 << "It was a TIE, BETTER LUCK NEXT TIME!"
			 <<std::endl;
  }else{
    std::cout<< "Out of the "<<plays<< "matches played:\n"
	         << "\tYou won "<<player<<" matches\n"
	         << "\tPC won "<<pc<<" matches\n"
			 << "You are the overall LOOSER of all the plays, BETTER LUCK NEXT TIME!"
			 <<std::endl;
  }
}
