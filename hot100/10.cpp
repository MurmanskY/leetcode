//
// Created by mumansk on 25-7-17.
//
# include <iostream>
# include <vector>
# include <unordered_map>

using namespace std;


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        int pre = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i ++) {
            pre += nums[i];
            if (pre == k) { // 刚好到此和为k
                ans += 1;
            }
            auto it = mp.find(pre - k);
            if (it == mp.end()) {
                // 没有找到，skip
            } else {
                // 找到了
                ans += it -> second;
            }
            auto it_mp = mp.find(pre);
            if (it_mp == mp.end()) {
                mp[pre] = 1;
            } else {
                mp[pre] += 1;
            }
        }
        return ans;
    }
};


int main() {
    vector<int> nums = {1,1,1};
    int k = 2;
    Solution s;
    int ans = s.subarraySum(nums, k);
    cout << ans << endl;
    return 0;
}