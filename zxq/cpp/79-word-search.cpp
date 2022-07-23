/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// /*
//     √ Accepted
//     √ 87/87 cases passed (1532 ms)
//     √ Your runtime beats 5.04 % of cpp submissions
//     √ Your memory usage beats 5.01 % of cpp submissions (357.8 MB)
//     √ Accepted
//     √ 87/87 cases passed (1516 ms)
//     √ Your runtime beats 5.04 % of cpp submissions
//     √ Your memory usage beats 5.01 % of cpp submissions (357.6 MB)
//  */
// class Solution {
// public:
//     int nrow;
//     int ncol;
//     bool exist(vector<vector<char>>& board, string word) {
//         if (board.empty()) { return word.empty(); }
//         if (board[0].empty()) { return word.empty(); }
//         nrow = board.size();
//         ncol = board[0].size();
//         if (nrow * ncol < word.size()) { return false; }

//         vector<vector<int>> log = {};
//         for (int i = 0; i < nrow; ++i) {
//             for (int j = 0; j < ncol; ++j) {
//                 log.push_back({i, j});
//                 if (Backtrack(board, word, log, 0)) {
//                     return true;
//                 }
//             }
//         }

//         return false;
//     }

//     bool Backtrack(const vector<vector<char>>& board, const string& word, vector<vector<int>>& log, int k)
//     {
//         if (board[log[k][0]][log[k][1]] != word[k]) {
//             log.pop_back();
//             return false;
//         }
//         else {
//             if (k == word.size()-1) {
//                 return true;
//             }
//         }
//         // up
//         if (isAvailable(log, log[k][0] - 1, log[k][1])) {
//             log.push_back({log[k][0] - 1, log[k][1]});
//             if (Backtrack(board, word, log, k+1)) {
//                 return true;
//             }
//         }
//         // left
//         if (isAvailable(log, log[k][0], log[k][1] - 1)) {
//             log.push_back({log[k][0], log[k][1] - 1});
//             if (Backtrack(board, word, log, k+1)) {
//                 return true;
//             }
//         }
//         // down
//         if (isAvailable(log, log[k][0] + 1, log[k][1])) {
//             log.push_back({log[k][0] + 1, log[k][1]});
//             if (Backtrack(board, word, log, k+1)) {
//                 return true;
//             }
//         }
//         // right
//         if (isAvailable(log, log[k][0], log[k][1] + 1)) {
//             log.push_back({log[k][0], log[k][1] + 1});
//             if (Backtrack(board, word, log, k+1)) {
//                 return true;
//             }
//         }

//         log.pop_back();
//         return false;
//     }

//     bool isAvailable(const vector<vector<int>>& log, int i, int j)
//     {
//         if (i < 0 || i >= nrow) { return false; }
//         if (j < 0 || j >= ncol) { return false; }
//         // if (std::find(log.begin(), log.end(), {i, j}) != log.end()) {
//         //     return false;
//         // }
//         for (auto& pos : log) {
//             if (pos == vector<int> {i, j}) {
//                 return false;
//             }
//         }
//         return true;
//     }
// };

// /*
//     Reduce redundant function calls
//     √ Accepted
//     √ 87/87 cases passed (456 ms)
//     √ Your runtime beats 5.96 % of cpp submissions
//     √ Your memory usage beats 5.13 % of cpp submissions (163 MB)
//     √ Accepted
//     √ 87/87 cases passed (452 ms)
//     √ Your runtime beats 6.01 % of cpp submissions
//     √ Your memory usage beats 5.13 % of cpp submissions (162.8 MB)
//  */
// class Solution {
// public:
//     int nrow;
//     int ncol;
//     bool exist(vector<vector<char>>& board, string word) {
//         if (board.empty()) { return word.empty(); }
//         if (board[0].empty()) { return word.empty(); }
//         nrow = board.size();
//         ncol = board[0].size();
//         if (nrow * ncol < word.size()) { return false; }

//         vector<vector<int>> log = {};
//         for (int i = 0; i < nrow; ++i) {
//             for (int j = 0; j < ncol; ++j) {
//                 if (board[i][j] == word[0]) {
//                     log.push_back({i, j});
//                     if (Backtrack(board, word, log, 0)) {
//                         return true;
//                     }
//                 }
//             }
//         }

//         return false;
//     }

//     bool Backtrack(const vector<vector<char>>& board, const string& word, vector<vector<int>>& log, int k)
//     {
//         if (k == word.size()-1) {
//             return true;
//         }
//         // up
//         if (log[k][0] > 0 
//             && std::find(log.begin(), log.end(), vector<int> {log[k][0]-1, log[k][1]}) == log.end()) {
//             if (board[log[k][0]-1][log[k][1]] == word[k+1]) {
//                 log.push_back({log[k][0] - 1, log[k][1]});
//                 if (Backtrack(board, word, log, k+1)) {
//                     return true;
//                 }
//             }
            
//         }
//         // left
//         if (log[k][1] > 0 
//             && std::find(log.begin(), log.end(), vector<int> {log[k][0], log[k][1]-1}) == log.end()) {
//             if (board[log[k][0]][log[k][1]-1] == word[k+1]) {
//                 log.push_back({log[k][0], log[k][1] - 1});
//                 if (Backtrack(board, word, log, k+1)) {
//                     return true;
//                 }
//             }
//         }
//         // down
//         if (log[k][0] + 1 < nrow
//             && std::find(log.begin(), log.end(), vector<int> {log[k][0]+1, log[k][1]}) == log.end()) {
//             if (board[log[k][0]+1][log[k][1]] == word[k+1]) {
//                 log.push_back({log[k][0] + 1, log[k][1]});
//                 if (Backtrack(board, word, log, k+1)) {
//                     return true;
//                 }
//             }
//         }
//         // right
//         if (log[k][1] + 1 < ncol 
//             && std::find(log.begin(), log.end(), vector<int> {log[k][0], log[k][1]+1}) == log.end()) {
//             if (board[log[k][0]][log[k][1]+1] == word[k+1]) {
//                 log.push_back({log[k][0], log[k][1] + 1});
//                 if (Backtrack(board, word, log, k+1)) {
//                     return true;
//                 }
//             }
//         }

//         log.pop_back();
//         return false;
//     }
// };

/*
    Top voted solution
    √ Accepted
    √ 87/87 cases passed (32 ms)
    √ Your runtime beats 72.01 % of cpp submissions
    √ Your memory usage beats 55.34 % of cpp submissions (14.4 MB)
    √ Accepted
    √ 87/87 cases passed (28 ms)
    √ Your runtime beats 76.64 % of cpp submissions
    √ Your memory usage beats 55.21 % of cpp submissions (14.6 MB)
    √ Accepted
    √ 87/87 cases passed (24 ms)
    √ Your runtime beats 87.97 % of cpp submissions
    √ Your memory usage beats 55.21 % of cpp submissions (14.5 MB)
 */
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty()) { return word.empty(); }
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (Dfs(board, word, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool Dfs(vector<vector<char>>& board, string& word, int i, int j)
    {
        if (word.empty()) { return true; }
        if (i < 0 || i>= board.size() 
            || j < 0 || j >= board[0].size()
            || board[i][j] != word[0]) {
            return false;
        }
        string sub = word.substr(1);
        char letter = board[i][j];
        board[i][j] = '*';
        bool res = Dfs(board, sub, i-1, j) || Dfs(board, sub, i+1, j) 
                    || Dfs(board, sub, i, j-1) || Dfs(board, sub, i, j+1);
        board[i][j] = letter;
        return res;
    }
};