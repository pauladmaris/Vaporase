#pragma once
#include "Service.h"
#include "Exceptions.h"
#include "Validator.h"
#include <iostream>
using namespace std;

class UI {
private:
	Service serv;
public:
	UI() {};
	UI(Service serv) { this->serv = serv; };
	void showUI();
	void addBoards();
	void showBoardPlayer();
	void showBoardComputer();
	void addElem();
	void addComputerBoard();
	void addPlayerBoard();
	void play();
	int transform(char);
	~UI() {};
};

