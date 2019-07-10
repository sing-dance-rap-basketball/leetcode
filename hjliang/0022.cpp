/**
 * 22. Generate Parentheses
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 */

/**
 * Runtime: 8 ms, faster than 69.17% of C++ online submissions for Generate Parentheses.
 * Memory Usage: 17.4 MB, less than 27.58% of C++ online submissions for Generate Parentheses.
 * 回溯法  或者说DFS 有点意思
 */
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        backtrack("", n, n);
        return res;
    }
    
  
private:
    vector<string> res;
    void backtrack(string substring, int left, int right)
    {
        cout << left << " " << right << endl;
        if (left == 0 && right == 0) {
            res.push_back(substring);
            return;
        }
        
        if (left > right)
            return;
        if (left > 0)
            backtrack(substring + "(", left -1, right);
        if (right > 0)
            backtrack(substring + ")", left, right - 1);
    }
};

/**
 * 答案应该是对了 但是n>8之后会time out……
 * 所用的递归的思想太麻烦
 */
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        ParenthesisSet(n,"");
        auto iter = buf.begin();
        while (iter != buf.end()) 
            ret.push_back(*iter++);
        return ret;
    }
    
  
private:
    set<string> buf;
    void ParenthesisSet(int n, string sub)
    {
        if (n == 0) {
            if (buf.find(sub) == buf.end())
                buf.insert(sub);
        }
        else {
            int length = sub.length();
            //cout << "legnth = " << length << endl;
            for (int i = 0; i < length + 1; i++) {
                string tmp = sub;
                //cout << n-1 << " " << sub << " " << i << endl;
                ParenthesisSet(n-1,tmp.insert(i,"()"));
            }
        }
    }
};