/*
   
   2P Game collection 

   1: player1	-1: player2
 

   Game.cpp
 */

#include <iostream>
#include "./TicTacToe/TicTacToe.h"

using namespace std;

class Game
{
	public:
		void start();
		void showMenu();
		void play(unsigned int gameType);
		void exit();
		
		bool state;

		unsigned int currentGameNumber;

		Game(){ state = true; }
		~Game(){ cout << "[*] Exit Program " << endl; }
};

void Game::showMenu()	// choose game what you want to play.
{
	system("clear");
	cout << "= = = GAME MENU = = = = =" << endl;
	cout << "1. TicTacToe" << endl;
	cout << "2. Comming soon !" << endl;
	cout << "	...	" << endl;
	cout << "= = = = = = = = = = = = =" << endl;
	cout << "select number : ";
	cin >> this->currentGameNumber;
};

void Game::start()	
{
	this->showMenu();	
	play(currentGameNumber);
};

void Game::play(unsigned int gameType)
{
	switch(gameType){
		case 1:{	// TicTacToe
			TicTacToe ttc;
			ttc.playGame();
			break;
		       }
		default:cout << "Game not found x_x" << endl;
			break;
	}
}

int main()
{
	Game game;
	cout << "current Game Number is " << game.currentGameNumber << endl;

	char continueAnswer;

	while(game.state){
		do{
			game.start();
			cout << "continue ? (y/n) " << endl;
			cin >> continueAnswer;
		}while(continueAnswer != 'y' && continueAnswer != 'n');
		if(continueAnswer == 'y') game.state = true;
		else game.state = false;
	}

	return 0;
}
