#pragma once
#include<string>
#include<iostream>
using namespace std;

class Vapor {
private:
	int x;
	int y;
	int len;
	string directie;
public:
	Vapor();
	Vapor(int x, int y, int len, string directie);
	Vapor(const Vapor& a);
	~Vapor();
	int getX();
	int getY();
	int getLen();
	string getDirectie();
	void setX(int x);
	void setY(int y);
	void setLen(int len);
	void setDirectie(string directie);
	Vapor& operator=(const Vapor& a);
	bool operator==(const Vapor&);
	friend ostream& operator<<(ostream& os, const Vapor& c);
};