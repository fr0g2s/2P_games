// TicTacToe.h

#include <iostream>
#include "../textGUI/textGUI.h"

using namespace std;

class TicTacToe
{	
	public:
		void initGame();
		void showBanner();
		void playGame();
		bool checkingWin(int turn);

		int gameMap[MAPSIZE][MAPSIZE];

		int turn;
		bool gameState;

		TicTacToe(){ this->initGame(); };
		~TicTacToe() { };
};
