/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */

// @lc code=start
class Solution {
public:
    string intToRoman(int num) {
        int units, tens, hundreds, thousands;
        string ans;

        thousands = num / 1000;
        num %= 1000;
        ans.append(thousands, 'M');

        hundreds = num / 100;
        num %= 100;
        if (hundreds == 4) {
            ans += "CD";
        }
        else if (hundreds == 9) {
            ans += "CM";
        }
        else {
            if (hundreds >= 5) {
                ans += "D";
            }
            hundreds %= 5;
            ans.append(hundreds, 'C');
        }

        tens = num / 10;
        num %= 10;
        if (tens == 4) {
            ans += "XL";
        }
        else if (tens == 9) {
            ans += "XC";
        }
        else {
            if (tens >= 5) {
                ans += "L";
            }
            tens %= 5;
            ans.append(tens, 'X');
        }

        units = num;
        if (units == 4) {
            ans += "IV";
        }
        else if (units == 9) {
            ans += "IX";
        }
        else {
            if (units >= 5) {
                ans += "V";
            }
            units %= 5;
            ans.append(units, 'I');
        }

        return ans;
    }
};
// @lc code=end

