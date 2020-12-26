#include "Utils.h"

void coordonate(std::string p, int& x, int& y, int n, int m) {

    int poz = stoi(p);
    poz--;
    x = int(poz / n);
    y = poz % n;
}

int inputCommndRead(std::string msg) {

    int cmd;
    std::cout << std::endl << msg; std::cin >> cmd;
    if (!std::cin) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid try again\n";
        return inputCommndRead(msg);
    }
    return cmd;
}