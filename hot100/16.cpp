//
// Created by mumansk on 25-7-19.
//
# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;


void print_vec(vector<int>& nums) {
    for (auto ele : nums) {
        cout << ele << " ";
    }
    cout << endl;
    return;
}


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> ans(len);

        vector<int> dp_front(len, nums[0]); // 从头开始
        vector<int> dp_back(len, nums[len-1]); // 从尾开始


        for (int i = 1; i < len; i++) {
            dp_front[i] = dp_front[i-1] * nums[i];
            int back_pos = len - 1 - i;
            dp_back[back_pos] = dp_back[back_pos + 1] * nums[back_pos];
        }

        cout << endl;
        print_vec(dp_front);
        print_vec(dp_back);

        // 初始化
        ans[0] = dp_back[1];
        ans[len-1] = dp_front[len - 2];
        for (int i = 1; i < len-1; i++) {
            ans[i] = dp_front[i-1] * dp_back[i+1];
        }

        return ans;
    }
};



int main() {
    vector<int> nums = {-1,1,0,-3,3};
    Solution s;
    vector<int> ans = s.productExceptSelf(nums);
    for (auto i : ans) {
        cout<<i<<" ";
    }
    return 0;
}