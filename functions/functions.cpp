#include "functions.h"
#include <random>
#include <cstdlib>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

int randomize(int start, int end) {

    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> distrib(start, end);

    return  distrib(gen);
}

void clear () {

    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void sleep() {
    #ifdef _WIN32
        Sleep(3000);
    #else
        sleep(3);
    #endif
}