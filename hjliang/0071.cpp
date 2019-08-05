/**
 * 71. Simplify Path
 * Given an absolute path for a file (Unix-style), simplify it. Or in other words, convert it to the canonical path.
 * In a UNIX-style file system, a period . refers to the current directory. Furthermore, a double period .. moves the directory up a level. For more information, see: Absolute path vs relative path in Linux/Unix
 * Note that the returned canonical path must always begin with a slash /, and there must be only a single slash / between two directory names. The last directory name (if it exists) must not end with a trailing /. Also, the canonical path must be the shortest string representing the absolute path.
 */

/**
 * Runtime: 16 ms, faster than 9.75% of C++ online submissions for Simplify Path.
 * Memory Usage: 9.6 MB, less than 96.08% of C++ online submissions for Simplify Path.
 * 补裤子解法  明天改……
 */

class Solution {
public:
    string simplifyPath(string path) {
        int len = path.length();
        string subPath = "";
        deque<string> p;
        for(int i = 0; i < len; ++i) {
            if (path[i] == '/') {
                if (subPath == "..") {
                    if (p.empty() != true)
                        p.pop_back();    
                }
                else if (subPath == ".") {
                    ;
                }
                else {
                    if (subPath != "") {
                        p.push_back(subPath);
                        cout << p.back() << endl;
                    }
                }
                subPath = "";
            }
            else
                subPath += path[i];
        }
        
        if (subPath == "..") {
            if (p.empty() != true)
                p.pop_back();  
            subPath = "";
        }
        else if (subPath == ".")
            subPath = "";
        else if (subPath != "")
            p.push_back(subPath);
        subPath = "";

        if (p.empty() == true)
            subPath += '/';
        
        while(p.empty() != true) {
            string tmp = p.front();
            p.pop_front();
            subPath += "/" + tmp;
        }
        return subPath;
    }
};