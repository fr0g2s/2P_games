// TicTacToe.cpp

#include <iostream>
#include "TicTacToe.h"

bool isValid(unsigned int pos_x, unsigned int pos_y){ return (0<=pos_x && pos_x<MAPSIZE && 0<=pos_y && pos_y<MAPSIZE); } 
 
void TicTacToe::initGame()
{
	turn = 1;
	gameState = true;
	for(int i=0;i<MAPSIZE;i++){
		for(int j=0;j<MAPSIZE;j++) gameMap[i][j] = 0;
	}
}

void TicTacToe::playGame()
{
	unsigned x, y;

	while(gameState){
		drawMap(gameMap);
		
		if(turn == 1) cout << "-- player1 --" << endl;
		else cout << "-- player2 -- " << endl;

		do{
			cin.clear();
			cout << "x, y = ";
			cin >> x >> y;
		}while(!isValid(x, y) || gameMap[x][y]!=0);
		gameMap[x][y] = turn;
		this->gameState = checkingWin(turn);

		turn = turn*-1;
	}
	drawMap(gameMap);

	cout << "!! Game Over !!" << endl;
	cout << "Winner is " << (turn==-1?"player1":"player2") << endl << endl << endl;
}

bool TicTacToe::checkingWin(int turn){
	int sum;

	// horizontal
	for(int i=0;i<MAPSIZE;i++){
		sum = 0;
		for(int j=0;j<MAPSIZE;j++) sum += gameMap[i][j];
		if(sum == turn*MAPSIZE) return false;
	}
	
	// vertical
	for(int i=0;i<MAPSIZE;i++){
		sum = 0;
		for(int j=0;j<MAPSIZE;j++) sum += gameMap[j][i];
		if(sum == turn*MAPSIZE) return false;
	}

	// cross: left top - right down
	sum = 0;
	for(int i=0;i<MAPSIZE;i++){
		sum += gameMap[i][i];
	}
	if(sum == turn*MAPSIZE) return false;

	// cross: right top - left down
	sum = 0;
	for(int i=0;i<MAPSIZE;i++){
		sum += gameMap[i][i-MAPSIZE-1];
	}
	if(sum == turn*MAPSIZE) return false;

	// no bingo
	return true;
}

void TicTacToe::showBanner()
{
	cout << " _____ _        _____            _____      	    	    " << endl;
	cout << "|_   _(_)      |_   _|          |_   _|            	    " << endl;
	cout << "  | |  _  ___    | | __ _  ___    | | ___   ___    	    " << endl;
	cout << "  | | | |/ __|   | |/ _` |/ __|   | |/ _ \\ / _ \\ 	    " << endl;
	cout << "  | | | | (__    | | (_| | (__    | | (_) |  __/   	    " << endl;
	cout << "  \\_/ |_|\\___|   \\_/\\__,_|\\___|   \\_/\\___/ \\___|   " << endl;
}


