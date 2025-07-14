//
// Created by mumansk on 24-11-28.
//
#include <iostream>
#include <vector>
#include <unordered_map>
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


class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        vector<int> ans;
        for ( int i = 0; i < nums.size(); i++ ) {
            auto it = mp.find(target - nums[i]);
            if ( it != mp.end() ) { // 已经找到了
                ans.push_back(it->second);
                ans.push_back(i);
                return ans;
            }
            mp[nums[i]] = i;
        }
    }
};

int main() {
    vector<int> nums = {2, 7, 11, 15};
    Solution2 solu;
    vector<int> ans = solu.twoSum(nums, 9);
    for (auto i : ans) {
        cout << i << endl;
    }
    return 0;
}