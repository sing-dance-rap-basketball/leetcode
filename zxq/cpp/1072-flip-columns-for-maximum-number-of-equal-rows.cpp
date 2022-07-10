/*
 * @lc app=leetcode id=1072 lang=cpp
 *
 * [1072] Flip Columns For Maximum Number of Equal Rows
 */

// /*
//   √ 84/84 cases passed (332 ms)
//   √ Your runtime beats 36.36 % of cpp submissions
//   √ Your memory usage beats 100 % of cpp submissions (27.3 MB)
//   √ 84/84 cases passed (320 ms)
//   √ Your runtime beats 36.85 % of cpp submissions
//   √ Your memory usage beats 100 % of cpp submissions (27.4 MB)
// */
// class Solution {
// public:
//     bool isSameType(vector<int>& row1, vector<int>& row2)
//     {
//         int xorSum = 0;
//         int len = row1.size();
//         for (int i = 0; i < len; ++i) {
//             xorSum += (row1[i] ^ row2[i]);
//         }
//         return xorSum == 0 || xorSum == len;
//     }
//     int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
//         std::vector<int> count(matrix.size(), 0);
//         int max = 1;
//         for (int i = 0; i < matrix.size(); ++i) {
//             bool isFound = false;
//             for (int j = 0; j < i; ++j) {
//                 if (count[j] > 0) {
//                     if (isSameType(matrix[j], matrix[i])) {
//                         isFound = true;
//                         count[j] += 1;
//                         if (max < count[j]) { max = count[j]; }
//                         break;
//                     }
//                 }
//             }
//             if (!isFound) {
//                 count[i] = 1;
//             }
//         }
//         return max;
//     }
// };

// /*
//   √ 84/84 cases passed (252 ms)
//   √ Your runtime beats 42.63 % of cpp submissions
//   √ Your memory usage beats 100 % of cpp submissions (60.3 MB)
// */
// class Solution {
// public:
//     vector<int> complement(vector<int>& row)
//     {
//         vector<int> result;
//         for (int v : row) {
//             result.push_back(v ^ 1);
//         }
//         return result;
//     }
//     int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
//         std::map<vector<int>, int> m;
//         int max = 1;
//         for (auto& v : matrix) {
//             auto temp = complement(v);
//             if (m.find(v) != m.end() || m.find(temp) != m.end()) {
//                 max = std::max(max, ++m[v]);
//                 ++m[temp];
//             }
//             else {
//                 m[v] = 1;
//                 m[temp] = 1;
//             }
//         }
//         return max;
//     }
// };

/*
  √ 84/84 cases passed (184 ms)
  √ Your runtime beats 80.07 % of cpp submissions
  √ Your memory usage beats 100 % of cpp submissions (42.6 MB)
  √ 84/84 cases passed (216 ms)
  √ Your runtime beats 52.11 % of cpp submissions
  √ Your memory usage beats 100 % of cpp submissions (42.7 MB)
*/
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int result = 1;
        std::unordered_map<std::string, int> umap;
        for(auto& row : matrix){
            std::string temp1, temp2;
            for(auto& v : row){
                temp1 += v;
                temp2 += !v;
            }
            result = std::max(result, ++umap[temp1]); 
            ++umap[temp2];
        }
        return result;
    }
};