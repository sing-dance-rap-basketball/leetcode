/**
 * 29. Divide Two Integers
 * Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.
 * Return the quotient after dividing dividend by divisor.
 * The integer division should truncate toward zero.
 */
 

/**
 * Runtime: 4 ms, faster than 85.45% of C++ online submissions for Divide Two Integers.
 * Memory Usage: 8.2 MB, less than 30.94% of C++ online submissions for Divide Two Integers.
 * 主要问题是时间的限制  应该可以模拟硬件结构实现……
 */

class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign = 1;
        int ret = 0;
        if (divisor == 0) {
            //or something
            return 0;
        }   
        if (divisor == 1)
            return dividend;
        
        if (dividend > 0) {
            dividend = -dividend;
            sign *= -1;
        }
        if (divisor > 0) {
            divisor = -divisor;
            sign *= -1;
        }
        
        while (dividend <= divisor) {
            int divisorTmp = divisor;
            int inc = 1;
            
            while (dividend <= divisorTmp) {
                dividend -= divisorTmp;
                
                if(ret <= INT_MAX - inc)
                    ret += inc;
                
                if (-divisorTmp < INT_MAX >> 2  && inc < INT_MAX >> 2) {
                    divisorTmp = -(-divisorTmp << 2);
                    inc <<=2;
                }
            }
        }
        return sign * ret;
    }
};