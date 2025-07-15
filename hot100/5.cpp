//
// Created by mumansk on 25-7-15.
//
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;


bool cmp(const std::pair<int,int>& a, const std::pair<int,int>& b) {
    return a.first > b.first;
}

class Solution {
    // 排序算法，n log n
public:
    int maxArea(vector<int>& height) {
        // 使用一个降序排列的map，第一个值是height，第二个值是i
        int ans = 0;
        vector<pair<int, int>> vec;
        for (int i = 0; i < height.size(); i++) {
            vec.push_back(make_pair(height[i], i));
        }
        sort(vec.begin(), vec.end(), cmp);
        int min_x = vec[0].second;
        int max_x = vec[0].second;
        for (int i = 1; i < vec.size(); i++) {
            ans = max(
                ans,
                max(
                    abs(min_x - vec[i].second),
                    abs(max_x - vec[i].second)
                ) * vec[i].first
            );
            min_x = min(min_x, vec[i].second);
            max_x = max(max_x, vec[i].second);
        }
        return ans;
    }
};








class Solution3 {
// 遍历方法，超时
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        for (int i = 0; i < height.size()-1; i++) {
            for (int j = i + 1; j < height.size(); j++) {
                ans = max(ans, min(height[i], height[j]) * (j-i));
            }
        }
        return ans;
    }
};




int main() {
    vector<int> v = {1,1};

    Solution s;
    cout << s.maxArea(v) << endl;


    return 0;
}