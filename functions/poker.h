#ifndef POKER_H
#define POKER_H

#include <vector>

using namespace std;

// Sprawdza czy liczba występuje n razy
bool repeated(vector<int>& values, int n);

// Sprawdza czy występują pary
bool repeatedPairs(vector<int>& values, int n);

// Sprawdza czy jest ful
bool isFull(vector<int>& values);

// Sprawdza czy jest poker królewski
bool isRoyalFlush(const vector<int>& values, vector<int>& colors);

// Sprawdza czy jest strit
bool isStraight(const vector<int>& values);

// Sprawdza czy jest poker
bool isStraightFlush(const vector<int>& values, vector<int>& colors);

#endif //POKER_H
