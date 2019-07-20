/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// /*
// × Time Limit Exceeded
//   × 41/62 cases passed (N/A)
//   × testcase: '51\n9'
//   × answer: 
//   × expected_answer: 
//   × stdout:
// */
// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         if (m == 1 || n == 1) {
//             return 1;
//         }
//         else if (m > 1 && n > 1) {
//             return uniquePaths(m-1, n) + uniquePaths(m, n-1);
//         }
//         return 1;
//     }
// };

// /*
// × Time Limit Exceeded
//   × 43/62 cases passed (N/A)
//   × testcase: '13\n23'
//   × answer: 
//   × expected_answer: 
//   × stdout:
// */
// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         if (m == 1 || n == 1) {
//             return 1;
//         }
//         else if (m == 2 || n == 2) {
//             return m + n - 2;
//         }
//         else if (m > 2 && n > 2) {
//             return uniquePaths(m-1, n) + uniquePaths(m, n-1);
//         }
//         return 1;
//     }
// };

/*
√ Accepted
  √ 62/62 cases passed (0 ms)
  √ Your runtime beats 100 % of cpp submissions
  √ Your memory usage beats 92.65 % of cpp submissions (8.1 MB)
√ Accepted
  √ 62/62 cases passed (4 ms)
  √ Your runtime beats 66.46 % of cpp submissions
  √ Your memory usage beats 80.45 % of cpp submissions (8.2 MB)
*/
class Solution {
public:
    int combination(int a, int b)
    {
        // note: a >= b
        long res = 1;    // avoid signed integer overflow
        for (int i = a+1, j = 1; j <= b; ++i, ++j) {
            res = res * i / j;  
        }
        return (int)res;
    }
    int uniquePaths(int m, int n) {
        if (m > 1 && n > 1) {
            if (m >= n) {
                return combination(m-1, n-1);
            }
            else {
                return combination(n-1, m-1);
            }
        }
        return 1;
    }
};