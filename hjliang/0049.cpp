/**
 * 49. Group Anagrams
 * Given an array of strings, group anagrams together.
 */

/**
 * Runtime: 48 ms, faster than 49.59% of C++ online submissions for Group Anagrams.
 * Memory Usage: 17.6 MB, less than 90.23% of C++ online submissions for Group Anagrams.
 */

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int size = strs.size();
        vector<vector<string>> ret;
        unordered_map<string,int> anagram;
        int index = 0;
        for (int i = 0; i < size; ++i) {
            string tmp = strs[i];
            sort(tmp.begin(),tmp.end());
            if (anagram.find(tmp) != anagram.end()) {
                int pos = anagram[tmp];
                ret[pos].push_back(strs[i]);
            }
            else {
                anagram.insert({tmp,index});
                ret.push_back({strs[i]});
                ++index;
            }
        }
        return ret;
    }
};