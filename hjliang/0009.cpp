/*
 * 9. Palindrome Number
 * Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.
 */
 
/*
 * Runtime: 8 ms, faster than 94.63% of C++ online submissions for Palindrome Number.
 * Memory Usage: 8.1 MB, less than 59.65% of C++ online submissions for Palindrome Number.
 */

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x!=0 && x % 10 ==0)) return false;
        int sum=0;
        while (x> sum) {
            sum *= 10;
            sum +=x%10;
            x /=10;
        }
        return (x==sum) || (x == sum/10);
    }
};