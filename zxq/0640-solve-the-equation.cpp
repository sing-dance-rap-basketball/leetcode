/*
 * @lc app=leetcode id=640 lang=cpp
 *
 * [640] Solve the Equation
 */

// @lc code=start

/**
 * Accepted
    52/52 cases passed (0 ms)
    Your runtime beats 100 % of cpp submissions
    Your memory usage beats 100 % of cpp submissions (6.3 MB)
 */
class Solution {
public:
    string solveEquation(string equation) {
        int pos = equation.find('=');
        string lhs = equation.substr(0, pos);
        string rhs = equation.substr(pos+1);
        int w1 = 0, b1 = 0;
        int w2 = 0, b2 = 0;

        reduce(lhs, w1, b1);
        reduce(rhs, w2, b2);

        if (w1 == w2) {
            if (b1 == b2) {
                return string {"Infinite solutions"};
            }
            return string {"No solution"};
        }
        return string {"x="} + to_string((b2 - b1) / (w1 - w2));
    }

    void reduce(string expr, int& w, int& b) {
        int coe = 0;    // coefficient
        int sign = 1;
        for (int i = 0; i < expr.size(); ++i) {
            char c = expr[i];
            if (c == '-') {
                sign = -1;
                coe = 0;
            }
            else if (c == '+') {
                sign = 1;
                coe = 0;
            }
            else if (c == 'x') {
                if (i == 0
                    || expr[i-1] == '+'
                    || expr[i-1] == '-') { 
                    coe = 1; 
                }
                w += coe * sign;
            }
            else {  // '0' -> '9'
                int digit = c - '0';
                coe = coe * 10 + digit;
                if (i+1 == expr.size()
                    || expr[i+1] == '+'
                    || expr[i+1] == '-') {
                    b += coe * sign;
                }
            }
        }
    }
};
// @lc code=end

