//
// Created by mumansk on 24-11-28.
//
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    ans.push_back(i + 1);
                    ans.push_back(j + 1);
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {2, 7, 11, 15};
    Solution solu1;
    solu1.twoSum(nums, 9);
    for (int& i : nums) {
        cout << i << endl;
    }
    return 0;
}