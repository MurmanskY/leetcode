//
// Created by mumansk on 25-7-14.
//
/*
给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。字母异位词是通过重新排列不同单词或短语的字母而形成的单词或短语，并使用所有原字母一次。

示例 1:
输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
解释：
在 strs 中没有字符串可以通过重新排列来形成 "bat"。
字符串 "nat" 和 "tan" 是字母异位词，因为它们可以重新排列以形成彼此。
字符串 "ate" ，"eat" 和 "tea" 是字母异位词，因为它们可以重新排列以形成彼此。

示例 2:
输入: strs = [""]
输出: [[""]]

示例 3:
输入: strs = ["a"]
输出: [["a"]]

提示：
1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] 仅包含小写字母
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
using namespace std;

class Solution {
    //  使用unordered_map收集排序后的string
    public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;
        for (auto str : strs) {
            vector<string> str_vec;
            string temp = str;
            sort(temp.begin(), temp.end());
            auto it = mp.find(temp);
            if (it != mp.end()) {
                // 存储过
                str_vec = it->second;
            }
            str_vec.push_back(str);
            mp[temp] = str_vec;
        }

        for (auto it = mp.begin(); it != mp.end(); it++) {
            ans.push_back(it->second);
        }

        return ans;
    }
};


class Solution2 {
    //  使用unordered_map收集映射后的字符串
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<vector<int>, vector<string>> mp;
        for (auto str : strs) {
            vector<int> str_hash(26, 0);
            vector<string> str_set;
            for (auto ch : str) {
                str_hash[ch - 'a'] += 1;
            }

            auto it = mp.find(str_hash);
            if (it != mp.end()) {
                // 非空
                str_set = it->second;
            }

            str_set.push_back(str);
            mp[str_hash] = str_set;
        }

        for (auto it = mp.begin(); it != mp.end(); it++) {
            ans.push_back(it->second);
        }

        return ans;
    }
};




int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution2 solu;
    vector<vector<string>> ans = solu.groupAnagrams(strs);
    for (auto group : ans) {
        for (auto str : group) {
            cout << str << " ";
        }
        cout << endl;
    }
    return 0;
}