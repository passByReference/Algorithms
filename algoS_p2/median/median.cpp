#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <functional>

using namespace std;
/*
Step 1: Add next item to one of the heaps, if next item is smaller than maxHeap root add it to maxHeap,
      else add it to minHeap

Step 2: Balance the heaps (after this step heaps will be either balanced or
         one of them will contain 1 more item)

    - if number of elements in one of the heaps is greater than the other by
    more than 1, remove the root element from the one containing more elements and
    add to the other one

Then at any given time you can calculate median like this:

- If the heaps contain equal amount of elements;
    median = (root of maxHeap + root of minHeap)/2
  Else
    median = root of the heap with more elements
*/

int main() {
    ifstream infile("Median.txt");
    if (infile.is_open()) {
        int input = 0;
        priority_queue<int, vector<int>, less<int>> left;
        priority_queue<int, vector<int>, greater<int>> right;
        int total = 0;
        while (infile >> input) {
            if (!left.empty() && input <= left.top()) {
                left.push(input);
            }
            else if (!right.empty() && input >= right.top()) {
                right.push(input);
            }
            else {
                right.push(input);
            }

            cout << "left size(): " << left.size() << " right size(): " << right.size() << endl;
            // size() returns an unsigned integer which could cause undefined behavior
            if (left.size() > right.size() && left.size() - right.size() > 1) {
                right.push(left.top());
                left.pop();
            }
            if (right.size() > left.size() && right.size() - left.size() > 1) {
                left.push(right.top());
                right.pop();
            }

            int median = 0;
            if (left.size() == right.size()) {
                cout << left.top() << endl;
                median = left.top();
            }
            else if (left.size() > right.size()) {
                cout << left.top() << endl;
                median = left.top();
            }
            else {
                cout << right.top() << endl;
                median = right.top();
            }
            total += median;
        }
        cout << "module: " << total % 10000 << endl;
    }
    infile.close();

    return 0;
}
