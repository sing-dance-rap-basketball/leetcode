/**
 * 66. Plus One
 * Given a non-empty array of digits representing a non-negative integer, plus one to the integer.
 * The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.
 * You may assume the integer does not contain any leading zero, except the number 0 itself.
 */

/**
 * Runtime: 4 ms, faster than 71.37% of C++ online submissions for Plus One.
 * Memory Usage: 8.6 MB, less than 61.66% of C++ online submissions for Plus One.
 */

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size() - 1;
        while(size > 0 && digits[size] + 1 == 10) {
            digits[size] = 0;
            --size;
        }
        
        if (size == 0 &&  digits[size] + 1 == 10) {
            digits[0] = 0;
            digits.insert(digits.begin(),1);
        }
        else
            digits[size] += 1;
        
        return digits;
    }
};