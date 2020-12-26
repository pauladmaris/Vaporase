#include"UI.h"
#include <iostream>
#include <ctime>
using namespace std;


void UI::showUI() {
	bool gata = false;
	bool stop = false;
	while (!gata) {
		cout << endl;
		cout << " --------------" << endl;
		cout << " |    MENIU    |" << endl;
		cout << " --------------" << endl;
		cout << endl;
		cout << "Optiuni: " << endl;
		cout << "	1. Add boat" << endl;
		cout << "	2. Add boards" << endl;
		cout << "	3. Show player board" << endl;
		cout << "	4. Show computer board" << endl;
		cout << "	5. Play the game" << endl;
		cout << "	6. Exit " << endl;
		cout << "Alegeti optiunea:  ";
		int opt;
		cin >> opt;
		cout << endl;
		switch (opt) {
		case 1: {addElem(); break; }
		case 2: {addBoards(); break; }
		case 3: {showBoardPlayer(); break; }
		case 4: {showBoardComputer(); break; }
		case 5: {play(); break; }
		case 6:	{gata = true; cout << "BYE BYE..." << endl; }
		}
	}
}

void UI::addBoards() {
	addComputerBoard();
	addPlayerBoard();
}

void UI::play() {
	bool ok = true;
	int contor_player = 1;
	int contor_computer = 1;
	cout << endl;
	while (true)
	{
		cout << endl;
		cout << "      <----->\n";
		cout << "  <------------->\n";
		cout << "<--- YOUR TURN ---> \n";
		cout << "  <------------->\n";
		cout << "      <----->\n";
		cout << endl;

		
		/*int option2;
		cout << "Doriti sa vedeti tabla adversarului?\n";
		cout << "1. Da\n";
		cout << "2. Nu\n";
		cin >> option2;
		if (option2 == 1)
			showBoardComputer();*/

		cout << "Introduceti coordonatele: " << endl;;
		int x;
		char y;
		cout << "x (1,2,..,10): ";
		cin >> x;
		cout << "y (a,b,..j,A,B,..,J): ";
		cin >> y;
		int int_y;
		int_y = transform(y);
		if (serv.getItemFromPosComputer(x - 1, int_y - 1) == "x")
		{
			if (contor_player == serv.getNrX_computer())
			{
				ok = false;
				cout << endl;
				cout << "---------------------------------\n";
				cout << "         !!! YOU WON !!!         \n";
				cout << "---------------------------------\n";
				cout << endl;
				break;
			}
			else
			{
				serv.setSpaceComputer(x - 1, int_y - 1);
				cout << endl;
				cout << "Felicitari, ati nimerit o parte din vapor!\n";
				contor_player++;
			}
		}
		else
			cout << "Nu ati nimerit niciun vapor...\n";
		cout << endl;
		cout << ">------------------------------------------------------------------------------------------<\n";
		cout << endl;
		cout << "COMPUTER's TURN: \n";
		if (serv.computerMove() == true) 
		{
			if (contor_computer == serv.getNrX_player())
			{
				ok = false;
				cout << "COMPUTER WON!!!";
				break;
			}
			else
			{
				cout << "!!! Computerul v-a lovit o parte din vapor...\n";
				cout << endl;
				contor_computer++;
			}
		}
		if (serv.computerMove() == false)
		{
			cout << "   ...  ";
			cout << endl;
		}
	}
	
}

int UI::transform(char c) {
	switch (c) {
	case 'A': {return 1; }
	case 'B': {return 2; }
	case 'C': {return 3; }
	case 'D': {return 4; }
	case 'E': {return 5; }
	case 'F': {return 6; }
	case 'G': {return 7; }
	case 'H': {return 8; }
	case 'I': {return 9; }
	case 'J': {return 10; }
	case 'a': {return 1; }
	case 'b': {return 2; }
	case 'c': {return 3; }
	case 'd': {return 4; }
	case 'e': {return 5; }
	case 'f': {return 6; }
	case 'g': {return 7; }
	case 'h': {return 8; }
	case 'i': {return 9; }
	case 'j': {return 10; }
	}
}

void UI::addPlayerBoard() {
	Vapor c(1, 0, 3, "dreapta");
	serv.addVaporPlayer(c);
	Vapor c1(3, 2, 5, "jos");
	serv.addVaporPlayer(c1);
	Vapor c2(4, 6, 2, "stanga");
	serv.addVaporPlayer(c2);
	Vapor c3(6, 8, 5, "sus");
	serv.addVaporPlayer(c3);
}

