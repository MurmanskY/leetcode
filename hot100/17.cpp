//
// Created by mumansk on 25-7-20.
//
# include <iostream>
# include <vector>

using namespace std;


void print_vec(vector<int>& nums) {
    for (auto num : nums) {
        cout << num << " ";
    }
    cout << endl;
    return;
}


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int ans = 0;

        int nums_len = nums.size();

        for (int i = 0; i < nums_len; i++) {
            if (nums[i] <= 0) {
                nums[i] = nums_len + 1;
            }
        }

        print_vec(nums);

        for (int i = 0; i < nums_len; i++) {
            int v = abs(nums[i]);         // ← 取绝对值，恢复“原始”标记前的数
            if (v >= 1 && v <= nums_len) {
                nums[v-1] = -abs(nums[v-1]);
            }
        }



        print_vec(nums);

        for (; ans < nums_len; ans++) {
            if (nums[ans] > 0) {
                return ans + 1;
            }
        }

        return nums_len + 1;
    }
};


int main() {
    vector<int> nums{1};
    Solution s;
    int ans = s.firstMissingPositive(nums);
    cout << ans << endl;
    return 0;
}