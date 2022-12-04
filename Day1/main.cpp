#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

// Not recommended :)
using namespace std;

int main (int argc, char* argv[]) {
    string value;
    int running_sum = 0;
    vector<int> all_elves;

    ifstream input("input.txt");

    while (getline(input, value)) {
        if (value == "") {
            all_elves.push_back(running_sum);
            running_sum = 0;
        } else {
            running_sum += stoi(value);
        }
    }
    input.close();

    sort(all_elves.begin(), all_elves.end(), greater<int>());
    cout << all_elves[0]+all_elves[1]+all_elves[2];
    return 0;
}