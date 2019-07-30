/**
 * 67. Add Binary
 * Given two binary strings, return their sum (also a binary string).
 * The input strings are both non-empty and contains only characters 1 or 0.
 */

/**
 * Runtime: 8 ms, faster than 34.12% of C++ online submissions for Add Binary.
 * Memory Usage: 9.1 MB, less than 36.74% of C++ online submissions for Add Binary. 
 */

class Solution {
public:
    string addBinary(string a, string b) {
        string ret;
        int carry = 0;
        int la = a.length() - 1, lb = b.length() - 1;
        while(la >= 0 && lb >= 0) {
            char tmp = a[la] + b[lb] - '0' + carry;
            carry = 0;
            if (tmp > '1') {
                tmp = '0' + (tmp - '0') % 2;
                carry = 1;
            }
            ret = string(1,tmp) + ret;
            --la;
            --lb;
        }
        
        while(la >= 0) {
            char tmp = a[la] + carry;
            carry = 0;
            if (tmp == '2') {
                tmp = '0';
                carry = 1;
            }
            ret = string(1,tmp) + ret;
            --la;        
        }
        
        while(lb >= 0) {
            char tmp = b[lb]  + carry;
            carry = 0;
            if (tmp == '2') {
                tmp = '0';
                carry = 1;
            }
            ret = string(1,tmp) + ret;
            --lb;        
        }
        
        if (carry == 1)
            ret = "1" +ret;
        
        return ret;
    }
};
