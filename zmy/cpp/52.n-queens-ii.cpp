/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 */
class Solution {


    void dfs(int n, int r, vector<int>& main, vector<int>& anti, vector<int>& columns, int &count) {
        if(r == n) count++;
        for(int c = 0; c<n; c++) {
            if( !main[c+r] && !anti[r+n-c-1] && !columns[c]) {
                main[c+r] = anti[r+n-c-1] = columns[c] = 1;
                dfs(n, r+1, main, anti, columns, count);
                main[c+r] = anti[r+n-c-1] = columns[c] = 0;
            }
        }
    }
public:
    int totalNQueens(int n) {
        vector<int> main(2*n), anti(2*n), columns(n);
        int count=0;
        dfs(n, 0, main, anti, columns,count);
        return count;
    }
};

