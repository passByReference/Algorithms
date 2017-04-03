#include<iostream>
#include<climits>
#include<string>
#include<stdlib.h>
#include<time.h>
#include<vector>
#include<algorithm>
using namespace std;

int removeElement(vector<int> &nums, int val){
    sort(nums.begin(), nums.end());
    int counter = 0;
    bool met = false;
    vector<int>::iterator first;
    for(auto it = nums.begin(); it != nums.end(); ++it){
        if(*it == val && !met){
            first = it;
            met = true;
            ++counter;
        }
        else if(*it == val && met){
            ++counter;
        }
    }
    nums.erase(first, first + counter);
    if(nums.empty()) return 0;
    return nums.size();
}


bool search (vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    auto start = nums.begin();
    auto end = nums.end();
    decltype(nums.begin()) mid = start + nums.size() / 2;
    while (start != end) {
        if (*mid == target) return true;
        else if (target < *mid) {
            cout << target << " < " << *mid << endl;
            end = mid;
            mid = start + (mid - start) / 2;
        }
        else {
            cout << target << " > " << *mid << endl;
            start = mid;
            mid = mid + (end - mid) / 2;
        }
    }
    return false;
}

void merge (vector<int>& nums1, decltype(nums1.size()) m, 
            vector<int>& nums2, decltype(nums2.size()) n){
    if (nums1.empty() || nums2.empty()) return;
    auto it1 = nums1.begin();
    auto it2 = nums2.begin();
    while (it1 != nums1.end() && it2 != nums2.end()) {
        if (*it2 <= *it1) {
            it1 = nums1.insert(it1, *it2);
            ++it2;
            ++it1;
        }
        else ++it1;
    }
    
    if (it1 == nums1.end() && it2 != nums2.end()) {
        //nums1.reserve(nums1.cend(), distance(it2, nums2.cend()));
        nums1.insert(nums1.end(), it2, nums2.end());
    }
    for (auto n : nums1) cout << n << ", ";
    cout << endl;
    cout << nums1.size() << endl;
}

int longestConsecutive (vector<int> &nums){
    if (nums.empty()) return 0;
    if (nums.size() == 1) return 1;
    sort(nums.begin(), nums.end());
    for (auto i : nums) cout << i << ",";
    cout << endl;
    int max_len = 1;
    unsigned i = 1;
    int cnt = 1;
    while (i < nums.size()) {
        if (nums[i] == nums[i - 1] + 1) {
            ++cnt;
        }
        else if (nums[i] == nums[i - 1]) {
            cnt = cnt;
        }
        else {
            if (cnt > max_len) max_len = cnt;
            cnt = 1;
        }
        ++i;
    }
    if (cnt > max_len) max_len = cnt;
    return max_len;
}

vector<int> searchRange(vector<int> &nums, int target) {
    int cnt = 0;
    unsigned i = 0;
    for (; i < nums.size(); ++ i){
        if (nums[i] == target) ++cnt;
        if (nums[i] > target) break;
    }
    vector<int> result;
    if (cnt > 0) {
        result.push_back(i - cnt);
        result.push_back(i - 1);
    }
    else {
        result.push_back(-1);
        result.push_back(-1);
    }
    return result;
}

bool canJump (vector<int>& nums) {
    if (nums.empty()) return false;
    auto size = nums.size();
    unsigned i = 0;
    while(i < size) {
        if (nums[i] >= size - i - 1) return true;
        if (nums[i] == 0) return false;
        i += nums[i];
    }
    return true;
}

