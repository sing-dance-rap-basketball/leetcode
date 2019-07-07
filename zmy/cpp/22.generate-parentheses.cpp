/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> dp(n+1, vector<string>());
        dp[0].push_back("");
        for(int i=1; i<=n; i++) {
            for(int k=0; k<i; k++) {
                for(string s1:dp[k]) {
                    for(string s2:  dp[i-1-k])
                        dp[i].push_back("("+s1+")"+s2);
                }
            }
        }
        return dp[n];
    }
};

