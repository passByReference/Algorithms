#include "all.h"

using namespace std;

unordered_map<int, int> m;

int climbStairs_recursion(int n) {
    if (n <= 2) return n;
    return climbStairs_recursion(n - 1) + climbStairs_recursion(n - 2);
}

int climbStairs_memo(int n) {
    if (n <= 2) {
        m[n] = n;
        return m[n];
    }
    if (m.find(n) != m.end()) return m[n];
    m[n] = climbStairs_memo(n - 1) + climbStairs_memo(n - 2);
    return m[n];

}

int climbStairs_dp(int n) {
    /* version1 with O(n)
    if (n <= 2) return n;
    vector<int> dp ={0, 1, 2};
    for (int i = 3; i <= n; ++i) {
        dp.push_back(dp[i - 1] + dp[i - 2]);
    }
    return dp.back();

    */

    // version2 with O(1)

    if (n <= 2) return n;
    int a = 1, b = 2, c = 0;
    for (int i = 3; i <= n; ++i) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main() {
    //cout << "recursion : " << climbStairs_recursion(44) << endl;
    //cout << "memo : " << climbStairs_memo(10000) << endl; // n = 10000, 0.018s
    cout << "dp : " << climbStairs_dp(10000) << endl; // n = 10000, 0.008s

    return 0;
}
