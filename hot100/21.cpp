//
// Created by mumansk on 25-7-22.
//
# include <iostream>
# include <vector>

using namespace std;


class Solution {
public:
    // 对于每一行，使用二份查找
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (const auto& group : matrix) {
            // 遍历每一行vector
            auto it = lower_bound(group.begin(), group.end(), target);
            if (it != group.end() && *it == target) {
                // 找到
                return true;
            }
        }
        return false;
    }
};


class Solution2 {
public:
    // z字形查找
    // target大，x++
    // target小，y--
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int pos_row = 0, pos_col = n - 1;

        while(pos_row < m || pos_col >= 0) {
            if (matrix[pos_row][pos_col] == target) {
                return true;
            } else if (matrix[pos_row][pos_col] < target) {
                if(++pos_row >= m) {
                    break;
                }
            } else {
                if(--pos_col < 0) {
                    break;
                }
            }
        }
        return false;
    }
};






int main() {
    vector<vector<int>> matrix = {
        {1,4,7,11,15},
        {2,5,8,12,19},
        {3,6,9,16,22},
        {10,13,14,17,24},
        {18,21,23,26,30}
    };
    int target = 5;

    Solution2 s;
    bool ans = s.searchMatrix(matrix, target);

    if (ans) {
        cout << "true" << endl;
    }else {
        cout << "false" << endl;
    }

    return 0;
}