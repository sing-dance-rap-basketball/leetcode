/**
 * 43. Multiply Strings
 * Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.
 */

/**
 * Runtime: 4 ms, faster than 96.16% of C++ online submissions for Multiply Strings.
 * Memory Usage: 8.8 MB, less than 59.15% of C++ online submissions for Multiply Strings.
 */

class Solution {
public:
    string multiply(string num1, string num2) {
        int l1 = num1.length(), l2 = num2.length();
        int resultL = l1 + l2;
        int *resInt = new int[resultL];
        memset(resInt, 0, resultL * sizeof(int));
        for (int i = l1 - 1; i >= 0; --i) {
            for (int j = l2 - 1; j >= 0; --j) {
                resInt[i + j + 1] += (num1[i] - '0') * (num2[j] - '0'); 
            }
        }
        
        for (int i = resultL - 1; i >= 0; --i) {
            if (resInt[i] > 9) {
                resInt[i - 1] += resInt[i] / 10;
                resInt[i] = resInt[i] % 10;
            }   
        }
        
        string ret;
        int index = 0;
        while(resInt[index] == 0) {
            ++index;
            if (index > resultL - 1)
                return "0";
        }
        for(;index < resultL; ++ index)
            ret += (resInt[index] + '0');
        
        return ret;
    }
};
