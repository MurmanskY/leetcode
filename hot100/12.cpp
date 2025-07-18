//
// Created by mumansk on 25-7-18.
//
# include <iostream>
# include <string>
# include <vector>

using namespace std;


void print_vec(vector<int>& v) {
    cout << "---------------" << endl;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] != 0) {
            cout << char(i + 'A') << " , freq: " << v[i] << endl;
        }
    }
    cout << "---------------" << endl;
}


class Solution {
public:
    bool contain_subchar(vector<int>& s, vector<int>& t) {
        // print_vec(s);
        // print_vec(t);
        for (int i = 0; i < t.size(); ++i) {
            if(t[i] > 0 && s[i] < t[i]) {
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        // 维护左右指针，滑动窗口
        int s_len = s.length(), t_len = t.length();
        if (s_len < t_len) {return "";}


        string ans;
        ans.reserve(s.length());
        int min_len = INT_MAX;
        vector<int> s_vocab(58, 0), t_vocab(58, 0);
        for (int i = 0; i < t_len; i++) {
            t_vocab[t[i] - 'A']++; // 初始化词频
        }
        int l = 0, r = 0;
        while (r <= s_len) {

            while (contain_subchar(s_vocab, t_vocab)) {
                // 如果包含，尝试找更短的
                int length = r - l;
                if (length <= min_len) {
                    // 如果此时的子串更短
                    ans.assign(s.data() + l, length);
                    min_len = length;
                }
                s_vocab[s[l] - 'A'] --;
                l++;
                cout << "l: " << l << endl;
            }
            if (r < s_len) {s_vocab[s[r] - 'A'] ++;}
            cout << "r: " << r << endl;
            r++;
        }

        return ans;
    }
};




int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";
    Solution solu;
    string ans = solu.minWindow(s, t);
    cout << ans << endl;
    return 0;
}