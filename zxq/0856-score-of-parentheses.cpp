/*
 * @lc app=leetcode id=856 lang=cpp
 *
 * [856] Score of Parentheses
 * 
 * Given a balanced parentheses string S, compute the score of the string based on the following rule:
    () has score 1
    AB has score A + B, where A and B are balanced parentheses strings.
    (A) has score 2 * A, where A is a balanced parentheses string.
 */

// @lc code=start

/**
 * Accepted
    85/85 cases passed (0 ms)
    Your runtime beats 100 % of cpp submissions
    Your memory usage beats 12.5 % of cpp submissions (10.5 MB)
 */
class Solution {
public:
    int scoreOfParentheses(string S) {
        if (S == "()") return 1;

        stack<char> mystack;
        int i = 0;
        while (i < S.size()) {
            if (mystack.empty() || mystack.top() == S[i])
                mystack.push(S[i]);
            else 
                mystack.pop();

            ++i;
            if (mystack.empty()) {
                break;
            }
        }

        if (i < S.size()) {
            return scoreOfParentheses(S.substr(0, i))
                    + scoreOfParentheses(S.substr(i)); 
        }
        // i == S.size()
        return 2 * scoreOfParentheses(S.substr(1, S.size()-2));
    }
};
// @lc code=end

