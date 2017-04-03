/*
 * The problems in this program are from Data Structures and Algorithms 
 * Made Easy. P387 Dynamic Programming
 */
#include "all.h"

using namespace std;
class dp {
    public:
        dp() = default;
        int dp_f(int n);
    private:
        std::unordered_map<int, int> m;
};

int dp::dp_f(int n) {
    m[0] = m[1] = 2;
    for (int i = 3; i <= n; ++i) {
        m[i] = m[i - 1] + 2 * m[i - 1] * m[i - 2];
    }

    return m[n];
}

int f(int n) {
    int sum = 0;
    if (n < 2) return 2;
    for (int i = 0; i < n; ++i) {
        sum += 2 * f(i) * f(i - 1);
    }
    return sum;
}

int LIS(vector<int> vec) {
    vector<int> LISTable(vec.size(), 1);
    int max = 0;
    for (unsigned i = 0; i < vec.size(); ++i) {
        for (unsigned j = 0; j < i; ++j) {
            if (vec[i] > vec[j] && LISTable[i] < LISTable[j] + 1){
                LISTable[i] = LISTable[j] + 1;
            }
        }
    }

    for (unsigned i = 0; i < LISTable.size(); ++i) {
        if (max < LISTable[i]) max = LISTable[i];
    }
    cout << "LISTable: " << endl;
    for (auto i : LISTable) cout << i << ",";
    cout << endl;
    return max;
}

bool subsetSum(vector<int> vec, int sum) {
    if (sum == 0) return true;
    if (vec.empty() && sum != 0) return false;

    if (vec.back() > sum) {
        vec.pop_back();
        return subsetSum(vec, sum);
    }
    else {
        int curr = vec.back();
        vec.pop_back();
        return subsetSum(vec, sum)
            || subsetSum(vec, sum - curr);
    }
}

