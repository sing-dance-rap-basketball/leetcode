/**
 * 69. Sqrt(x)
 * Implement int sqrt(int x).
 * Compute and return the square root of x, where x is guaranteed to be a non-negative integer.
 * Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.
 */

/**
 * Runtime: 4 ms, faster than 78.83% of C++ online submissions for Sqrt(x).
 * Memory Usage: 8.1 MB, less than 77.45% of C++ online submissions for Sqrt(x).
 * newthon method
 * 0x5f375a86 -- 这个数挺好玩的…… 
 */

class Solution {
public:
    int mySqrt(int x) {
        long ret = x;   
        while(ret * ret > x) {
            ret =  ret - (ret * ret - x) / (2.0 * ret);
        }
        return int(ret);
    }
};
