/**
 * 17. Letter Combinations of a Phone Number
 * Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
 * A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
 */

/**
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions for Letter Combinations of a Phone Number.
 * Memory Usage: 8.8 MB, less than 25.58% of C++ online submissions for Letter Combinations of a Phone Number.
 */

/**
 * 递归方法 返回的vector位置放的不好……
 */
class Solution {
public:
    string KeyBoard[8] = {       "abc", "def",
                          "ghi", "jkl", "mno",
                          "pqrs","tuv", "wxyz"};
    
    vector<string> ret;
    
    vector<string> letterCombinations(string digits) {
        
        combNum(digits,string(""));
        return ret;
    }
    
    void combNum(string digits, string res)
    {
        int length = digits.length(); 
        if (length == 0)
            return;
        if (length == 1) {
            int num = digits[0] - '0' - 2;
            for (int i = 0; i < KeyBoard[num].length(); ++i) {
                string tmp = res + KeyBoard[num][i];
                ret.push_back(tmp);
            }
        }
        else {
            int num = digits[0] - '0' - 2;
            for (int i = 0; i < KeyBoard[num].length(); ++i) {
                string tmp = res + KeyBoard[num][i];
                combNum(digits.substr(1), tmp);
            }
        }
    }
};