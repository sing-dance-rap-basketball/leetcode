/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] ZigZag Conversion
 */
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        string result[numRows];
        string res;
        int pos = 0;
        int flag = 0;
        for(int i=0; i<s.size();) {
            if(!flag){
                result[pos ++ ].push_back(s[i]);
                if(pos == numRows) {
                    flag = 1;
                    pos--;
                }
            } else {
                pos--;
                if(pos == 0) {
                    flag = 0;
                    continue;
                }
                result[pos].push_back(s[i]);
            }
            i++;
        }
        for(auto s:result) {
            res += s;
        }
        return res;
    }
};

