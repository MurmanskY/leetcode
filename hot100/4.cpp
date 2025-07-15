//
// Created by mumansk on 25-7-15.
//
/**
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
请注意 ，必须在不复制数组的情况下原地对数组进行操作。

示例 1:
输入: nums = [0,1,0,3,12]
输出: [1,3,12,0,0]

示例 2:
输入: nums = [0]
输出: [0]

提示:
1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1
 */
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // 使用双指针，一前一后，从头开始遍历。 --> 因为需要保持相对顺序
        // 不是一头一尾，从两头开始遍历。
        int le = 0; int ri = le + 1;
        while (ri < nums.size()) {
            if (!nums[le] && nums[ri]) {
                // 如果左边为0，右边为1，互换位置；
                int temp = nums[le];
                nums[le] = nums[ri];
                nums[ri] = temp;
                // 更新指针
                le ++;
                ri ++;
            }else if (!nums[le] && !nums[ri]) {
                // 如果左边为0，右边为0，右指针往后移一位
                ri++;
            }else if (nums[le] && !nums[ri]) {
                // 如果左边为1，右边为0，左指针移动到右指针，右指针在做指针右边一个
                le = ri;
                ri ++;
            }else {
                // 如果左边为1，右边为1，左指针移动到右边的后一个，右指针在做指针右边一个
                le = ri + 1;
                ri = le + 1;
            }
        }
    }
};


class Solution2 {
    // 直接使用stl库函数
public:
    void moveZeroes(vector<int>& nums) {
        auto it = remove(nums.begin(), nums.end(), 0);
        fill(it, nums.end(), 0);
    }
};



int main() {
    vector<int> nums = {};
    Solution solu;
    solu.moveZeroes(nums);
    for (auto i : nums) {
        cout << i << endl;
    }
    return 0;
}