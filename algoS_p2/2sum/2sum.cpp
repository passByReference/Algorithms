#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <string>
#include <set>
using namespace std;

int main() {
    ifstream infile("2sum.txt");
    unordered_map<long long int, int> m;
    if (infile.is_open()) {
        string input;
        while (getline(infile, input)) {
            long long int value = 0;
            value = stoll(input);
            m[value] = 1;
        }
    }
    infile.close();
    int counter = 0;
    for (long long int t = -10000; t < 10001; ++t) {
        for (auto it = m.cbegin(); it != m.cend(); ++it) {
            if (m.find(t - it->first) != m.end()) {
                cout << "found " << t << endl;
                ++counter;
                break;
            }
        }
    }

    cout << "result: " << counter << endl;
}
