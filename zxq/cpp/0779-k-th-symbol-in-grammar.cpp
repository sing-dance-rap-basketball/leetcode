/*
 * @lc app=leetcode id=779 lang=cpp
 *
 * [779] K-th Symbol in Grammar
 */

/*
    √ Accepted
    √ 55/55 cases passed (0 ms)
    √ Your runtime beats 100 % of cpp submissions
    √ Your memory usage beats 83.33 % of cpp submissions (8.2 MB)
 */
class Solution {
public:
    int kthGrammar(int N, int K) {
        if (N == 1 && K == 1) {
            return 0;
        }
        if (K <= (1 << N-2)) {
            return kthGrammar(N-1, K);
        }
        else {
            return 1 - kthGrammar(N-1, K - (1 << N-2));
        }
    }
};

