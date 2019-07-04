/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */

// 差点写了个一沓子规则的自动机emmmm
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(); int n = p.size();
        bool dp[m+2][n+2];
        memset(dp, 0, sizeof(dp));
        dp [0][0] = true;

        for(int i=1; i<=m; i++) 
            dp[i][0] = false;
        
        // ?*?*?*
        for (int j=2; j<=n; j++) 
            dp[0][j] = p[j - 1] == '*' && dp[0][j-2];

        for (int i=1; i<=m; i++) {
            // forward *
            for(int j=1; j<=n; j++) {
                if(p[j-1] == '*') {
                    dp[i][j] = dp[i][j - 2] || (dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
                } else {
                    dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
                // cout << i << "\t" << j << "\t" << dp[i][j] << endl;
            }
        }
        return dp[m][n];
    }
};

