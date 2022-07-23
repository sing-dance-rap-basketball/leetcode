/*
 * @lc app=leetcode id=680 lang=cpp
 *
 * [680] Valid Palindrome II
 *
 * https://leetcode.com/problems/valid-palindrome-ii/description/
 *
 * algorithms
 * Easy (39.42%)
 * Likes:    6003
 * Dislikes: 317
 * Total Accepted:    522.2K
 * Total Submissions: 1.3M
 * Testcase Example:  '"aba"'
 *
 * Given a string s, return true if the s can be palindrome after deleting at
 * most one character from it.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "aba"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "abca"
 * Output: true
 * Explanation: You could delete the character 'c'.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "abc"
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^5
 * s consists of lowercase English letters.
 * 
 * 
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Accepted
    // 469/469 cases passed (75 ms)
    // Your runtime beats 56.26 % of cpp submissions
    // Your memory usage beats 75.84 % of cpp submissions (19.7 MB)
    bool validPalindrome(string s) {
        if (s.size() <= 2) {return true;}
        bool deleted = false;
        for (int l = 0, r = s.size()-1; l < r; ++l, --r) {
            if (s[l] != s[r]) {
                if (deleted) {
                    return false;
                } else {    // cnt == 0
                    if (s[l+1] == s[r] && s[l] != s[r-1]) {
                        ++l; 
                    } else if (s[l+1] != s[r] && s[l] == s[r-1]) {
                        --r; 
                    } else if (s[l+1] == s[r] && s[l] == s[r-1]) {
                        return isPalindrome(s.substr(l, r-l)) 
                                || isPalindrome(s.substr(l+1, r-l));
                    } else {
                        return false;
                    }
                    deleted = true;
                }
            }
        }
        return true;
    }
    bool isPalindrome(string s) {
        if (s.size() <= 1) {return true;}
        for (int l = 0, r = s.size()-1; l < r; ++l, --r) {
            if (s[l] != s[r]) return false;
        }
        return true;
    }
};

// class Solution {
// public:
//     // Accepted
//     // 469/469 cases passed (55 ms)
//     // Your runtime beats 89.24 % of cpp submissions
//     // Your memory usage beats 75.84 % of cpp submissions (19.7 MB)
//     bool validPalindrome(string s) {
//         int l = 0, r = s.size() - 1;
//         return validPalindrome(s, l, r, 1);
//     }
    
//     bool validPalindrome(string& s, int l, int r, int count) {
//         // 至多删去count个字母
//         if (count < 0) return false;
//         while (l < r) {
//             if (s[l] == s[r]) {
//                 l++; r--;
//             } else {
//                 return validPalindrome(s, l + 1, r, count - 1) || 
//                         validPalindrome(s, l, r - 1, count - 1);
//             }
//         }
//         return true;
//     }
// };
// @lc code=end