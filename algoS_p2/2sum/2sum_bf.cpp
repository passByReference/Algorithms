#include <iostream>
#include <fstream>
#include <vector>
#include <set>
using namespace std;

int main() {
    ifstream infile("2sum.txt");
    vector<long long int> m;
    if (infile.is_open()) {
        string input;
        while (getline(infile, input)) {
            long long int value = 0;
            value = stoll(input);
            m.push_back(value);
        }
    }
    infile.close();
    set<long long int> s;
    int counter = 0;
    for (long long int i = 0; i < m.size(); ++i) {
        for (long long int j = i + 1; j < m.size(); ++j) {
            long long int total = m[i] + m[j];
            if (total >= -10000 && total <= 10000) {
                cout << "found " << total << endl;
                s.insert(total);
            }
        }
    }

    cout << "result: " << s.size() << endl;
}
