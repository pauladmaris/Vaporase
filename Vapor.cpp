#include"Vapor.h"

Vapor::Vapor() {
	//cout << "const implicit";
	this->x = 0;
	this->y = 0;
	this->len = 0;
	this->directie = { '\0' };

}Vapor::Vapor(int x, int y, int len, string directie) {
	//cout << "constructor with param" << endl;
	this->x = x;
	this->y = y;
	this->len = len;
	this->directie = directie;
}
Vapor::Vapor(const Vapor& a) {
	//cout << "copy constructor" << endl;
	this->x = a.x;
	this->y = a.y;
	this->len = a.len;
	this->directie = a.directie;
}
Vapor::~Vapor() {
	//cout << "Destructor";
	this->x = 0;
	this->y = 0;
	this->len = 0;
	this->directie = { '\0' };
}
int Vapor::getX() {

	return this->x;
}
int Vapor::getY() {

	return this->y;
}
int Vapor::getLen() {
	return this->len;
}
string Vapor::getDirectie() {

	return this->directie;
}
void Vapor::setX(int x) {

	this->x = x;
}
void Vapor::setY(int y) {
	this->y = y;
}

void Vapor::setLen(int len) {
	this->len = len;
}
void Vapor::setDirectie(string directie) {

	this->directie = directie;

}Vapor& Vapor::operator=(const Vapor& a) {

	this->setX(a.x);
	this->setY(a.y);
	this->setLen(a.len);
	this->setDirectie(a.directie);
	return *this;
}
bool Vapor::operator==(const Vapor& a) {

	return (this->x == a.x) && (this->y == a.y) && (this->directie.compare(a.directie) == 0);
}
ostream& operator<<(ostream& os, const Vapor& a) {

	os << "Coordonata X: " << a.x << "|" << " Coordonata Y: " << a.y << "|" << " Orientare coada:" << a.directie;
	return os;
}