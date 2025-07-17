//
// Created by mumansk on 25-7-17.
//
# include <iostream>
# include <vector>
# include <algorithm>
# include <string>

using namespace std;


class Solution {
public:
    // 超时 N*M*logM
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        string pattern = p;
        sort(pattern.begin(), pattern.end());
        int s_len = s.length();
        int p_len = p.length();
        for (int i = 0; i <= s_len - p_len; i++) {
            string temp = s.substr(i, p_len);
            sort(temp.begin(), temp.end());
            if(temp == pattern) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};




void print_vec(vector<int> vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
    return;
}



class Solution2 {
public:

    vector<int> findAnagrams(string s, string p) {
        int s_len = s.length();
        int p_len = p.length();
        vector<int> ans;

        if (s_len < p_len){
            return ans;
        }

        vector<int> p_vocab(26, 0);
        vector<int> s_vocab(26, 0);
        for (int i  = 0; i < p_len; i++) {
            s_vocab[s[i] - 'a'] += 1; // string的词频数组
            p_vocab[p[i] - 'a'] += 1; // pattern的词频数组
        }
        cout << endl;

        for (int i = 0; i <= s_len - p_len; i++) {
            if(s_vocab == p_vocab) {
                // 如果词频数组相同，则找到
                ans.push_back(i);
            }

            // 词频数组不相同，没有找到
            if (i + p_len >= s_len) {break;}
            s_vocab[s[i] - 'a'] -= 1;
            s_vocab[s[i+p_len] - 'a'] += 1;

        }

        return ans;
    }

};



int main() {
    string s = "cbaebabacd";
    string p = "abc";

    Solution2 solu;
    vector<int> ans = solu.findAnagrams(s, p);
    for (auto i : ans) {
        cout << i << endl;
    }

    return 0;
}