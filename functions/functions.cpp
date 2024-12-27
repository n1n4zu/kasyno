#include "functions.h"
#include <random>
#include <cstdlib>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

int randomize(const int start, const int end) {

    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<> distrib(start, end);

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