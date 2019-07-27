/**
 * 58. Length of Last Word
 * Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
 * If the last word does not exist, return 0.
 */

/**
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions for Length of Last Word.
 * Memory Usage: 8.9 MB, less than 18.37% of C++ online submissions for Length of Last Word.
 */

class Solution {
public:
    int lengthOfLastWord(string s) 
    {
        int length = 0;
        for(int i = s.size() - 1; i >= 0; i--)
        {
            if(s[i] == ' '){
                if(length != 0)
                    break;
            }
            else{
                length++;
            }
        }
        return length;
    }
};