#include <iostream>

using namespace std;

int main() {
    int p = 2;
    int* i = &p;
    int* j = i;

    cout << &i << endl;
    cout << &j << endl;

    cout << i << endl;
    cout << j << endl;

    return 0;
}
