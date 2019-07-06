/**
 * 13. Roman to Integer
 * reference to #12
 */
 
/**
 * Runtime: 4 ms, faster than 99.20% of C++ online submissions for Roman to Integer.
 * Memory Usage: 8.2 MB, less than 93.14% of C++ online submissions for Roman to Integer.
 */
class Solution {
public:
    int romanToInt(string s) {
        int length = s.size();
        int ret = 0;
        int preValue = 1000;
        for (int i = 0; i < length; ++i) {
            int value = 0; 
            switch (s[i]){
                case 'I':value = 1;      break;
                case 'V':value = 5;      break;
                case 'X':value = 10;     break;
                case 'L':value = 50;     break;
                case 'C':value = 100;    break;
                case 'D':value = 500;    break;
                case 'M':value = 1000;   break;
                default :value = 0;
            }         
            ret += (preValue >= value) ? value : (value - preValue - preValue);
            preValue = value;
        }
        return ret;
    }
};