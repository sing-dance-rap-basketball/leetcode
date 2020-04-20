/*
 * @lc app=leetcode id=830 lang=cpp
 *
 * [830] Positions of Large Groups
 * 
 * In a string S of lowercase letters, these letters form consecutive groups of the same character.
 * For example, a string like S = "abbxxxxzyy" has the groups "a", "bb", "xxxx", "z" and "yy".
 * Call a group large if it has 3 or more characters.  We would like the starting and ending positions of every large group.
 * The final answer should be in lexicographic order.
 */

// @lc code=start

/**
 * Accepted
    202/202 cases passed (8 ms)
    Your runtime beats 78.85 % of cpp submissions
    Your memory usage beats 100 % of cpp submissions (6.8 MB)
 */
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> ans;
        for (int i = 0; i < S.size();) {
            int j = i + 1;
            for (; j < S.size(); ++j) {
                if (S[j] != S[i]) break;
            }
            if (j - i >= 3) {
                ans.push_back({i, j-1});
            }
            i = j;
        }
        return ans;
    }
};
// @lc code=end

