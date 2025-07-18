//
// Created by mumansk on 25-7-18.
//
# include <iostream>
# include <vector>
# include <deque>
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



class Solution2 {
    // 使用 双端队列的方法，在滑动窗口中实时维护最大值
    // 双端队列中，从头到尾，value递减
    // 有点点难理解
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> q;
        // 初始化
        for (int i = 0; i < k; i++) {
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
        }

        ans.push_back(nums[q.front()]); // 初试化

        for (int i = k; i < nums.size(); i ++) {
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);

            while(q.front() <= i - k) {
                q.pop_front();
            }
            ans.push_back(nums[q.front()]);
        }

        return ans;
    }
};




int main() {
    Solution2 solu;
    vector<int> nums = {1,3,1,2,0,5};
    vector<int> result = solu.maxSlidingWindow(nums, 3);

    for (auto i : result) {
        cout<<i<<" ";
    }

    return 0;
}