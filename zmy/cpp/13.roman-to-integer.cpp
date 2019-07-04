/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */
// 暴力就完事了
class Solution {
public:
    int romanToInt(string s) {
        int table[256];
        table['M'] = 1000;
        table['D'] = 500;
        table['C'] = 100;
        table['L'] = 50;
        table['X'] = 10;
        table['V'] = 5;
        table['I'] = 1;
        int res = table[s.back()];
        int len = s.size() - 1;
        for(int i = 0; i < len; i++) {
            if(table[s[i]] < table[s[i + 1]]) res -= table[s[i]];
            else res += table[s[i]];
        }
        return res;
    }
};

