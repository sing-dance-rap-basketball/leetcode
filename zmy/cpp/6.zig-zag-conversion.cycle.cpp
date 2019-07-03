/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] ZigZag Conversion
 */
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) {return s;}
        // 012321 012321 0
        int len = s.size();
        int cycle = (numRows-1) << 1;
        string result;
        for (int i=0; i<numRows; i++) {
            for (int j=i; j<len; j += cycle) {
                result+=s[j];
                int second = j + cycle - i - i;
                if(i!=0 && i!=numRows-1 && second < len )
                    result+=s[second];
            }
        }
        return result;
    }
};

