/* 
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        std::string dict[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        std::queue<string> q;
        std::vector<string> result;
        if(digits.size()==0) return result;
        q.push("");
        while(!q.empty()) {
            std::string curr = q.front();
            q.pop();
            std::cout << curr << std::endl;
            if(curr.size() == digits.size() - 1){
                for(auto &ch:dict[digits[curr.size()] - '2']) {
                    result.push_back(curr + ch);
                }
            } else {
                for(auto &ch:dict[digits[curr.size()] - '2']) {
                    q.push(curr + ch);
                }
            }
        }
        return result;
    }
};

