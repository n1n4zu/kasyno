#include "OneHandedBandit.h"
#include <iostream>

using namespace std;

void OneHandedBandit::play() const {
    cout << var1 << " " << var2 << " " << var3 << endl;

    var1 == var2 && var2 == var3 && var1 == var3 ? cout << "Wygrałeś!" << endl : cout << "Przegrałeś" << endl;
}