/**
 * 28. Implement strStr()
 * Implement strStr().
 * Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 * 
 * *** What should we return when needle is an empty string? This is a great question to ask during an interview.
F* *** or the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
 */

/**
 * Runtime: 4 ms, faster than 94.10% of C++ online submissions for Implement strStr().
 * Memory Usage: 8.9 MB, less than 93.85% of C++ online submissions for Implement strStr().
 */

class Solution {
public:
    int strStr(string haystack, string needle) {
        int hIndex = 0;
        int hLength = haystack.length();
        int nLength = needle.length();
        
        if (nLength == 0)
            return 0;
        if (nLength > hLength)
            return -1;
        
        while (haystack[hIndex] != '\0') {
            int nIndex = 0;
            int tmpIndex = hIndex;
            for (; nIndex < nLength; ++nIndex,++tmpIndex) {
                if (haystack[tmpIndex] == '\0')
                    return -1;
                if (haystack[tmpIndex] != needle[nIndex]) 
                    break;
            }
            if(nIndex == nLength)
                return hIndex;
            
            ++hIndex;
        }
        return -1;
    }
};