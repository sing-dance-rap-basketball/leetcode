/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */
class Solution {
public:
    int myAtoi(string str) {
        long result = 0;
        int flag = 1;
        for (int i=str.find_first_not_of(' '); i<str.size(); ) {
            if(str[i] == '-' || str[i] == '+') {
                flag = ((str[i++] == '-')?-1:1);
            }
            while (str[i] >='0' && str[i]<='9') {
                result *= 10;
                result += (str[i++] - '0');
                if(result*flag >= INT_MAX) return INT_MAX;
                if(result*flag <= INT_MIN) return INT_MIN;
            }
            break;
        }
        return result * flag;
    }
};

