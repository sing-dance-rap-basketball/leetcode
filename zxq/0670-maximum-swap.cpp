/*
 * @lc app=leetcode id=670 lang=cpp
 *
 * [670] Maximum Swap
 */

/*
    √ Accepted
    √ 111/111 cases passed (0 ms)
    √ Your runtime beats 100 % of cpp submissions
    √ Your memory usage beats 100 % of cpp submissions (8.1 MB)
 */
class Solution {
public:
    int maximumSwap(int num) {
        vector<int> digits {};
        do {
            digits.push_back(num % 10);
            num /= 10;
        } while (num != 0);

        for (int i = digits.size()-1; i > 0; --i) {
            int max_digit_idx = i;
            for (int j = 0; j < i; ++j) {
                if (digits[j] > digits[max_digit_idx]) {
                    max_digit_idx = j;
                }
            }
            if (max_digit_idx != i) {
                std::swap(digits[i], digits[max_digit_idx]);
                break;
            }
        }

        int res = 0;
        for (int i = digits.size()-1; i > -1; --i) {
            res = res * 10 + digits[i];
        }
        return res;
    }
};

