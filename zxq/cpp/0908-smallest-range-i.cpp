/*
 * @lc app=leetcode id=908 lang=cpp
 *
 * [908] Smallest Range I
 */

/*
  √ 68/68 cases passed (20 ms)
  √ Your runtime beats 88.81 % of cpp submissions
  √ Your memory usage beats 51.91 % of cpp submissions (9.7 MB)
  √ 68/68 cases passed (20 ms)
  √ Your runtime beats 88.81 % of cpp submissions
  √ Your memory usage beats 22.58 % of cpp submissions (9.8 MB)
*/
class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        if (A.size() <= 1) { return 0; }
        int minA = A[0];
        int maxA = A[0];
        for (int i = 1; i < A.size(); ++i) {
            if (A[i] < minA) {
                minA = A[i];
            }
            else if (A[i] > maxA) {
                maxA = A[i];
            }
        }
        return (maxA - minA > K * 2) ? maxA - minA - K * 2 : 0;
    }
};

