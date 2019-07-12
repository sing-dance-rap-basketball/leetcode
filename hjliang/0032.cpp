/**
 * 32. Longest Valid Parentheses
 * Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
 */

/**
 * Runtime: 8 ms, faster than 71.92% of C++ online submissions for Longest Valid Parentheses.
 * Memory Usage: 9.6 MB, less than 27.53% of C++ online submissions for Longest Valid Parentheses.
 * 虽然solution里有暴力方法 但是暴力的总是超时  可能是因为C++要求高……
 * 解法较多 可以学习下  尤其是DP
 */

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> parenthes;
        int max = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(')
                parenthes.push(i);
            else {
                if(!parenthes.empty() && s[parenthes.top()] == '(')
                    parenthes.pop();
                else
                    parenthes.push(i);
                
                int tmp = parenthes.empty()?-1:parenthes.top();
                if (max < i - tmp)
                    max = i - tmp;
            }
        }
        return max;
    }
};