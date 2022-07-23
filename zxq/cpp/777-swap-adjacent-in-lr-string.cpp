/*
 * @lc app=leetcode id=777 lang=cpp
 *
 * [777] Swap Adjacent in LR String
 */

/*
    √ Accepted
    √ 78/78 cases passed (12 ms)
    √ Your runtime beats 61.46 % of cpp submissions
    √ Your memory usage beats 100 % of cpp submissions (9.4 MB)
*/
class Solution {
public:
    bool canTransform(string start, string end) {
        if (start.size() != end.size()) {
            return false;
        }
        int i = -1, j = -1;
        int len = start.size();
        int s_leftX_count = 0, e_leftX_count = 0;
        while (true) {
            for (i += 1; i < len; ++i) {
                if (start[i] == 'X') {
                    ++s_leftX_count;
                }
                else {
                    break;
                }
            }
            for (j += 1; j < len; ++j) {
                if (end[j] == 'X') {
                    ++e_leftX_count;
                }
                else {
                    break;
                }
            }

            if (i == len && j == len) {
                break;
            }
            if (i == len || j == len) {
                return false;
            }

            if (start[i] != end[j]) {
                return false;
            }
            else if (start[i] == end[j] && start[i] == 'R') {
                if (s_leftX_count > e_leftX_count) {
                    return false;
                }
            }
            else if (start[i] == end[j] && start[i] == 'L') {
                if (s_leftX_count < e_leftX_count) {
                    return false;
                }
            }
        }
        return true;
    }
};

