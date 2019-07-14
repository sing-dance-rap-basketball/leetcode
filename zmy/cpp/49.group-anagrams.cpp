/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> results;
        unordered_map<string , vector<string>> mmap;
        for(auto s: strs) {
            string t = s;
            sort(t.begin(), t.end());
            mmap[t].push_back(s);
        }
        for(auto p: mmap) {
            results.push_back(p.second);
        }
        return results;
    }
};

