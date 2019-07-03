/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */
class Solution {
public:
    int reverse(int x) {
        long y = 0;
        while(x) {
            y *= 10;
            y += x%10; 
            x/=10;
        }
        return  ( y> INT_MAX || y < INT_MIN) ? 0 : y;
    }
};

