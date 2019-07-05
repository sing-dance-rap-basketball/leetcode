/**
 * 7. Reverse Integer
 * Given a 32-bit signed integer, reverse digits of an integer.
 * Assume we are dealing with an environment which could only store integers 
 * within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of 
 * this problem, assume that your function returns 0 when the reversed integer 
 * overflows.
 */

 
/**
 * Runtime: 4 ms, faster than 81.52% of C++ online submissions for Reverse Integer.
 * Memory Usage: 8.3 MB, less than 28.44% of C++ online submissions for Reverse Integer.
 */
 
class Solution {
public:
    int reverse(int x) {
        long long tmp = 0;
        while (x != 0) {
            tmp = tmp * 10 + x % 10;
            x /= 10;
        }
        if(tmp > INT_MAX || tmp < INT_MIN)
            return 0;
        else
            return (int)tmp;
    }
};