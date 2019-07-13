/*
 * @lc app=leetcode id=44 lang=cpp
 *
 * [44] Wildcard Matching
 */
class Solution {
public:
    bool isMatch(string s, string p) {
        int l1 = s.size(); int l2 = p.size();
        int i = 0; int j=0; int asterisk = -1; int match;
        while(i<l1) {
            if(j<l2 && p[j] == '*') {
                match = i;
                asterisk = j++;
            } else if (j<l2 && (s[i]==p[j] ||p[j]=='?')) {
                i++;
                j++;
            } else if (asterisk >= 0) {
                i = ++match;
                j = asterisk + 1;
            } else 
                return false;
        }
        while(j<l2 && p[j] == '*') j++;
        return j == l2;
    }
};
