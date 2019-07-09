/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */
// 这里是玄学...
#define MAX(m, n) ((m)>(n))?(m):(n)
class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0;
        int right = 0;
        int maxlength = 0;
        int n = s.size();
        for(int i=0; i<n; i++){
            if(s[i] == '(') {
                left ++;
            } else {
                right ++;
            }

            if(left == right) {
                maxlength = MAX(maxlength, left *2);
            } else if(right > left) {
                left = right = 0;
            }
        }
        left = right = 0;
        for(int i=n-1; i>=0; i--) {
            if(s[i] == '(')
                left ++;
            else 
                right ++;
            if(left == right) {
                maxlength = MAX(maxlength, left *2);
            } else if(left > right) {
                left = right = 0;
            }
        }
        return maxlength;
    }
};

