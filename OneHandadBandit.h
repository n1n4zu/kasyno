#ifndef ONEHANDADBANDIT_H
#define ONEHANDADBANDIT_H
#include <iostream>
#include <ostream>
#include <random>

class OneHandadBandit {

    int var1 = randomize();
    int var2 = randomize();
    int var3 = randomize();

    static int randomize() {

        std::random_device rd;
        std::mt19937 gen(rd());

        std::uniform_int_distribution<> distrib(1, 5);

        return  distrib(gen);
    }

public:
    std::string play() {
        std::cout << var1 << " " << var2 << " " << var3 << std::endl;

        if (var1 == var2 && var2 == var3 && var1 == var3) {
            return "Wygrałeś!";
        } else {
            return "Przegrałeś";
        }
    }
};



#endif //ONEHANDADBANDIT_H
