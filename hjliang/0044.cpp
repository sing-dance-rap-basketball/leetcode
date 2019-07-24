/**
 * 44. Wildcard Matching
 * Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.
 * '?' Matches any single character.
 * '*' Matches any sequence of characters (including the empty sequence).
 * The matching should cover the entire input string (not partial).
 */

/**
 * Runtime: 40 ms, faster than 60.98% of C++ online submissions for Wildcard Matching.
 * Memory Usage: 29.5 MB, less than 19.70% of C++ online submissions for Wildcard Matching.
 * DP方法
 * 状态机方法很有意思 可以研究下
 */

class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> memo(p.size() + 1, vector<int>(s.size() + 1));
        memo[0][0] = 1;
        for(int i = 1; i <= p.size(); i++)
            memo[i][0] = p[i - 1] == '*' && memo[i - 1][0];

        for(int i = 1; i <= p.size(); i++) {
            for(int j = 1; j <= s.size(); j++) {
                if(p[i - 1] == '*')
                    memo[i][j] = memo[i - 1][j] || memo[i][j - 1];
                else if(p[i - 1] == '?' || p[i - 1] == s[j - 1])
                    memo[i][j] = memo[i - 1][j - 1];
            }
        }
        return memo.back().back();
    }
};