/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 *
 * https://leetcode.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (42.57%)
 * Likes:    4248
 * Dislikes: 5613
 * Total Accepted:    1.4M
 * Total Submissions: 3.3M
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * A phrase is a palindrome if, after converting all uppercase letters into
 * lowercase letters and removing all non-alphanumeric characters, it reads the
 * same forward and backward. Alphanumeric characters include letters and
 * numbers.
 * 
 * Given a string s, return true if it is a palindrome, or false otherwise.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "A man, a plan, a canal: Panama"
 * Output: true
 * Explanation: "amanaplanacanalpanama" is a palindrome.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "race a car"
 * Output: false
 * Explanation: "raceacar" is not a palindrome.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = " "
 * Output: true
 * Explanation: s is an empty string "" after removing non-alphanumeric
 * characters.
 * Since an empty string reads the same forward and backward, it is a
 * palindrome.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 2 * 10^5
 * s consists only of printable ASCII characters.
 * 
 * 
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAlnum(char c) {
        return (c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
    }
    char lower(char c) {
        return (c >= 'A' && c <= 'Z') ? (c - 'A' + 'a') : c;
    }
    // Accepted
    // 480/480 cases passed (7 ms)
    // Your runtime beats 69.18 % of cpp submissions
    // Your memory usage beats 76.48 % of cpp submissions (7.3 MB)
    // bool isPalindrome(string s) {
    //     int l = 0, r = s.size() - 1;
    //     while (l < r) {
    //         if (!isAlnum(s[l])) {
    //             ++l;
    //             continue;
    //         }
    //         if (!isAlnum(s[r])) {
    //             --r;
    //             continue;
    //         }
    //         if (lower(s[l++]) != lower(s[r--])) {
    //             return false;
    //         }
    //     }
    //     return true;
    // }

    // Accepted
    // 480/480 cases passed (4 ms)
    // Your runtime beats 86.46 % of cpp submissions
    // Your memory usage beats 90.39 % of cpp submissions (7.3 MB)
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            while (l < r && !isAlnum(s[l])) {++l;}
            while (l < r && !isAlnum(s[r])) {--r;}
            if (lower(s[l++]) != lower(s[r--])) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

