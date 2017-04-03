#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class fib {
    public:
        fib() = default;
        int compute_fib(int n);
    private:
        unordered_map<int, int> vec;
};
int fib::compute_fib(int n){
    if (n == 1) return 1;
    if (n == 2) return 1;
    if (vec[n] != 0) return vec[n];
    else vec[n] = compute_fib(n - 1) + compute_fib(n - 2);
    return vec[n];
}

int main() {
    fib *f = new fib();
    cout << f->compute_fib(39) << endl;
    return 0;
}
