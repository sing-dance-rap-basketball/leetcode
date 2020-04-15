/*
 * @lc app=leetcode id=537 lang=cpp
 *
 * [537] Complex Number Multiplication
 */

// @lc code=start

/**
 * Accepted
    55/55 cases passed (0 ms)
    Your runtime beats 100 % of cpp submissions
    Your memory usage beats 100 % of cpp submissions (5.9 MB)
 */
class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int re_a, im_a, re_b, im_b;
        stringToComplex(a, re_a, im_a);
        stringToComplex(b, re_b, im_b);

        int re_c = re_a * re_b - im_a * im_b;
        int im_c = re_a * im_b + im_a * re_b;
        return complexToString(re_c, im_c);
    }

    string complexToString(int re, int im) {
        string result = to_string(re);
        result += '+';
        result += to_string(im);
        result += 'i';

        return result;
    }

    void stringToComplex(string z, int& re, int& im) {
        int pos = z.find('+');
        re = stoi(z.substr(0, pos));
        im = stoi(z.substr(pos+1));
    }
};
// @lc code=end

