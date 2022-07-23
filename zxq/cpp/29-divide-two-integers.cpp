/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */

// @lc code=start

/*
 * Accepted
 *  989/989 cases passed (0 ms)
 *  Your runtime beats 100 % of cpp submissions
 *  Your memory usage beats 100 % of cpp submissions (6.2 MB) 
 */
class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign = 1;
        if (dividend < 0) {
            sign = -sign;
        }
        if (divisor < 0) {
            sign = -sign;
        }

        // 考虑到 long 可能和 int 一样长，这里选择了 long long
        // 这里用 abs 有点偷懒，当然不用 abs 用三元运算符也可以
        long long dividend_abs = abs((long long)dividend);
        long long divisor_abs = abs((long long)divisor);
        if (dividend_abs < divisor_abs) {
            return 0;
        }

        // 创建 divisor 乘 2 的幂的 vector
        vector<long long> list {divisor_abs};
        vector<long long> pow2 {1LL};
        while (list.back() < dividend_abs) {
            list.push_back(list.back() + list.back());
            pow2.push_back(pow2.back() + pow2.back());
        }

        long long ans = 0;
        for (int i = list.size() - 1; i >= 0; --i) {
            if (list[i] < dividend_abs) {
                dividend_abs -= list[i];
                ans += pow2[i];
            }
            else if (list[i] > dividend_abs) {
                continue;
            }
            else {
                ans += pow2[i];
                break;
            }
        }

        ans = sign > 0 ? ans : -ans;

        if (ans > INT_MAX) { 
            return INT_MAX;
        }
        return (int)ans;
    }
};
// @lc code=end

