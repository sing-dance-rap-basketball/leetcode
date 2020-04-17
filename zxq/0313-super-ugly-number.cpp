/*
 * @lc app=leetcode id=313 lang=cpp
 *
 * [313] Super Ugly Number
 */

// @lc code=start

/**
 * Accepted
    83/83 cases passed (224 ms)
    Your runtime beats 32.57 % of cpp submissions
    Your memory usage beats 33.33 % of cpp submissions (23.2 MB)
 */
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> pos(primes.size());
        vector<int> result(n, __INT_MAX__);
        result[0] = 1;
        for (int i = 1; i < n; ++i) {
            vector<int> indices;
            for (int j = 0; j < primes.size(); ++j) {
                int temp = result[pos[j]] * primes[j];
                if (temp < result[i]) {
                    result[i] = temp;
                    indices.clear();
                    indices.push_back(j);
                }
                else if (temp == result[i]) {
                    indices.push_back(j);
                }
            }
            for (int j : indices) {
                if (result[pos[j]] * primes[j] == result[i]) {
                    ++pos[j];
                }
            }
        }
        return result.back();
    }
};
// @lc code=end

