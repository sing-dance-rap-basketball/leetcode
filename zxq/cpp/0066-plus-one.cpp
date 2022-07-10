/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

/*
√ Accepted
  √ 109/109 cases passed (4 ms)
  √ Your runtime beats 74.88 % of cpp submissions
  √ Your memory usage beats 9.45 % of cpp submissions (8.7 MB)
√ Accepted
  √ 109/109 cases passed (0 ms)
  √ Your runtime beats 100 % of cpp submissions
  √ Your memory usage beats 46.92 % of cpp submissions (8.6 MB)
*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res(digits);
        res.insert(res.begin(), 0);
        for (int i = res.size()-1; i >= 0; --i) {
            if (res[i] < 9) {
                res[i] += 1;
                break;
            }
            else {
                res[i] = 0;
            }
        }
        if (res[0] == 0) {
            res.erase(res.begin());
        }
        return res;
    }
};