int firstMissingPositive (vector<int>& nums) {
    if (nums.empty()) return 1;
    bool isOne = false;
    int reserve = -1;
    int left = -1, mid = -1, right = -1;
    for (int i = 0; i < nums.size(); ++i){
        if (nums[i] > 0) {
            if ((i - 1) >= 0 ) {
                if (nums[i] == nums[i - 1]) continue;
            }
            cout << nums[i] << " "
                 << left << " "
                 << mid << " "
                 << right << endl;
            if (nums[i] == right){
                if (left == -2) {//-2 means invalid, ex 0
                    mid = nums[i];
                    right = mid + 1;
                    left = -3; // -3 means already in the list
                    continue;
                }
                else {
                    right = right + 1;
                    continue; // still waiting for left
                }
            }
            else if (nums[i] == left) {
                mid = nums[i];
                left = mid - 1;
            }
            else if (nums[i] == mid) continue;
            else if (nums[i] > right && right > 0) {
                if (nums[i] == (right + 1)) reserve = nums[i] + 1;
                continue;
            } 
            else if ((nums[i] + 1) == mid && left == -3) continue;
           // else if ((i - 1) >= 0) {
             //   if (nums[i] == nums[i - 1]) continue;
           // }
            else {
                if (isOne && nums[i] == 1 && i != 0) continue;
                mid = nums[i];
                left = mid - 1;
                if ((i + nums.size()) == right) reserve = right;
                right = mid + 1;
            }
            if (left < 1) left = -2;
        }
        if (nums[i] == 1) isOne = true;
        
    }
    if (left > 0 && isOne) return left;
    else if (left > 0 && (!isOne)) return 1;
    else if (right > 0) {
        if ((reserve - right) == 1) return reserve;
        else return right;
    }
    else {
        return 1;
    }
}

int firstMissingPositive2(vector<int>& nums) {
    
}



int removeDuplicates2(vector<int>& nums) {
    if (nums.empty()) return 0;
    if (nums.size() < 4) {
        if (nums[nums.size() - 1] == nums[0]) {
            nums.pop_back();
            return nums.size();
        }
        return nums.size();
    }
    for (unsigned i = nums.size() - 1; i > 1; --i) {
        int current = nums[i];
        int prev1 = nums[i - 1];
        int prev2 = nums[i - 2];
        if (current == prev1 && prev1 == prev2) {
            nums.erase(nums.begin() + i);
        }
    }
    return nums.size();
}

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> result;
    if (numRows == 0) return result;
    vector<int> vec1{1};
    result.push_back(vec1);
    if (numRows == 1) {
        return result;
    }
    vector<int> vec2{1,1};
    result.push_back(vec2);
    if (numRows == 2) {
        return result;
    }
    int row = 1;
    while (row <= numRows - 2) {
        vector<int> vec{1};
        vector<int> temp = result.back();
        for (int j = 0; j < temp.size() - 1; ++j) {
            int val = temp[j] + temp[j + 1];
            vec.push_back(val);
        }
        vec.push_back(1);
        result.push_back(vec);
        ++row;
    }
    return result;
}

vector<int> plusOne(vector<int>& digits) {
    /*
    if (digits.empty()) {
        digits.push_back(1);
        return digits;
    }
    unsigned i = digits.size() - 1;
    digits[i] += 1;
    if (digits[i] > 9) {
        digits[i] -= 10;
        unsigned j = i - 1;
        while (digits[j] + 1 > 9 && j >= 0) {
            digits[j] += 1;
            digits[j] -= 10;
            --j;
        }
        digits[j] += 1;
    }
    return digits;
    */
    vector<int> result{0};
    result.insert(result.end(), digits.cbegin(), digits.cend());
    unsigned i = result.size() - 1;
    result[i] += 1;
    if (result[i] > 9) {
        result[i] -= 10;
        unsigned j = i - 1;
        while (result[j] + 1 > 9 && j >= 0) {
            result[j] += 1;
            result[j] -= 10;
            --j;
        }
        result[j] += 1;
    }
    if (result[0] == 0) {
        result.erase(result.begin());
        return result;
    }
    return result;

}

vector<int> reverse(vector<int> nums) {
    vector<int> result;
    for (auto it = nums.end() - 1; it >= nums.begin(); --it) {
        result.push_back(*it);
        cout << *it << endl;
    }
    return result;
}

