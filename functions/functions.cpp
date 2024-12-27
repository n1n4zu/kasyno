#include "functions.h"
#include <random>
#include <cstdlib>
#include <vector>
#include <unordered_map>

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

using namespace std;

int randomize(const int start, const int end) {

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

bool repeated(vector<int>& values, const int n) {
    unordered_map<int, int> count;

    for (int num : values) if (++count[num] == n) return true;

    return false;
}

bool repeatedPairs(vector<int>& values, int n) {
    unordered_map<int, int> count;

    for (int num : values) ++count[num];

    int pair_count = 0;

    for (const auto& [key, value] : count) if (value == n) ++pair_count;

    return pair_count == 2;
}

bool isFull(vector<int>& values) {
    unordered_map<int, int> count;
    const bool isThree = repeated(values, 3);

    for (int num : values) ++count[num];

    int counter = 0;

    for (const auto& [key, value] : count) {
        if (value == 2) ++counter;
        else if (value == 3) ++counter;
    }

    return isThree && counter == 2;
}

bool isRoyalFlush(const vector<int> &values, vector<int> &colors) {
    const bool isColor = repeated(colors, 5);

    for (int i = 1; i < values.size(); i++) {
        if (values[i] + 1 == values[i + 1] &&
            values[i + 1] + 1 == values[i + 2] &&
            values[i + 2] + 1 == values[i + 3] &&
            values[i + 3] + 1 == values[i + 4] &&
            values[i + 4] == 14 &&
            isColor) return true;
    }

    return false;
}