bool findPartition(vector<int> vec) {
    int sum = 0;
    for (auto v : vec) {
        sum += v;
    }
    if (sum % 2 != 0) return false;
    else return subsetSum(vec, sum / 2);
}
template <typename T>
void print_matrix(vector<vector<T>> matrix) {
    if (matrix.empty()) {
        cout << "empty matrix" << endl;
        return;
    }
    for (auto row : matrix) {
        for (auto e : row) {
            cout << e << " ";
        }
        cout << endl;
    }
}
void print_arr(vector<vector<bool>> arr, int m, int n) {
    if (m < 0 || n < 0) return;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
bool findPartition2 (vector<int> vec) {
    int sum = 0;
    for (auto v : vec) {
        sum += v;
    }
    int n = vec.size();
    if (sum % 2 != 0) return false;
    vector<vector<bool>> part;
    //bool part[(sum / 2) + 1][n + 1];
    for (int i = 0; i < (sum / 2) + 1; ++i) {
        vector<bool> newVec(n + 1);
        part.push_back(newVec);
    }
    for (int i = 0; i <= n; ++i)
        part[0][i] = true;
    for (int i = 1; i <= sum / 2; ++i) {
        part[i][0] = false;
    }

    for (int i = 1; i <= sum / 2; ++i) {
        for (int j = 1; j <= n; ++j) {
            part[i][j] = part[i][j - 1];
            if (i >= vec[j- 1]) {
                part[i][j] = part[i][j]
                          || part[i - vec[j - 1]][j - 1];
            }
            print_arr(part, sum / 2 + 1, n + 1);
            cout <<"i   j   vec[j - 1]" << endl;
            cout << i << "  " << j << "  " << vec[j - 1] << endl;
        }
    }
    return part[sum / 2][vec.size()];

}

int min(int a, int b , int c) {
    int min = a;
    if (min > b) min = b;
    if (min > c) min = c;
    return min;
}
void SubmatrixWithAllOnes(vector<vector<int>> M) {
    unsigned max_of_s, max_i, max_j;
    const unsigned R = M.size();
    const unsigned C = M[0].size();
    vector<vector<int>> S;
    for (unsigned i = 0; i < R; ++i) {
        vector<int> newVec(C);
        S.push_back(newVec);
    }
    for (unsigned i = 0; i < R; ++i) {
        S[i][0] = M[i][0];
    }
    for (unsigned j = 0; j < C; ++j) {
        S[0][j] = M[0][j];
    }

    for (int i = 1; i < R; ++i) {
        for (int j = 1; j < C; ++j) {
            if (M[i][j] == 1)
                S[i][j] = min(S[i][j-1], S[i - 1][j], S[i - 1][j - 1]) + 1;
            else
                S[i][j] = 0;
        }
    }
    /* Find the maximum entry, and indexes of maximum entry
     * in S[][] */
    max_of_s = S[0][0]; max_i = 0; max_j = 0;
    for (unsigned i = 0; i < R; ++i) {
        for (unsigned j = 0; j < C ; ++j) {
            if (max_of_s < S[i][j]) {
                max_of_s = S[i][j];
                max_i = i;
                max_j = j;
            }
        }
    }

    cout << endl;
    cout << "Helper Matrix: " << endl;
    for (auto v : S) {
        for (auto e : v) {
            cout << e << " ";
        }
        cout << endl;
    }
    cout << "Maimum size sub-matrix is: " << endl;
    for (unsigned i = max_i; i > max_i - max_of_s; --i) {
        for (unsigned j = max_j; j> max_j - max_of_s; --j) {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
}

int min (int a, int b) {
    return a > b? b : a;
}

int minPathSum(vector<vector<int>>& grid) {
    if (grid.empty()) return 0;
    vector<vector<int>> m(grid);
    int min_val = grid[0][0];
    unsigned i, j;
    for (i = 0; i < grid.size(); ++i) {
        for (j = 0; j < grid[0].size(); ++j) {
            if (i == 0 && j != 0) {
                m[i][j] += m[i][j - 1];
            }
            if (i != 0 && j == 0) {
                m[i][j] += m[i - 1][j];
            }
            if (i != 0 && j != 0) {
                m[i][j] += min(m[i - 1][j], m[i][j - 1]);
            }
        }
    }
    if (i > 0 && j > 0) {
        return m[i - 1][j - 1];
    }
    else
        return min_val;
}

int climbStairs(int n) {
    if (n <= 0) return 0;
    return 1 + climbStairs(n - 1) + climbStairs(n - 2);
}
inline int max(int a, int b) {
    return a > b? a : b;
}
int rob(vector<int>& nums) {
    if (nums.empty()) return 0;
    vector<vector<int>> matrix;
    for (unsigned i = 0; i <= nums.size(); ++i) {
        vector<int> vec (nums.size() + 1, 0);
        matrix.push_back(vec);
    }
    for (unsigned i = 1; i <= nums.size(); ++i) {
        for (unsigned j = 1; j <= nums.size(); ++j) {
            if (i == 1) matrix[i][j] = nums[j];
            else if (j == 1) matrix[i][j] = nums[i];
        }
    }
    print_matrix(matrix);
    unsigned i = 1, j = 1;
    for (; i <= nums.size(); ++i) {
        for (; j <= nums.size(); ++j) {
            if (abs(i - j) > 2) continue;
            matrix[i][j] += max(matrix[i - 1][j], matrix[i][j - 1]);
        }
    }
    return matrix[i][j];
}
int main() {
    //vector<int> vec{10, 22, 9, 33, 21, 50, 41, 60, 80};
    vector<int> vec{5,6,2,3,4,1,9,9,8,9,5};
    cout << LIS(vec) << endl;
    vector<int> vec1{1,5,11,5};
    //cout << "subset sum?" << endl;
    //cout << findPartition2(vec1) << endl;
    srand(time(NULL));
    int m = rand() % 5 + 2;
    int n = rand() % 5 + 2;
    vector<vector<int>> matrix;
    for (int i = 0; i < m; ++i) {
        vector<int> newVec(n);
        matrix.push_back(newVec);
    }
    /*
    for (auto &v : matrix) {
        for (auto &e : v) {
            e = rand() % 2;
        }
    }
    cout << "Matrix generated: " << endl; 
    for (auto v : matrix) {
        for (auto e : v) {
            cout << e << " ";
        }
        cout << endl;
    }
    //SubmatrixWithAllOnes(matrix);
    for (auto &v : matrix) {
        for (auto &e : v) {
            e = rand() % 11;
        }
    }
    
    cout << "Matrix generated: " << endl; 
    for (auto v : matrix) {
        for (auto e : v) {
            cout << e << " ";
        }
        cout << endl;
    }
    cout << minPathSum(matrix) << endl;
    cout << climbStairs(20) << endl;
    */
    cout << rob(vec) << endl;
    return 0;

} 
