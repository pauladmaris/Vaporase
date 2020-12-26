#pragma once
#include "Board.h"
#include "Vapor.h"
#include "Exceptions.h"

class ValidatorVapor
{
private:
	int err;
	string mesaj;
	Board board;
	Vapor* vapor;
public:
	ValidatorVapor();
	int validate(Vapor* vapor);
	void showMesaj();
	string toString();
	~ValidatorVapor();
};