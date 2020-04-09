/*
 * @lc app=leetcode id=273 lang=cpp
 *
 * [273] Integer to English Words
 */

// @lc code=start

/**
 * Accepted
    601/601 cases passed (8 ms)
    Your runtime beats 31.14 % of cpp submissions
    Your memory usage beats 100 % of cpp submissions (7.8 MB)
 */
class Solution {
public:
    string numberToWords(int num) {
        if (num < 0) {
            exit(EXIT_FAILURE);
        }
        
        string ans;

        if (num < 1e3) {
            int unit = num;
            ans = threeFigures(unit);
        }
        else if (num < 1e6) {
            int unit = num % 1000;
            int thousand = num / 1000;
            ans = threeFigures(thousand) + " Thousand";
            if (unit != 0) {
                ans.append(" " + threeFigures(unit));
            }
        }
        else if (num < 1e9) {
            int unit = num % 1000;
            int thousand = (num / 1000) % 1000;
            int million = num / 1000000;
            ans = threeFigures(million) + " Million";
            if (thousand != 0) {
                ans.append(" " + threeFigures(thousand)).append(" Thousand");
            }
            if (unit != 0) {
                ans.append(" " + threeFigures(unit));
            }
        }
        else { // 1e9 - INT_MAX
            int unit = num % 1000;
            int thousand = (num / 1000) % 1000;
            int million = (num / 1000000) % 1000;
            int billion = num / 1000000000;
            ans = threeFigures(billion) + " Billion";
            if (million != 0) {
                ans.append(" " + threeFigures(million)).append(" Million");
            }
            if (thousand != 0) {
                ans.append(" " + threeFigures(thousand)).append(" Thousand");
            }
            if (unit != 0) {
                ans.append(" " + threeFigures(unit));
            }
        }

        return ans;
    }

    string threeFigures(int num) {
        if (num < 0 || num >= 1000) {
            exit(EXIT_FAILURE);
        }

        if (num == 0) {
            return "Zero";
        }
        
        string result;
        vector<string> table {"", "One", "Two", "Three", "Four", 
                            "Five", "Six", "Seven", "Eight", "Nine",
                            "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", 
                            "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

        vector<string> tens{"", "Ten", "Twenty", "Thirty", "Forty",
                            "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
       
        if (num > 99) {
            result = table[num / 100];
            result.append(" Hundred ");
            num %= 100;
            if (num == 0) {
                result.pop_back();
            }
        }

        if (num % 10 == 0) {    // 0, 10, 20, ..., 90
            result.append(tens[num/10]);
        }
        else if (num < 20) {    // except for 0 and 10
            result.append(table[num]);
        }
        else {
            result.append(tens[num/10]).append(" " + table[num%10]);
        }

        return result;
    }
};
// @lc code=end

