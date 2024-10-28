#ifndef ONEHANDADBANDIT_H
#define ONEHANDADBANDIT_H
#include <iostream>
#include <ostream>
#include "functions.h"

using namespace std;

class OneHandadBandit {

    int var1 = randomize(1, 5);
    int var2 = randomize(1, 5);
    int var3 = randomize(1, 5);

public:
    string play() {
        cout << var1 << " " << var2 << " " << var3 << endl;

        if (var1 == var2 && var2 == var3 && var1 == var3) {
            return "Wygrałeś!";
        } else {
            return "Przegrałeś";
        }
    }
};



#endif //ONEHANDADBANDIT_H
