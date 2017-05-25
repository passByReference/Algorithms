#include "all.h"

int leastBricks(vector<vector<int>>& wall) {
    int height = wall.size();
    unordered_map<int, int> m;
    for (int row = 0; row < height; ++row) {
        int sum = 0;
        for (int col = 0; col < wall[row].size() - 1; ++col) {
            sum += wall[row][col];
            ++m[sum];
        }
                
    }

    int maxVal = 0;
    for (auto& rec : m) {
        if (rec.second > maxVal) {
            maxVal = rec.second;
        }
    }

    return height - maxVal;
}
