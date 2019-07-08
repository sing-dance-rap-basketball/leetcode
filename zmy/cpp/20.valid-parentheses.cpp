/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */
class Solution {
public:
    bool isValid(string s) {
        std::stack<char> st;
        for(auto & ch : s) {
            switch (ch) {
            case '(': 
            case '[': 
            case '{': 
                st.push(ch); 
                break;
            case ')':
                if(!st.empty() && st.top() == '(') st.pop();
                else return false;
                break;
            case ']':
                if(!st.empty() && st.top() == '[') st.pop();
                else return false;
                break;
            case '}':
                if(!st.empty() && st.top() == '{') st.pop();
                else return false;
                break;
            default:
                break;
            }
        }
        return st.empty();
    }
};

