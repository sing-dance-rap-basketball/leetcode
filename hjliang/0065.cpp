/**
 * 65. Valid Number
 * Validate if a given string can be interpreted as a decimal number.
 */

/**
 * Runtime: 4 ms, faster than 75.13% of C++ online submissions for Valid Number.
 * Memory Usage: 8.2 MB, less than 60.00% of C++ online submissions for Valid Number.
 * 还是状态机好玩啊…… 应该有种规范的写法
 */

class Solution {
public:
    bool isNumber(string s) {
        int state=0;
        while(s[0]==' ')  s.erase(0,1);
        while(s[s.length()-1]==' ') s.erase(s.length()-1, 1);
        
        for (int i = 0; i < s.length(); ++i) {
            switch(state) {
                case 0:
                    if (s[i] == '+' || s[i] == '-') {state = 1;break;}
                    if (s[i] >= '0' && s[i] <= '9') {state = 2;break;}
                    if (s[i] == '.') {state = 9;break;}
                    return false;
                case 1:
                    if (s[i] >= '0' && s[i] <= '9') {state = 2;break;}
                    if (s[i] == '.') {state = 8;break;}
                    return false;  
                case 2:
                    if (s[i] >= '0' && s[i] <= '9') {state = 2;break;}
                    if (s[i] == '.') {state = 6;break;}
                    if (s[i] == 'e' || s[i] == 'E') {state = 3;break;}
                    return false;
                case 3:
                    if (s[i] == '+' || s[i] == '-') {state = 4;break;}
                    if (s[i] >= '0' && s[i] <= '9') {state = 5;break;}
                    return false;                                                    
                case 4:
                    if (s[i] >= '0' && s[i] <= '9') {state = 5;break;}
                    return false;
                case 5:
                    if (s[i] >= '0' && s[i] <= '9') {state = 5;break;}
                    return false;
                case 6:
                    if (s[i] >= '0' && s[i] <= '9') {state = 7;break;}
                    if (s[i] == 'e' || s[i] == 'E') {state = 3;break;}
                    return false; 
                case 7:
                    if (s[i] >= '0' && s[i] <= '9') {state = 7;break;}
                    if (s[i] == 'e' || s[i] == 'E') {state = 3;break;}
                    return false;
                case 8:
                    if (s[i] >= '0' && s[i] <= '9') {state = 7;break;}                                           
					return false;                                                   
                case 9:
                    if (s[i] >= '0' && s[i] <= '9') {state = 7;break;}                                          
					return false; 
                default:
                    return false;
            }
            //cout << s[i] << " " << state << endl;
        } 
        return (state == 2 || state == 5 || state == 6 || state == 7);
    }
};