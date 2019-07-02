/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_map<char, int> mmap;
        int start = 0;
        int longest = 0;
        for (int i=0; i<s.length(); i++){
            if(mmap.find(s[i])!=mmap.end() && mmap[s[i]] >= start) {
                start = mmap[s[i]] + 1; 
            }
            if(i-start +1 > longest) {
                longest = i - start +1;
            }
            mmap[s[i]] = i;
        }
        return longest;
    }
};