int minSubArrayLen(int s, vector<int>& nums) {
    if (nums.empty()) return 0;
    unsigned i = 0, min_val = nums.size();
    vector<int> result;
    vector<int> final_result;
    bool found = false;
    for (; i < nums.size() - 1; ++i) {
        result.clear();
        result.push_back(nums[i]);
        if (nums[i] >= s) return 1;
        for (unsigned j = i + 1, sum = nums[i]; 
                sum < s && j < nums.size(); ++j) {
            sum += nums[j];
            result.push_back(nums[j]);
            if (sum >= s) {
                cout << min_val << " " << i << " " << j << endl;
                if (j - i + 1 < min_val) {
                    found = true;
                    min_val = j - i + 1;
                    cout << "im here " << min_val << endl;
                    final_result.clear();
                    final_result = result;
                }
                break;
            }
        }
    }
    for (auto e : final_result) {
        cout << e << endl;
    }
    if (found)
        return min_val;
    return 0;
}
int minSubArrayLen2 (int s, vector<int> nums) {
    if (nums.empty()) return 0;
    unsigned size = nums.size();
    unsigned start = 0, end = 0, sum = 0, min_val = size;
    bool found = false;
    while (true) {
        if (sum < s) {
            if (end >= size) break;
            sum += nums[end];
            cout << "sum < s " << " end = " << end << " nums[end] = " <<
                nums[end] << " sum = " << sum << endl;
            ++end;
        }
        else {
            if (start > end) break;
            min_val = min (end - start, min_val);
            found = true;
            sum -= nums[start];
            cout << "sum >= s " << " start = " << start << 
                " end = " << end 
                << " nums[start] = " << nums[start] 
                << " nums[end] = " << nums[end]
                << " sum = " << sum << endl;
            ++start;
        }
    }
    if (found)
        return min_val;
    return 0;
}

int trap(vector<int>& height) {
    if (height.empty()) return 0;
    int maxHeight = 0, maxIdx = 0;
    int vol = 0;
    unsigned size = height.size();
    for (unsigned i = 0; i < size; ++i) {
        if (height[i] > maxHeight) {
            maxHeight = height[i];
            maxIdx = i;
        }
    }

    int prevHeight = 0;
    for (unsigned i = 0; i < maxIdx; ++i) {
        if (height[i] > prevHeight) {
            prevHeight = height[i];
        }
        vol += (prevHeight - height[i]);
    }

    prevHeight = 0;

    for (unsigned i = size - 1; i > maxIdx; --i) {
        if (height[i] > prevHeight) {
            prevHeight = height[i];
        }
        vol += (prevHeight - height[i]);
    }
    
    return vol;
}

unsigned selectClosest(vector<int> nums, int target, int m) {
    int gap = INT_MAX;
    unsigned chosen_index = 0;
    for (unsigned i = 0; i < nums.size(); ++i) {
        if (abs(nums[i] - target) < gap) {
            gap = abs(nums[i] - target);
            chosen_index = i;
        }
    }
    return chosen_index;
}

int threeSumClosest(vector<int>& nums, int target) {
    if (nums.empty()) return 0;
    unsigned size = nums.size();
    vector<int> result;
    sort(nums.begin(), nums.end());
    int m = 0;
    while (m < 3) {
        unsigned i = selectClosest(nums, target, m);
        result.push_back(nums[i]);
        target -= nums[i];
        cout << nums[i] << endl;
        int temp = nums[i];
        nums[i] = nums.back();
        nums.back()  = temp;
        nums.pop_back();
        ++m;
    }
    int total = 0;
    for (auto e : result) {
        total += e;
    }
    return total;
}

