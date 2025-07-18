//
// Created by mumansk on 25-7-18.
//
# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;



class Solution {
    // 可能会出现超时
public:
    int find_max_pos(vector<int>& nums, int start, int end) {
        // [s, en]
        int pos = start;
        int max_ele = nums[start];
        for (int i = start; i <= end; i++) {
            if (nums[i] >= max_ele) {
                pos = i;
                max_ele = max(max_ele, nums[i]);
            }
        }
        return pos;
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int l = 0;
        int r = l + k;
        int nums_size = nums.size();
        int pos = find_max_pos(nums, l,r-1);
        ans.push_back(nums[pos]);
        while (l < nums_size-k) {
            if (nums[r] >= nums[pos]) {
                // 如果往右移，出现了一个大于等于当前区间最大值的值
                pos = r;
            }
            l ++;
            r ++; // 整体往前移动
            if (l > pos) {
                pos = find_max_pos(nums, l, r-1);
            }
            ans.push_back(nums[pos]);
        }
        return ans;
    }
};



int main() {
    Solution solu;
    vector<int> nums = {1,3,1,2,0,5};
    vector<int> result = solu.maxSlidingWindow(nums, 3);

    for (auto i : result) {
        cout<<i<<" ";
    }

    return 0;
}