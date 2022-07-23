/*
 * @lc app=leetcode id=748 lang=cpp
 *
 * [748] Shortest Completing Word
 */

/*
    √ Accepted
    √ 102/102 cases passed (20 ms)
    √ Your runtime beats 70.47 % of cpp submissions
    √ Your memory usage beats 40 % of cpp submissions (14.7 MB)
 */
class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> plate(26, 0);
        for (char c : licensePlate) {
            if (c >= 'a' && c <= 'z') {
                ++plate[c-'a'];
            }
            else if (c >= 'A' && c <= 'Z') {
                ++plate[c-'A'];
            }
        }
        int shortest_len = 16;
        string shortest_word;
        for (string& word : words) {
            if (check(plate, word)) {
                if (word.size() < shortest_len) {
                    shortest_len = word.size();
                    shortest_word = word;
                }
            }
        }
        return shortest_word;
    }
private:
    bool check(const vector<int>& plate, const string& word)
    {
        vector<int> temp(plate);
        for (int i = 0; i < word.size(); ++i) {
            if (temp[word[i]-'a'] > 0) {
                --temp[word[i]-'a'];
            }
        }
        for (int n : temp) {
            if (n > 0) {
                return false;
            }
        }
        return true;
    }
};

