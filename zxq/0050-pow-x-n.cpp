/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start

/**
 * Accepted
 *  304/304 cases passed (0 ms)
 *  Your runtime beats 100 % of cpp submissions
 *  Your memory usage beats 100 % of cpp submissions (6.4 MB)
 */
class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0.) {
            return 0.;  // 0^-1 题目没有具体要求
        }

        double ans = 1.;
        if (n == 0) {
            return 1.;
        }
        else if (n > 0) {
            vector<int> order {1};
            vector<double> xPow {x};
            
            while (order.back() < n && order.back() <= n / 2) { // 第二个条件用除法防止溢出
                order.push_back(order.back() * 2);
                xPow.push_back(xPow.back() * xPow.back());
            }
            
            for (int i = order.size() - 1; i >= 0; --i) {
                if (order[i] <= n) {
                    ans *= xPow[i];
                    n -= order[i];
                    if (n == 0) {
                        break;
                    }
                }
            }
        }
        else {  // n < 0
            vector<int> order {-1};
            vector<double> xPow {1./x};

            while (order.back() > n && order.back() >= n / 2) {
                order.push_back(order.back() * 2);
                xPow.push_back(xPow.back() * xPow.back());
            }

            for (int i = order.size() - 1; i >= 0; --i) {
                if (order[i] >= n) {
                    ans *= xPow[i];
                    n -= order[i];
                    if (n == 0) {
                        break;
                    }
                }
            }
        }

        return ans;
    }
};
// @lc code=end

