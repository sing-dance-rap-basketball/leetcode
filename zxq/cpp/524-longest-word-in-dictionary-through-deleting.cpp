/*
 * @lc app=leetcode id=524 lang=cpp
 *
 * [524] Longest Word in Dictionary through Deleting
 *
 * https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/description/
 *
 * algorithms
 * Medium (51.03%)
 * Likes:    1411
 * Dislikes: 336
 * Total Accepted:    130.7K
 * Total Submissions: 256.1K
 * Testcase Example:  '"abpcplea"\n["ale","apple","monkey","plea"]'
 *
 * Given a string s and a string array dictionary, return the longest string in
 * the dictionary that can be formed by deleting some of the given string
 * characters. If there is more than one possible result, return the longest
 * word with the smallest lexicographical order. If there is no possible
 * result, return the empty string.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
 * Output: "apple"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "abpcplea", dictionary = ["a","b","c"]
 * Output: "a"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 1000
 * 1 <= dictionary.length <= 1000
 * 1 <= dictionary[i].length <= 1000
 * s and dictionary[i] consist of lowercase English letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // Accepted
    // 31/31 cases passed (83 ms)
    // Your runtime beats 65.44 % of cpp submissions
    // Your memory usage beats 50.04 % of cpp submissions (17.6 MB)
    string findLongestWord(string s, vector<string>& dictionary) {
        string ans("");
        for (string word : dictionary) {
            int i = 0;
            for (int j = 0; i < word.size() && j < s.size(); ++j) {
                if (word[i] == s[j]) {++i;}
            }
            if (i == word.size()) { // `word` can be formed
                if ((word.size() > ans.size()) || 
                (word.size() == ans.size() && word < ans)) {
                    ans = word;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

