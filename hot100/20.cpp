//
// Created by mumansk on 25-7-22.
//
# include <iostream>
# include <vector>
# include <algorithm>

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


class Solution {
public:
    // 矩阵转置+左右轴反转
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // 转置
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                cout << i << j << endl;
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        print_mat(matrix);

        // 左右翻转
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n / 2; j++) {
                swap(matrix[i][j], matrix[i][n - 1 - j]);
            }
        }
        print_mat(matrix);

    }
};

int main() {
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Solution s;
    s.rotate(matrix);
    print_mat(matrix);
    return 0;
}