/**
 * 问题描述：
 * 3. Longest Substring Without Repeating Characters1. Two Sum
 * Given a string, find the length of the longest substring without repeating characters.
 */

/**
 * 提交结果：
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

/**
 * 改进：和上一版Solution类似，但更明确地使用双指针方法；使用了std::unordered_map
 * 提交结果：
 * Runtime: 20 ms, faster than 65.51% of C++ online submissions for Longest Substring Without Repeating Characters. 
 * Memory Usage: 13.3 MB, less than 27.19% of C++ online submissions for Longest Substring Without Repeating Characters.
 * 很遗憾没有变快，甚至变慢了。
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        const int len = s.length();
        if (len <= 1) { return len; }

        int start = 0;
        int end = 0;
        //bool *umap = new bool(256, false);
        std::unordered_map<char, int> umap;
        std::unordered_map<char, int>::iterator got;
        while (end < len) {
            got = umap.find(s[end]);
            if (got == umap.end()) {
                //umap.insert(std::make_pair(s[end], end));
                umap[s[end]] = end;
            }
            else {
                maxLen = (maxLen < end - start) ? (end - start) : maxLen;
                int newStart = got->second + 1;
                for (int i = start; i < newStart; ++i) {
                    umap.erase(s[i]);
                }
                //umap.insert(std::make_pair(s[end], end));
                umap[s[end]] = end;
                start = newStart;
            }
            ++end;
        }
        maxLen = (maxLen < end - start) ? (end - start) : maxLen;

        return maxLen;
    }
};

/**
 * 改进：借鉴zhou diao的思路，减少无用功
 * 提交结果：
 * Runtime: 12 ms, faster than 88.97% of C++ online submissions for Longest Substring Without Repeating Characters. 
 * Memory Usage: 10.7 MB, less than 56.29% of C++ online submissions for Longest Substring Without Repeating Characters.
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        const int len = s.length();
        if (len <= 1) { return len; }

        int start = 0;
        std::unordered_map<char, int> umap;
        for (int end = 0; end < len; ++end) {
            if (umap.find(s[end]) != umap.end() && umap[s[end]] >= start) {
                start = umap[s[end]] + 1;
            }
            maxLen = (maxLen < end - start + 1) ? end - start + 1 : maxLen;
            umap[s[end]] = end;
        }

        return maxLen;
    }
};