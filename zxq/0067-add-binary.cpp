/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

// @lc code=start

/**
 * Accepted
 *  294/294 cases passed (4 ms)
 *  Your runtime beats 77.7 % of cpp submissions
 *  Your memory usage beats 100 % of cpp submissions (7 MB)
 */
class Solution {
public:
    string addBinary(string a, string b) {
        int len_a = a.size(), len_b = b.size();
        int ia = 1, ib = 1;
        int digit_a, digit_b;
        int carry = 0;
        string ans;
        while (ia <= len_a || ib <= len_b) {
            digit_a = ia <= len_a ? a[len_a - ia++] - '0' : 0;
            digit_b = ib <= len_b ? b[len_b - ib++] - '0' : 0;
            switch(digit_a + digit_b + carry) {
                case 0:
                    ans = "0" + ans;
                    carry = 0;
                    break;
                case 1:
                    ans = "1" + ans;
                    carry = 0;
                    break;
                case 2:
                    ans = "0" + ans;
                    carry = 1;
                    break;
                case 3:
                    ans = "1" + ans;
                    carry = 1;
                    break;
                default:
                    cerr << "Something wrong with the digits." << endl;
                    exit(1);
            }
        }
        
        if (carry == 1) {
            ans = "1" + ans;
        }
        return ans;
    }
};
// @lc code=end

