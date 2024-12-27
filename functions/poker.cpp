#include "poker.h"
#include <unordered_map>

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

bool isRoyalFlush(const vector<int>& values, vector<int>& colors) {
    const bool isFlush = repeated(colors, 5);

    for (int i = 0; i < values.size(); i++)
        if (values[i] + 1 == values[i + 1] &&
            values[i + 1] + 1 == values[i + 2] &&
            values[i + 2] + 1 == values[i + 3] &&
            values[i + 3] + 1 == values[i + 4] &&
            values[i + 4] == 14 &&
            isFlush) return true;

    return false;
}

bool isStraight(const vector<int>& values) {
    for (int i = 0; i < values.size(); i++)
        if ((values[i] + 1 == values[i + 1] &&
            values[i + 1] + 1 == values[i + 2] &&
            values[i + 2] + 1 == values[i + 3] &&
            values[i + 3] + 1 == values[i + 4]) ||
            (values[values.size() - 1] == 14 &&
            values[i] + 1 == values[i + 1] &&
            values[i + 1] + 1 == values[i + 2] &&
            values[i + 2] + 1 == values[i + 3])) return true;

    return false;
}

bool isStraightFlush(const vector<int>& values, vector<int> &colors) {
    return repeated(colors, 5) && isStraight(values);
}
