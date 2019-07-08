/**
 * 14. Longest Common Prefix
 * Write a function to find the longest common prefix string amongst an array of strings.
 * If there is no common prefix, return an empty string "".
 */
 
/**
 * Runtime: 4 ms, faster than 96.89% of C++ online submissions for Longest Common Prefix.
 * Memory Usage: 9 MB, less than 26.24% of C++ online submissions for Longest Common Prefix.
 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int num = strs.size();
        if (num == 0)
            return "";
        int length = strs[0].length();
        string ret = "";
        for (int i = 0; i < length; ++i) {
            char tar = strs[0][i];
            char flag = 1;
            if (tar == '\0')
                break;
            for (int j =1; j < num; ++j){
                if( i + 1 > strs[j].length()) {
                    return ret;
                }
                if (tar != strs[j][i]) {
                    return ret;
                }
            }
            if (flag)
                ret += tar;
        }
        return ret;
    }
};
