#include "all.h"

using namespace std;

bool caseFive(int n, int i ) {
    if (n < i * i) return true;
    if (n % i == 0 || n % (i + 2) == 0)
        return false;
    else return caseFive(n, i + 6);
}

bool isPrime(int n) {
    if (n == 2) return true;
    if (n < 4) return n > 1;
    else if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    else return caseFive(n, 5);
}

int countPrimes(int n) {
    if (n == 0) return 0;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (isPrime(i)) ++cnt;
    }
    return cnt;
}

int main(){
    int input = 0;
    while (input != -1) {
        cout << "Enter a number: " << endl;
        cin >> input;
        cout << isPrime(input) << endl;
    }
    return 0;
}