void UI::showBoardPlayer() {
	cout << endl;
	cout << " -------------- PLAYER BOARD -------------- " << endl << endl;
	int x = 1;
	char y = 'A';
	cout << "   ! ";
	for (int j = 0; j < 10; j++) {
		cout << y << " ! ";
		y += 1;
	}
	cout << endl;
	cout << "============================================" << endl;
	for (int i = 0; i < 10; i++) {
		if (x == 10) 
			cout << x << " ! ";
		else 
			cout << " " << x << " ! ";
		x++;
		for (int j = 0; j < 10; j++) {
			if (j > 0) {
				if (serv.getItemFromPosPlayer(i, j) == "x" && serv.getItemFromPosPlayer(i, j - 1) == "x")
				{
					cout << serv.getItemFromPosPlayer(i, j);
					cout << " | "; 
				}
				else
					if (serv.getItemFromPosPlayer(i, j) == "x" && serv.getItemFromPosPlayer(i, j - 1) != "x")
					{
						cout << serv.getItemFromPosPlayer(i, j);
						cout << " | ";
					}
				if (serv.getItemFromPosPlayer(i, j) != "x")
				{
					cout << serv.getItemFromPosPlayer(i, j);
					cout << "  | ";
				}
			}
			else
				if (serv.getItemFromPosPlayer(i, j) != "x")
				{
					cout << serv.getItemFromPosPlayer(i, j);
					cout << "  | ";
				}
				else
					if (serv.getItemFromPosPlayer(i, j) == "x")
					{
						cout << serv.getItemFromPosPlayer(i, j);
						cout << " | ";
					}

		}
		cout << endl;
		cout << "============================================" << endl;
	}
	cout << endl;
	cout << endl;
}

void UI::addComputerBoard() {
	Vapor c(0, 0, 3, "dreapta");
	serv.addVaporComputer(c);
	Vapor c1(3, 0, 3, "jos");
	serv.addVaporComputer(c1);
	Vapor c2(5, 5, 2, "stanga");
	serv.addVaporComputer(c2);
	Vapor c3(7, 8, 5, "sus");
	serv.addVaporComputer(c3);
}

void UI::showBoardComputer() {
	cout << endl;
	cout << " ------------- COMPUTER BOARD ------------- " << endl << endl;
	int x = 1;
	char y = 'A';
	cout << "   ! ";
	for (int j = 0; j < 10; j++) {
		cout << y << " ! ";
		y += 1;
	}
	cout << endl;
	cout << "============================================" << endl;
	for (int i = 0; i < 10; i++) {
		if (x == 10)
			cout << x << " ! ";
		else
			cout << " " << x << " ! ";
		x++;
		for (int j = 0; j < 10; j++) {
			if (j > 0) {
				if (serv.getItemFromPosComputer(i, j) == "x" && serv.getItemFromPosComputer(i, j - 1) == "x")
				{
					cout << serv.getItemFromPosComputer(i, j);
					cout << " | ";
				}
				else
					if (serv.getItemFromPosComputer(i, j) == "x" && serv.getItemFromPosComputer(i, j - 1) != "x")
					{
						cout << serv.getItemFromPosComputer(i, j);
						cout << " | ";
					}
				if (serv.getItemFromPosComputer(i, j) != "x")
				{
					cout << serv.getItemFromPosComputer(i, j);
					cout << "  | ";
				}
			}
			else
				if (serv.getItemFromPosComputer(i, j) != "x")
				{
					cout << serv.getItemFromPosComputer(i, j);
					cout << "  | ";
				}
				else
					if (serv.getItemFromPosComputer(i, j) == "x")
					{
						cout << serv.getItemFromPosComputer(i, j);
						cout << " | ";
					}

		}
		cout << endl;
		cout << "============================================" << endl;
	}
	cout << endl;
	cout << endl;
}

void UI::addElem() {
	int x;
	char r;
	char y;
	int l;
	string o;
	cout << "Linie: ";
	cin >> x;
	cout << "Coloana: ";
	cin >> y;
	cout << "Alegeti tipul:  a. Vas de razboi| b. Yacht| c.Submarin: ";
	cin >> r;
	switch (r) {
	case'a': {l = 5; break; }
	case 'b': {l = 3; break; }
	case 'c': {l = 2; break; }
	default:
		l = 2;
		break;
	}
	cout << "Directia: ";
	cin >> o;
	int int_y = transform(y);
	try{
		Vapor a(x - 1 , int_y - 1 , l, o);
		serv.validare(a);
		serv.addVaporPlayer(a);
		cout << "Adaugare vapor cu succes! ";
	}
	catch (ValidationException & ex) {
		cout << "Exceptii: " << ex.what() << endl;}
}

