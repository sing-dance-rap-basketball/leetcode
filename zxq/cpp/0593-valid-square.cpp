/*
 * @lc app=leetcode id=593 lang=cpp
 *
 * [593] Valid Square
 */

// @lc code=start

/**
 * Accepted
    244/244 cases passed (0 ms)
    Your runtime beats 100 % of cpp submissions
    Your memory usage beats 100 % of cpp submissions (6.3 MB)
 */
class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<int> es {};  //edge square
        es.push_back(getEdgeSquare(p1, p2));
        es.push_back(getEdgeSquare(p1, p3));
        es.push_back(getEdgeSquare(p1, p4));
        es.push_back(getEdgeSquare(p2, p3));
        es.push_back(getEdgeSquare(p2, p4));
        es.push_back(getEdgeSquare(p3, p4));

        sort(es.begin(), es.end());
        return es[0] != 0 
                && es[0] == es[1] && es[1] == es[2] && es[2] == es[3]
                && 2 * es[3] == es[4] 
                && es[4] == es[5];
    }

    int getEdgeSquare(vector<int>& a, vector<int>& b) {
        return (a[0] - b[0]) * (a[0] - b[0])
                 + (a[1] - b[1]) * (a[1] - b[1]);
    }
};
// @lc code=end