int maxProfit2(vector<int>& prices) {
    if (prices.empty()) return 0;
    unsigned max = 0, buy = 0, sell = 0;
    bool up = false, down = false;
    for (unsigned i = 1; i < prices.size(); ++i) {
        if (prices[i] > prices[i - 1] && !up) {
            buy = i - 1;
            up = true;
            down = false;
        }
        if (prices[i] < prices[i - 1] && !down) {
            sell = i - 1;
            up = false;
            down = true;
            max += prices[sell] - prices[buy];
        }
    }
    if (buy < prices.size() && up) {
        sell = prices.size() - 1;
        max += prices[sell] - prices[buy];
    }
    return max;
}

int maxProfit3(vector<int>& prices) {
   if (prices.empty()) return 0;
   unsigned min = 0, maxDiff = 0, diff = 0, sell = 0, buy = 0;
   unsigned maxProfit = 0;
   for (unsigned i = 0; i < prices.size(); ++i) {
       if (prices[i] < prices[min]) {
           min = i;
       }
       diff = prices[i] - prices[min];
       if (diff > maxDiff) {
           maxDiff = diff;
           buy = min;
           sell = i;
       }
   }
   cout << "maxDiff1 = " << maxDiff << endl;
   cout << "buy1 = " << buy << " sell1 = " << sell << endl;
   maxProfit += maxDiff;
   min = 0;
   maxDiff = 0;
   for (unsigned i = 0; i < prices.size(); ++i) {
       if (i == buy || i == sell || (min == buy || min == sell)) continue;
       if (prices[i] < prices[min]) {
           min = i;
       }
       cout << "i = " << i << " min = " << min << endl;
       diff = prices[i] - prices[min];
       if (diff > maxDiff) {
           maxDiff = diff;
           buy = min;
           sell = i;
       }
   }
   cout << "maxDiff2 = " << maxDiff << endl;
   cout << "buy2 = " << buy << " sell2 = " << sell << endl;
   maxProfit += maxDiff;
   return maxProfit;
}

vector<int> productExceptSelf(vector<int>& nums) {
    unsigned n = nums.size();
    vector<int> result(n, 1);
    for (unsigned i = 1; i < n; ++i) {
        result[i] = result[i - 1] * nums[i - 1];
        //result[i - 1] is like a left = 1 
    }
    int right = 1;
    for (int i = n - 1; i >= 0; --i) {
        result[i] *= right;
        right *= nums[i];
        cout << result[i] << " " << nums[i] << endl;
    }

    return result;
}

int main(){
    srand(time(NULL));
    vector<int> nums;
    while (nums.size() < 50) { nums.push_back(rand() % 1000); }
    vector<int> nums1;
    while (nums1.size() < 50) { nums1.push_back(rand() % 1000); }
    vector<int> nums2 = {4,1,2};
    vector<int> nums3 = {3,2,6,5,0,3};
    //2,1,3,4,4,3,1,1
    //1
    //1,4,2,0,3,4,2,4,2
    //cout << removeElement(nums1, 5);
    //cout << search(nums1, 4) << endl;
    sort(nums.begin(), nums.end());
    sort(nums1.begin(), nums1.end());
    //merge(nums2, nums.size(), nums3, nums1.size());
    //cout << "longest consecutive length: " << longestConsecutive(nums3) << endl;
    //for (auto i : searchRange(nums2, 10)) cout << i << endl;
    //cout << canJump(nums3) << endl;
    //cout << firstMissingPositive(nums3) << endl;
    //cout << maxProfit(nums3) << endl;
    //vector<int> nums4 = {1,1,1,1};
    //cout << removeDuplicates2(nums4) << endl;
    /*
    vector<vector<int>> result = generate(10);
    for (auto v : result) {
        for (auto e : v) {
            cout << e << " ";
        }
        cout << endl;
    }
    vector<int> nums5 {0};
    vector<int> result = plusOne(nums5);
    for (auto e : result) {
        cout << e;
    }
    cout << endl;
    */
    vector<int> nums5 {1, 1};
    auto result =  productExceptSelf(nums5);
    for (auto n : result) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}
