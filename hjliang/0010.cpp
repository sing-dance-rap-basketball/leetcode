/**
 * 10. Regular Expression Matching
 * Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 * The matching should cover the entire input string (not partial).
 * Note:
 * 		s could be empty and contains only lowercase letters a-z.
 * 		p could be empty and contains only lowercase letters a-z, and characters like . or *. 
*/

/* 
 * 本想自己写一个状态机，但没写出来，对'*'的处理没有好的思路
 * 便参考了solution的递归方法  
 * 存在'*'时，采用了一种两头堵的思想:1.匹配0个  2.匹配一个 不断递归从而完成对'*'的处理
 * 时间复杂度的分析很复杂，可以研究下……
 */

class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty())
            return s.empty();
        
        bool firstMatch = (!s.empty() &&
                           (p[0] == s[0] || p[0] == '.'));
        
        if (p.length() >= 2 && p[1] == '*') {
            return (isMatch(s,p.substr(2)) ||
                    (firstMatch && isMatch(s.substr(1),p)));
        }
        else
            return firstMatch && isMatch(s.substr(1),p.substr(1));
   
    }
};