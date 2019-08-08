/**
 * 118. Pascal's Triangle
 * Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.
 */

/**
 * Runtime: 4 ms, faster than 63.34% of C++ online submissions for Pascal's Triangle.
 * Memory Usage: 8.8 MB, less than 74.07% of C++ online submissions for Pascal's Triangle.
 */

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        if (numRows == 0)
            return ret;
        ret.push_back({1});
        for (int i = 1; i < numRows; ++i) {
            vector<int> tmp;
            for (int j = 0; j <= i; ++j) {
                if (j == 0 || j == i)
                    tmp.push_back(1);
                else
                    tmp.push_back(ret[i-1][j-1]+ret[i-1][j]);
            }
            ret.push_back(tmp);
        }
        return ret;
    }
};