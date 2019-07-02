/**
 * 问题描述
 * 3. Longest Substring Without Repeating Characters1. Two Sum
 * Given a string, find the length of the longest substring without repeating characters.
 */

/**
 * 提交结果
 * Runtime: 20 ms, faster than 65.93% of C++ online submissions for Longest Substring Without Repeating Characters.
 * Memory Usage: 13.8 MB, less than 25.70% of C++ online submissions for Longest Substring Without Repeating Characters.
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        int start = 0;  // 当前子字符串起点
        int pos;        // 当前字符位置
        int len = s.length();
        
        if (len <= 1) {
            return len;
        }
        
        for (pos = 1; pos < len; ++pos) {
            auto temp = s.substr(start, pos - start).find(s[pos]);
            if (temp != string::npos) {
                if (maxLen < pos - start) {
                    maxLen = pos - start;
                }
                start += (temp + 1);
            }
        }
        if (maxLen < pos - start) {
            maxLen = pos - start;
        }
        
        return maxLen;
    }
};