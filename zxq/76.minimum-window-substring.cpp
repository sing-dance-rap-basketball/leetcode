/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 *
 * https://leetcode.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (39.49%)
 * Likes:    11333
 * Dislikes: 550
 * Total Accepted:    807K
 * Total Submissions: 2M
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * Given two strings s and t of lengths m and n respectively, return the
 * minimum window substring of s such that every character in t (including
 * duplicates) is included in the window. If there is no such substring, return
 * the empty string "".
 * 
 * The testcases will be generated such that the answer is unique.
 * 
 * A substring is a contiguous sequence of characters within the string.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "ADOBECODEBANC", t = "ABC"
 * Output: "BANC"
 * Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C'
 * from string t.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "a", t = "a"
 * Output: "a"
 * Explanation: The entire string s is the minimum window.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "a", t = "aa"
 * Output: ""
 * Explanation: Both 'a's from t must be included in the window.
 * Since the largest window of s only has one 'a', return empty string.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == s.length
 * n == t.length
 * 1 <= m, n <= 10^5
 * s and t consist of uppercase and lowercase English letters.
 * 
 * 
 * 
 * Follow up: Could you find an algorithm that runs in O(m + n) time?
 */

// @lc code=start

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Accepted
    // 266/266 cases passed (12 ms)
    // Your runtime beats 86.85 % of cpp submissions
    // Your memory usage beats 68.7 % of cpp submissions (7.7 MB)
    string minWindow(string s, string t) {
        vector<bool> is_exist(128, 0);  // t中每个字符存在与否
        vector<int> n_chars(128, 0);    // 每个字符t中数量减去当前s子串中数量

        for (char c : t) {
            is_exist[c] = true;
            n_chars[c]++;
        }

        int l = 0, r = 0;
        int min_l = 0, min_len = s.size() + 1;
        int cnt = 0;    // 当前子字符串包含了t中多少个字符
        for (r = 0; r < s.size(); ++r) {
            if (is_exist[s[r]]) {
                if (n_chars[s[r]]-- > 0) {
                    cnt++;
                }
            }

            while (cnt == t.size()) {
                if (r - l + 1 < min_len) {
                    min_l = l;
                    min_len = r - l + 1;
                }
                if (is_exist[s[l]]) {
                    if (n_chars[s[l]]++ >= 0) {
                        cnt--;
                    }
                }
                l++;
            }
        }
        return min_len > s.size() ? "" : s.substr(min_l, min_len);
    }
};
// @lc code=end

