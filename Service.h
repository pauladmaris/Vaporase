#pragma once
#include "Board.h"
#include "Exceptions.h"
#include "Validator.h"
#include <ctime>

class Service {
private:
	Board* board_player;
	Board* board_computer;
	ValidatorVapor val;
public:
	Service() {};
	Service(Board* b_p, Board* b_c) 
	{ 
		this->board_player = b_p; 
		this->board_computer = b_c; 
	};

	bool computerMove() 
	{
		int x, y; bool ok = false;
		srand(time(0));
		x = rand() % 10;
		y = rand() % 10;
		if (getItemFromPosPlayer(x, y) == "x")
		{
			setSpacePlayer(x, y);
			ok = true;
		}
		return ok;
	};
	
	vector<vector<string>> getPlayerBoard() 
	{ 
		return board_player->getBoard(); 
	};

	void setSpaceComputer(int x, int y) {
		board_computer->setSpace(x, y);
	}
	void setSpacePlayer(int x, int y) {
		board_player->setSpace(x, y);
	}

	vector<vector<string>> getComputerBoard()
	{
		return board_computer->getBoard();
	};

	string getItemFromPosPlayer(int x, int y) 
	{ 
		return board_player->getItemFromPos(x, y); 
	};

	string getItemFromPosComputer(int x, int y) 
	{ 
		return board_computer->getItemFromPos(x, y); 
	};

	int getNrX_computer() {
		return board_computer->getNrX();
	}

	int getNrX_player() {
		return board_player->getNrX();
	}

	void validare(Vapor& a) {
		int rez = 0;
		rez = val.validate(&a);
		if (rez != 0)
			throw ValidationException(val.toString());
	}

	void addVaporPlayer(Vapor& a) 
	{ 
		try 
		{
			if (val.validate(&a) == 0)
			{
				board_player->addElem(a);
			}
		}
		catch (ValidationException & ex) {
			throw ex;
		}
		
	};

	void addVaporComputer(Vapor& a) 
	{ 
		board_computer->addElem(a); 
	};
	
	~Service() {};
};

