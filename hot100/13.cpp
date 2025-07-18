//
// Created by mumansk on 25-7-18.
//
# include <iostream>
# include <vector>
using namespace std;



class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // 前缀和，动态规划
        int ans = INT_MIN;
        int nums_len = nums.size();
        int min_pos = 0; // 动态维护，指向最小的pre_sum
        vector<int> pre_sum(nums_len + 1, 0); // 为了算法一致性，下标从-1开始
        for (int nums_idx = 0; nums_idx < nums_len; nums_idx++) {
            pre_sum[nums_idx + 1] = pre_sum[nums_idx] + nums[nums_idx];
            if (pre_sum[nums_idx] <= pre_sum[min_pos]) {
                min_pos = nums_idx;
            }
            ans = max(ans, pre_sum[nums_idx+1] - pre_sum[min_pos]);
        }
        return ans;
    }
};


int main() {
    vector<int> nums = {-2,-2,-1,1};
    Solution s;
    int ans = s.maxSubArray(nums);
    cout << ans << endl;
    return 0;
}
