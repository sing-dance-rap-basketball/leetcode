/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 */

// 有个玄学的bug
class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        while(--n) {
            int cnt = result.size();
            string temp = "";
            for(int i=0; i<cnt;) {
                int count = 1;
                for(int j=1; i+j<cnt && result[i+j] == result[i]; j++, count++);
                temp += std::to_string(count);
                temp += result[i];
                i+=count;
            }
            result = temp;
        }
        return result;
    }
};
