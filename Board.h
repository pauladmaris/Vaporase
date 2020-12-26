#pragma once
#include<vector>
#include "Vapor.h"
using namespace std;

class Board {
private:
	vector<vector<string> > matrice;
	int x;
public:
	Board() {
		vector < vector<string> > Matr(20, vector<string>(20));
		matrice = Matr;
		x = 0;
	};

	~Board() {};

	vector < vector<string> >getBoard() {
		return this->matrice;
	};

	void setSpace(int x, int y) {
		matrice[x][y] = "";
	}

	string getItemFromPos(int x, int y) {
		return matrice[x][y];
	};

	int getNrX() {
		return x;
	}

	void addElem(Vapor& a)
	{
		x += a.getLen();
		if (a.getDirectie() == "sus")
		{
			if ((a.getX() >= 0) && (a.getY() >= 0) && (a.getX() - a.getLen() + 1 >= 0))
			{
				for (int i = a.getX() - a.getLen() + 1; i <= a.getX(); i++) {
					matrice[i][a.getY()] = "x";
				}
			}
		}
		if (a.getDirectie() == "stanga") {
			if ((a.getX() >= 0) && (a.getY() - a.getLen() + 1 >= 0) && (a.getY() >= 0)) 
			{
				for (int i = a.getY() - a.getLen() + 1; i <= a.getY(); i++) {
					matrice[a.getX()][i] = "x";
				}
			}
		}
		if (a.getDirectie() == "dreapta") 
		{
			if ((a.getX() <= 10) && (a.getY() + a.getLen() - 1 <= 10) && (a.getY() <= 10)) 
			{
				for (int i = a.getY(); i < a.getY() + a.getLen(); i++) {
					matrice[a.getX()][i] = "x";
				}
			}
		}
		if (a.getDirectie() == "jos")
		{
			if ((a.getX() <= 10) && (a.getX() + a.getLen() - 1<= 10) && (a.getY() <= 10))
			{
				for (int i = a.getX(); i < a.getX() + a.getLen(); i++) {
					matrice[i][a.getY()] = "x";
				}
			}
		}
	};
};

