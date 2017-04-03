#include <iostream>
#include <vector>
using namespace std;

void dutchFlagPartition(vector<int>& vec, int x) {
    /*
     * - vec[i] < pivot: exchange vec[i] and vec[smaller], increment i and smaller
     * - vec[i] > pivot: exchange vec[i] and vec[larger], decrement larger. Notice that we don't increment i here because, vec[larger] has not
     *   been compared with pivot yet. In the case above, sicne i = smaller in the beginning, vec[smaller] has been compared with pivot already
     *   through vec[i]
     * - vec[i] == pivot: increment i
     */
    int pivot = vec[x];
    int i = 0;
    int smaller = 0;
    int larger = vec.size() - 1;
    while (i <= larger) {
        if (vec[i] > pivot) {
            swap(vec[i], vec[larger--]);
        }
        else if (vec[i] < pivot) {
            swap(vec[i++], vec[smaller++]);
        }
        else ++i;
    }
    
}

int main() {
    vector<int> vec = {0, 1, 2, 0, 2, 1, 1};
    dutchFlagPartition(vec, 3);
    for (auto v : vec) {
        cout << v <<", ";
    }
    cout << endl;
    return 0;
}
