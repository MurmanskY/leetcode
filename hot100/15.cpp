//
// Created by mumansk on 25-7-19.
//
# include <iostream>
# include <vector>

using namespace std;

void print_viod(vector<int>& nums) {
    for (auto a : nums) {
        cout << a << " ";
    }
    return;
}


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> temp_front; //
        vector<int> temp_back; // 长度为k的nums的后部数组
        k %= nums.size();
        temp_back.assign(nums.begin() + nums.size() - k, nums.end());
        temp_front.assign(nums.begin(), nums.begin() + nums.size() - k);
        temp_back.insert(temp_back.end(), temp_front.begin(), temp_front.end());
        nums.swap(temp_back);
        return;
    }
};


int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    vector<int> nums2 = {-1};
    int k = 3;
    Solution s;
    s.rotate(nums2, 0);
    for (int i = 0; i < nums2.size(); i++) {
        cout << nums2[i] << " ";
    }
    return 0;
}