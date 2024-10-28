#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <random>
#include <cstdlib>

static int randomize(int start, int end) {

    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> distrib(start, end);

    return  distrib(gen);
}

static void clear () {
    try {
        system("clear");
    } catch (...) {
        system("cls");
    }
}

#endif //FUNCTIONS_H
