/**
 * 30. Substring with Concatenation of All Words
 * You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.
 * Input:
 *     s = "barfoothefoobarman",
 *     words = ["foo","bar"]
 * Output: [0,9]
 * Explanation: Substrings starting at index 0 and 9 are "barfoor" and "foobar" respectively.
 * The output order does not matter, returning [9,0] is fine too.
 *
 * 这题看了几遍才明白什么意思
 * 给了一个字符串和一个单词vector 找到刚好包含vector中所有单词(无顺序要求)的子串 并给出起始下标位置
 */

/**
 * Runtime: 632 ms, faster than 16.79% of C++ online submissions for Substring with Concatenation of All Words.
 * Memory Usage: 286.4 MB, less than 15.94% of C++ online submissions for Substring with Concatenation of All Words.
 * 内存上应该有优化空间  时间上没啥思路
 */

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int> StrMap;
        vector<int> ret;
        
        if(s.length() == 0)
            return ret;
        if(words.size() == 0)
            return ret;
        
        for (int i = 0; i < words.size(); ++i) {
            if (StrMap.find(words[i]) == StrMap.end())
                StrMap.insert({words[i],1});
            else
                ++StrMap[words[i]];
        }
        
        int begin = 0;
        int inc = words[0].length();
        while (begin + words.size() * inc <= s.length()) {
            int wordsNum = words.size();
            unordered_map<string,int> TmpMap = StrMap;
            
            //cout << begin << " " << s.length() << endl;
            int substart = begin;
            while (wordsNum) {
                string word = s.substr(substart,inc);
                substart += inc;
                //cout << word << endl;
                if (TmpMap.find(word) != TmpMap.end() && TmpMap[word] != 0) {
                    --wordsNum;
                    TmpMap[word]--;
                }
                else
                    break;
            }
            if (wordsNum == 0) {
                ret.push_back(begin);
            }
            begin = begin + 1;
        }
        
        return ret;
    }
};