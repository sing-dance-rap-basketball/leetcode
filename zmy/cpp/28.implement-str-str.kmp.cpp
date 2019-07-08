/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 */
class Solution {
    vector<int> genNext(string needle) {
        int n = needle.size();
        vector<int> next(n, 0);
        for (int i = 1, len = 0; i < n;) {
            if (needle[i] == needle[len]) {
                next[i++] = ++len;
            } else if (len) {
                len = next[len - 1];
            } else {
                next[i++] = 0;
            }
        }
        return next;
    }
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        if (!n) {
            return 0;
        }
        vector<int> next = genNext(needle);
        for (int i = 0, j = 0; i < m;) {
            if (haystack[i] == needle[j]) { 
                i++, j++;
            }
            if (j == n) {
                return i - j;
            }
            if (i < m && haystack[i] != needle[j]) {
                j ? j = next[j - 1] : i++;
            }
        }
        return -1;
    }
};

