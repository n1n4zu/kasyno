#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <vector>

using namespace std;

// Losowanie liczby całkowitej w podanym zakresie
int randomize(int start, int end);

// Czyszczenie konsoli przy sprawdzeniu systemu operacyjnego
void clear();

// Czekanie na ruch
void sleep();

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

#endif //FUNCTIONS_H