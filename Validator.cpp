#include "Validator.h"
#include <iostream>
#include <string.h>
#include <string>
using namespace std;


ValidatorVapor::ValidatorVapor()
{
	err = 0;
	mesaj = "";
}

int ValidatorVapor::validate(Vapor* vapor)
{
	err = 0;
	mesaj = "";
	if (vapor->getX() < 0 || vapor->getX() > 9){
		err++; mesaj += "Linia trebuie sa fie cuprinsa intre [1,10]! ";
	}
	if (vapor->getY() < 0 || vapor->getY() > 9) {
		err++; mesaj += "Coloana trebuie sa fie cuprinsa intre [1,10]! ";
	}
	if (board.getItemFromPos(vapor->getX(),vapor->getY()) == "x") {
		err++; mesaj += "Exista deja un vapor pe acea pozitie! ";
	}
	return err;
}

void ValidatorVapor::showMesaj()
{
	if (mesaj != "")
	{
		cout << endl;
		cout << "--- ERORI ---: " << endl;
		cout << mesaj << endl;
		cout << endl;
	}
}

string ValidatorVapor::toString() {
	return mesaj;
}

ValidatorVapor::~ValidatorVapor()
{
}