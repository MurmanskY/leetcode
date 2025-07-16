//
// Created by mumansk on 25-7-16.
//
/*
给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请你返回所有和为 0 且不重复的三元组。
注意：答案中不可以包含重复的三元组。

示例 1：
输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]
解释：
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
注意，输出的顺序和三元组的顺序并不重要。

示例 2：
输入：nums = [0,1,1]
输出：[]
解释：唯一可能的三元组和不为 0 。

示例 3：
输入：nums = [0,0,0]
输出：[[0,0,0]]
解释：唯一可能的三元组和为 0 。

提示：
3 <= nums.length <= 3000
-105 <= nums[i] <= 105
 */
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
    // 排序加map，需要仔细处理，多个相同值的区间（区间边界和区间内）
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        map<int, int> mp; // key为value，

        for (int i = 0; i < nums.size(); i++) {
            if (mp.find(nums[i]) == mp.end()) { // 之前没有出现过
                mp[nums[i]] = 1;
            } else {
                mp[nums[i]] += 1;
            }
        }

        // for (auto it = mp.begin(); it != mp.end(); it++) {
        //     cout << it->first << " " << it->second << endl;
        // }

        // cout << endl;

        map<int, int>::iterator it1 = mp.begin();
        map<int, int>::iterator it2 = it1;
        if (it1->second == 1) {
            // 如果第一个值只有一个，那么右指针往后移
            it2 = next(mp.begin(), 1);
        }


        while (it1 != mp.end()) {
            int a = it1->first;
            while (it2 != mp.end()) {
                int b = it2->first;
                int c = -(a + b); // c 为确定的值

                if (c == b) {
                    // 如果 c的值和b的值相同
                    auto it3 = mp.find(c);
                    if (it3 != mp.end()) {

                        if ((it3->second == 2 && b != a) || it3->second > 2) {
                            // int c 找到了
                            vector<int> tmp = {a, b, c};
                            ans.push_back(tmp);
                        }

                    }
                }

                if (c > b) {
                    // 只能往后找
                    auto it3 = mp.find(c);
                    if (it3 != mp.end()) {
                        // 如果找到了合适的值
                        vector<int> tmp = {a, b, c};
                        ans.push_back(tmp);
                    }
                }
                // 不管有没有找到对应的值，右指针都需要向后移
                it2 = next(it2, 1);
            }

            it1 = next(it1, 1);
            if (it1->second > 1) {
                // 如果左指针对应的值至少有两个
                it2 = it1;
            } else {
                it2 = next(it1, 1);
            }
        }

        return ans;
    }
};



int main() {
    vector<int> nums = {0,0,0};

    Solution solu;

    vector<vector<int>>ans = solu.threeSum(nums);

    for (auto group : ans) {
        for (auto i : group) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}