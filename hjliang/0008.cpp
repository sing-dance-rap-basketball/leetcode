/*
 * 8. String to Integer (atoi)
 * 
 * Implement atoi which converts a string to an integer.
 * The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.
 * The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.
 * If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
 *
 * If no valid conversion could be performed, a zero value is returned.
 * Note:
 * 		1.Only the space character ' ' is considered as whitespace character.
 * 		2.Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. If the numerical value is out of the range of representable values, INT_MAX (231 − 1) or INT_MIN (−231) is returned.
 */
 
/* 
 * Runtime: 8 ms, faster than 67.31% of C++ online submissions for String to Integer (atoi).
 * Memory Usage: 8.5 MB, less than 43.15% of C++ online submissions for String to Integer (atoi).
 *
 */
 
class Solution {
public:
    int myAtoi(string str) {
        int index = 0;
        int ret = 0;
        while (str[index] == ' ') 
            ++index;
        
        char flag = 1;
        if (str[index] == '+' || str[index] == '-')
            flag = (str[index++] == '+')?1:-1;
  
        while (str[index] >= '0' && str[index] <= '9' && str[index] != '\0') { 
            int chtoi =  flag * (str[index++] - '0');
            
            //the method to check overflow in 7. Reverse Integer's solution
            if(ret > INT_MAX / 10 || (ret == INT_MAX /10 && chtoi > 7))
                return INT_MAX;
            if(ret < INT_MIN / 10 || (ret == INT_MIN /10 && chtoi < -8))
                return INT_MIN;               

            ret = ret * 10 + chtoi;
        }
        return ret;
    }
};