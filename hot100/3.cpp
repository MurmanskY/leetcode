//
// Created by mumansk on 25-7-15.
//
/*
给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
请你设计并实现时间复杂度为 O(n) 的算法解决此问题。

示例 1：
输入：nums = [100,4,200,1,3,2]
输出：4
解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。

示例 2：
输入：nums = [0,3,7,2,5,8,4,6,0,1]
输出：9

示例 3：
输入：nums = [1,0,1,2]
输出：3

提示：
0 <= nums.length <= 105
-109 <= nums[i] <= 109
 */
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> set;

        for (auto num : nums) {

            if (set.find(num) == set.end()) {
                // 在set中没有出现；放进去
                set.insert(num);

            }
        }

        for (auto it = set.begin(); it != set.end(); it ++) {
            if (set.find((*it) - 1) == set.end()) {
                // 不能找到更小的，说明是起点
                int len = 1;
                while(set.find((*it) + len) != set.end()) { // 如果值往上找可以找到，那么长度可以增加
                    len ++;
                }
                ans = max(len, ans);
            }
        }

        return ans;
    }
};



int main() {
    vector<int> nums = {};
    Solution solu;
    int ans = solu.longestConsecutive(nums);
    cout << ans << endl;
    return 0;
}