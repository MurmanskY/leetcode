//
// Created by mumansk on 25-7-21.
//
# include <iostream>
# include <vector>

using namespace std;


void print_mat(vector<vector<int>> mat) {
    for (auto row : mat) {
        for (auto col : row) {
            cout << col << " ";
        }
        cout << endl;
    }
    cout << endl;
    return;
}

void print_vec(vector<int> vec) {
    for (auto ele : vec) {
        cout << ele << " ";
    }
    cout << endl;
    return;
}


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;

        int row_start = 0, row_end = matrix.size() - 1;
        int col_start = 0, col_end = matrix[0].size() - 1;

        while (row_start <= row_end && col_start <= col_end) {
            // 从左到右
            for (int j = col_start; j <= col_end; ++j) {
                ans.push_back(matrix[row_start][j]);
            }
            row_start ++;
            // 从上到下
            for (int i = row_start; i <= row_end; ++i) {
                ans.push_back(matrix[i][col_end]);
            }
            col_end --;
            // 从右到左
            if (row_start <= row_end) {
                for (int j = col_end; j >= col_start; --j) {
                    ans.push_back(matrix[row_end][j]);
                }
                row_end --;
            }
            // 从下到上
            if (col_start <= col_end) {
                for (int i = row_end; i >= row_start; --i) {
                    ans.push_back(matrix[i][col_start]);
                }
                col_start ++;
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> matrix1 = {{1,2,3}, {4,5,6}, {7, 8, 9}};
    vector<vector<int>> matrix2 = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};

    print_mat(matrix1);

    Solution s;
    vector<int> ans = s.spiralOrder(matrix1);
    print_vec(ans);
    return 0;
}