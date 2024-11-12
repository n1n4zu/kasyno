#ifndef ONEHANDEDBANDIT_H
#define ONEHANDEDBANDIT_H
#include "../functions/functions.h"

using namespace std;

class OneHandedBandit {

    // Losowanie wartości na automacie
    int var1 = randomize(1, 5);
    int var2 = randomize(1, 5);
    int var3 = randomize(1, 5);

public:
    void play() const;
};



#endif //ONEHANDEDBANDIT_H
