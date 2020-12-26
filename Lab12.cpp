// Lab12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include "Board.h"
#include"Service.h"
#include"UI.h"
int main()
{
    Board* b1 = new Board();
    Board* b2 = new Board();
    Service s(b1, b2);
    UI ui(s);
    ui.showUI();
    delete b1;
    delete b2;
}