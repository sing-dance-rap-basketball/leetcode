/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        int len = strs[0].size();
        auto s = strs[0];
        for(auto &str : strs) {
            for(int i=0; i<len; i++) {
                if(s[i] != str[i]) {
                    len = i;
                }
            }
        }
        return s.substr(0, len);
    }
};

