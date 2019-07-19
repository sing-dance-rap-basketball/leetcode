/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */
class Solution {
public:
    int lengthOfLastWord(string s) {
        int result = 0;
        for(auto i = std::rbegin(s); i!= std::rend(s); i++) {
            if(*i == ' ' && result == 0) continue;
            if( *i == ' ' && result) break;
            result ++;
        }
        return result;
    }
};

