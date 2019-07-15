/**
 * 38. Count and Say
 * The count-and-say sequence is the sequence of integers with the first five terms as following:
 *  1.     1
 *  2.     11
 *  3.     21
 *  4.     1211
 *  5.     111221
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence.
 * Note: Each term of the sequence of integers will be represented as a string.
 */

/**
 * Runtime: 8 ms, faster than 30.23% of C++ online submissions for Count and Say.
 * Memory Usage: 59.8 MB, less than 5.07% of C++ online submissions for Count and Say.
 */

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) 
            return "1";
        else {
            string tmp = countAndSay(n-1);
            return countStr(tmp);
        }
        return "";
    }
    
    string countStr(string s) {
        int length = s.length();
        string ret = "";
        int count = 1;
        for (int i = 0; i < length - 1; ++i) {
            if(s[i] == s[i+1])
                ++count;
            else {
                ret = ret + to_string(count) + s[i];
                count = 1;
            }
        }
        ret = ret + to_string(count) + s[length-1];
        return ret;
    }
};
