#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_map>


// Not recommended :)
using namespace std;

unordered_map<char, char> translation;
unordered_map<char, int> score_choice;
unordered_map<string, int> score_using_outcome;

int win = 6;
int tie = 3;
int loss = 0;

int calculateRoundScore(char opp, char me);
void initializeGlobals();
int calculateOutcomeFromStrategy(char opp, char needed_outcome);

int main (int argc, char** argv) {
    initializeGlobals();

    string line;
    int score = 0;

    ifstream input("input.txt");

    while (getline(input, line)) {
        char opp = line[0];
        char me = line[2];

        score += calculateOutcomeFromStrategy(opp, me);
    }
    input.close();

    cout << score << endl;
    return score;
}

void initializeGlobals() {
    translation['A'] = 'X';
    translation['B'] = 'Y';
    translation['C'] = 'Z';

    score_choice['X'] = 1;
    score_choice['Y'] = 2;
    score_choice['Z'] = 3;

    /*
    a = rock = 1
    b = paper = 2
    c = scissors = 3

    part 2
    z = win = 6
    y = draw = 3
    x = lose = 0
*/


    score_using_outcome["AX"] = 3 + 0;
    score_using_outcome["AY"] = 1 + 3;
    score_using_outcome["AZ"] = 2 + 6;
    score_using_outcome["BX"] = 1 + 0;
    score_using_outcome["BY"] = 2 + 3;
    score_using_outcome["BZ"] = 3 + 6;
    score_using_outcome["CX"] = 2 + 0;
    score_using_outcome["CY"] = 3 + 3;
    score_using_outcome["CZ"] = 1 + 6;
    
}

int calculateOutcomeFromStrategy(char opp, char needed_outcome) {
    auto combined = string(1,opp) + needed_outcome;
    cout << combined << " : " << score_using_outcome[combined] << endl;
    return score_using_outcome[combined];
}

int calculateRoundScore(char opp, char me) {
    char oppTranslation = translation[opp];

    if (oppTranslation == me) {
        return (tie + score_choice[me]);
    } else if (
        (me == 'Y' && opp == 'A') ||
        (me == 'X' && opp == 'C') ||
        (me == 'Z' && opp == 'B')
    ) {
        return (win + score_choice[me]);
    } else {
        return (loss + score_choice[me]);
    }
}