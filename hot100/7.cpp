//
// Created by mumansk on 25-7-16.
//
#include <iostream>
#include <vector>
#include <stack>

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








class Solution2 {
public:
    int trap(vector<int>& height) {
        // 双指针，一次遍历
        int l = 0, r = height.size() - 1; // 双指针
        int l_max = 0, r_max = 0, ans = 0;
        while (l < r) {
            if (height[l] < height[r]) {
                l_max = max(l_max, height[l]);
                ans += l_max - height[l];
                l++;
            } else {
                r_max = max(r_max, height[r]);
                ans += r_max - height[r];
                r--;
            }
        }
        return ans;
    }
};



class Solution3 {
public:
    int trap(vector<int>& height) {
        // 单调栈
        int ans = 0;
        stack<int> stk_index;
        stk_index.push(0);
        for (int i = 1; i < height.size(); i++) {
            while(!stk_index.empty() && height[stk_index.top()] < height[i]) {
                int water_index = stk_index.top();
                stk_index.pop();
                if (stk_index.empty()) {break;} // 没有左边界了
                ans += (min(height[stk_index.top()], height[i]) - height[water_index]) * (i - stk_index.top() - 1);
            }
            stk_index.push(i);
        }
        return ans;
    }
};





int main() {
    vector<int> heights = {4,2,0,3,2,5};

    Solution3 s;
    int ans = s.trap(heights);

    cout << ans << endl;

    return 0;
}