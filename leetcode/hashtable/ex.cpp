#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    unordered_map<int, string> m;
    for (int i = 0; i < 10; ++i) {
        cout << m[i] << endl;
    }

    for (int i = 0; i < m.size(); ++i) cout << i << " " << m[i] << endl;
    return 0;
}
