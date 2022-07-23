/*
 * @lc app=leetcode id=763 lang=cpp
 *
 * [763] Partition Labels
 */

// @lc code=start
class Solution {
public:
    // Accepted
    // 118/118 cases passed (4 ms)
    // Your runtime beats 74.81 % of cpp submissions
    // Your memory usage beats 88.94 % of cpp submissions (6.5 MB)
    vector<int> partitionLabels(string s) {
        vector<int> ends(26, -1);
        for (int i = 0; i < s.size(); ++i) {
            ends[s[i] - 'a'] = i;
        }

        vector<int> ans;
        int l = 0, r = 0;
        for (int i = 0; i < s.size(); ++i) {
            r = max(ends[s[i] - 'a'], r);
            if (i == r) {
                ans.push_back(r - l + 1);
                l = r + 1;
                r = l;
            }
        }
        return ans;
    }
};
// @lc code=end

