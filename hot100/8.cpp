//
// Created by mumansk on 25-7-17.
//
# include <iostream>
# include <unordered_map>
# include <unordered_set>

using namespace std;


class Solution {
public:
    // 使用hash_map，像对于使用hash_set，耗时会更长，主要时间出现在clear()操作，本质上是一个遍历所有元素的操作
    int lengthOfLongestSubstring(string s) {
        int ans = 0, left = 0, right = 0;
        int len = s.length();
        unordered_map<char, int> mp; // 存储char出现的index
        while(right < len) {
            auto it = mp.find(s[right]);
            if (it == mp.end()) {
                // map中没有找到，说明，没有出现重复
                mp[s[right]] = right;
                right++;
                ans = max(ans, right - left);
            } else {
                // 如果出现重复了，重新开始走
                left = it->second + 1;
                right = it->second + 1;
                mp.clear();
            }
        }
        return ans;
    }
};




class Solution2 {
public:
    // 使用hash_map，像对于使用hash_set，耗时会更长，主要时间出现在clear()操作，本质上是一个遍历所有元素的操作
    int lengthOfLongestSubstring(string s) {
        int ans = 0, left = 0, right = 0;
        int len = s.length();
        unordered_set<char> set; // 存储char出现的index
        for (; left < len; left++) {
            while(right < len) {
                if(set.find(s[right]) == set.end()) {
                    // 如果如果找不到
                    set.insert(s[right]);
                    right++;
                    ans = max(ans, right - left);
                } else {
                    // 如果找到了
                    break;
                }
            }
            set.erase(s[left]);
        }
        return ans;
    }
};




int main() {
    string str = "";
    Solution2 s;
    int ans = s.lengthOfLongestSubstring(str);
    cout << ans << endl;
    return 0;
}