/**
 * 6. ZigZag Conversion
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number 
 * of rows like this: (you may want to display this pattern in a fixed font for 
 * better legibility)
 *
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 *
 * And then read line by line: "PAHNAPLSIIGYIR"
 * Write the code that will take a string and make this conversion given a number of rows:
 *
 *  	string convert(string s, int numRows);
 *
 * for strLen = 15, n = 5   a direct example is:
 *      0       8 
 *		1     7 9        15
 *		2   6   10    14        =====>>   0 8 1 7 9 15 2 6 10 14 3 5 11 13 4 12
 *		3 5     11 13
 *		4       12
 */
 
/**
 * Runtime: 12 ms, faster than 86.59% of C++ online submissions for ZigZag Conversion.
 * Memory Usage: 10 MB, less than 90.96% of C++ online submissions for ZigZag Conversion.
 */
 
class Solution {
public:
    string convert(string s, int numRows) {
        int strLen = s.length();
        if(numRows == 1)
            return s;
        string retStr(strLen,'\0');
        int retIndex = 0;
        
        int inc1 = 2 * (numRows - 1);
        int inc2 = 0;
        
        for(int i = 0; i < numRows; ++i){
            int index = i;
            int count = 0;
            
            while(index < strLen){
                int inInc1 = (inc1 <= 0) ? 2 * (numRows - 1):inc1;
                int inInc2 = (inc2 <= 0) ? 2 * (numRows - 1):inc2;

                retStr[retIndex++] = s[index];
                
                index += ( (count%2==0)?inInc1:inInc2);
                count++;
            }
            
            inc1 = inc1 - 2;
            inc2 = inc2 + 2;
        }
        return retStr;
    }
};