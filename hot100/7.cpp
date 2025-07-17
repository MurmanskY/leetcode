//
// Created by mumansk on 25-7-16.
//
#include <iostream>
#include <vector>

using namespace std;





class Solution {
public:
    int trap(vector<int>& height) {
        // 动态规划
        int ans = 0;
        vector<int> left_max(height.size(), 0); // [1, n]
        vector<int> right_max(height.size(), 0); // 【0, n-1】
        left_max[0] = height[0];
        for (int i = 1; i < height.size(); i++) {
            left_max[i] = max(left_max[i-1], height[i]);
        }
        right_max[height.size()-1] = height[height.size()-1];
        for (int i = right_max.size()-2; i >= 0; i--) {
            right_max[i] = max(right_max[i+1], height[i]);
        }
        for (int i = 0; i < height.size(); i++) {
            ans += min(left_max[i], right_max[i]) - height[i];
        }
        return ans;
    }
};



int main() {

    vector<int> heights = {0,1,0,2,1,0,1,3,2,1,2,1};

    Solution s;
    int ans = s.trap(heights);

    cout << ans << endl;

    return 0;
}