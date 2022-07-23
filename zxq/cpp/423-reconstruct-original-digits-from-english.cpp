/*
 * @lc app=leetcode id=423 lang=cpp
 *
 * [423] Reconstruct Original Digits from English
 */

// @lc code=start

/**
 * Accepted
    24/24 cases passed (20 ms)
    Your runtime beats 88.83 % of cpp submissions
    Your memory usage beats 100 % of cpp submissions (9.7 MB)
 */
class Solution {
public:
    string originalDigits(string s) {
        vector<int> dc(10);     // digit count
        vector<int> lc(26);    // letter count
        
        for (char c : s) {
            ++lc[c - 'a'];
        }

        CountDigit(dc, lc, 0, 'z');
        CountDigit(dc, lc, 2, 'w');
        CountDigit(dc, lc, 4, 'u');
        CountDigit(dc, lc, 6, 'x');
        CountDigit(dc, lc, 8, 'g');
        CountDigit(dc, lc, 1, 'o');
        CountDigit(dc, lc, 3, 'h');
        CountDigit(dc, lc, 5, 'f');
        CountDigit(dc, lc, 7, 's');
        CountDigit(dc, lc, 9, 'i');
        
        string ans;
        for (int i = 0; i < 10; ++i) {
            ans.append(string(dc[i], '0'+i));
        }

        return ans;
    }

    void CountDigit(vector<int>& dc, vector<int>& lc, int d, char c) {
        vector<string> strs {"zero", "one", "two", "three", "four", 
                            "five", "six", "seven", "eight", "nine"};
        
        dc[d] = lc[c - 'a'];

        int temp = lc[c - 'a'];
        for (char letter : strs[d]) {
            lc[letter - 'a'] -= temp;
        }
    }
};
// @lc code=end

