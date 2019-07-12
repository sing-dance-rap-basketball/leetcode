/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 */
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2 == "0") return "0";
        int l1 = num1.size();
        int l2 = num2.size();
        int c = 0;
        string result;
        vector<int> cnt(l1+l2-1, 0);
        for(int i=0; i<l1; i++)
            for(int j=0; j<l2; j++)
                cnt[i+j]+=(num1[i] - '0')*(num2[j]-'0');
        for(auto i = cnt.rbegin(); i!=cnt.rend(); i++) {
            int tmp = *i + c;
            result.insert(result.begin(), tmp % 10 + '0');
            c = tmp/10;
        }
        if(c)
            result.insert(result.begin(), c+'0');
        return result;
    }
};

