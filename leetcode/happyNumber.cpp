#include "all.h"

bool isHappy (int n) {
    if (n == 1) return true;
    static int cnt = 0;
    ++cnt;
    if (cnt > 10) return false;
    int total = 0;
    while (n != 0) {
        total += pow(n % 10, 2.0);
        n /= 10;
    }
    std::cout << "new n = " << total << " cnt = " << cnt << std::endl;
    n = total;
    return isHappy(n);
}
int main () {
    srand(time(NULL));
    int n = rand() % 101 + 1;
    std::cout << n << std::endl;
    std::cout << isHappy(7) << std::endl;
    return 0;

}
