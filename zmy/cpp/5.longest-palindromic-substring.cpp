/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */
class Solution {
public:
    string longestPalindrome(string s) {
        int length = s.size();
        if( length < 2 ) return s;
        int max_l = 0;
        int max_s = 0;

        for (int i=0; i < length;) {
            int start = i, end = i;
            while( end + 1 < length && s[end] == s[end+1]) end ++;
            i = end + 1;
            while (start - 1 >= 0 && end +1 < length && s[start - 1] == s[end + 1]) {
                start --;
                end ++;
            }
            if(end - start + 1 > max_l) {
                max_l = end - start + 1;
                max_s = start;
            }
        }
        return s.substr(max_s, max_l);
    }
};

