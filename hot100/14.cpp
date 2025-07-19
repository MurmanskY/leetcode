//
// Created by mumansk on 25-7-18.
//
# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;


bool cmp(const vector<int>& a, const vector<int>& b) {
    if (a[0] != b[0]) {
        return a[0] < b[0];
    } else {
        return a[1] < b[1];
    }

}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        vector<vector<int>> v = intervals;
        sort(v.begin(), v.end(), cmp); // 排序

        for (auto group : v) {
            cout << group[0] << " " << group[1] << endl;
        }
        cout << endl;

        int start = v[0][0];
        int end = v[0][1];
        for (int i = 1; i < v.size(); i++) {
            cout << "1  start: " << start << ", end: " << end << endl;
            // 从第二个位置开始遍历
            if (v[i][0] <= end) {
                // 连上了
                end = max(end, v[i][1]); //  不断扩大end
                cout << "2  start: " << start << ", end: " << end << endl;
            } else {
                // 隔开了
                cout << "3  start: " << start << ", end: " << end << endl;
                ans.push_back(vector<int>{start, end});
                start = v[i][0];
                end = v[i][1];
                cout << "4  start: " << start << ", end: " << end << endl;
            }
            cout << endl;
        }
        ans.push_back(vector<int>{start, end}); // 初始化操作


        return ans;
    }
};


int main() {
    vector<vector<int>> intervals = {{2, 3}, {4, 5}, {6, 7}, {8, 9}, {1, 10}};
    Solution s;
    vector<vector<int>> ans = s.merge(intervals);
    for (auto group : ans) {
        cout << group[0] << " " << group[1] << endl;
    }


    return 0;
}