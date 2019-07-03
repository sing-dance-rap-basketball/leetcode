/**
 * 5. Longest Palindromic Substring
 * Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
 *
 */

 
/*
 * Runtime: 60 ms, faster than 50.23% of C++ online submissions for Longest Palindromic Substring.
 * Memory Usage: 104.1 MB, less than 13.38% of C++ online submissions for Longest Palindromic Substring.
 */
 
class Solution {
public:
    string longestPalindrome(string s) {
        int strLen = s.length();
        
        if(strLen == 1)
            return s;
        
        int maxLen = 0;
        int start = 0, end = 0;
        for (int i = 0; i < strLen; i++) {
            int subLen1 = ScanFromCenter(s, i, i);
            int subLen2 = ScanFromCenter(s, i, i + 1);
            int len = max(subLen1, subLen2);

            if (maxLen < len){
                maxLen = len;
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }  
        return s.substr(start,maxLen);
    }
    
    int ScanFromCenter(string s, int left, int right)
    {
        int strLen = s.length();
        while (left >= 0 && right < strLen && s[left] == s[right]) {
            --left;
            ++right;
        }
        return right - left + 1 - 2;
    }
};