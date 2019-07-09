/**
 * 20. Valid Parentheses
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 * An input string is valid if:
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * Note that an empty string is also considered valid.
 */
 
/**
 * Runtime: 4 ms, faster than 74.58% of C++ online submissions for Valid Parentheses.
 * Memory Usage: 8.5 MB, less than 45.40% of C++ online submissions for Valid Parentheses.
 * 知道要用栈 就是写的很难看……
 */
class Solution {
public:
    bool isValid(string s) {
        stack<char> parent;
        for (int i = 0; i < s.size(); ++i) {
            if (!parent.empty()) {
                switch (s[i]) {
                    case ')':
                        if(parent.top() == '(')
                            parent.pop();
                        else
                            parent.push(s[i]);
                        break;
                    case '}':
                        if(parent.top() == '{')
                            parent.pop();
                        else
                            parent.push(s[i]);
                        break;
                    case ']':
                        if(parent.top() == '[')
                            parent.pop();
                        else
                            parent.push(s[i]);
                        break;
                    default:
                        parent.push(s[i]);
                        break;
                } 
            }
            else
                parent.push(s[i]);
        }
        if (parent.empty())
            return true;
        else
            return false;
    }
};