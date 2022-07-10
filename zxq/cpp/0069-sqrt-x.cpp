/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start

/*
    Line 11: Char 21: runtime error: signed integer overflow: 1073697799 * 1073697799 cannot be represented in type 'int' (solution.cpp)
    Line 11: Char 21: runtime error: signed integer overflow: 1073697799 * 1073697799 cannot be represented in type 'int' (solution.cpp)
    SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior prog_joined.cpp:22:21
 */
// class Solution {
// public:
//     int mySqrt(int x) {
//         if (x < 0) {
//             exit(1);
//         }

//         int l = 0, r = x;
//         int mid = x / 2;
//         while (l < r) {
//             if (mid * mid == x) {
//                 return mid;
//             }
//             else if (mid * mid > x) {
//                 int tmp = mid - 1;
//                 if (tmp * tmp <= x) {
//                     return mid - 1;
//                 }
//                 else {
//                     r = tmp;
//                     mid = (l + r) / 2;
//                 }
//             }
//             else {
//                 int tmp = mid + 1;
//                 if (tmp * tmp > x) {
//                     return mid;
//                 }
//                 else if (tmp * tmp == x) {
//                     return tmp;
//                 }
//                 else {
//                     l = tmp;
//                     mid = (l + r) / 2;
//                 }
//             }
//         }

//         return 0;
//     }
// };


/*
    Accepted
    1017/1017 cases passed (4 ms)
    Your runtime beats 67.1 % of cpp submissions
    Your memory usage beats 100 % of cpp submissions (6 MB)
*/
class Solution {
public:
    int mySqrt(int x) {
        if (x < 0) {
            exit(1);
        }

        long l = 0, r = x;
        long mid = x / 2;
        while (l < r) {
            if (mid * mid == x) {
                return mid;
            }
            else if (mid * mid > x) {
                long tmp = mid - 1;
                if (tmp * tmp <= x) {
                    return mid - 1;
                }
                else {
                    r = tmp;
                    mid = (l + r) / 2;
                }
            }
            else {
                long tmp = mid + 1;
                if (tmp * tmp > x) {
                    return mid;
                }
                else if (tmp * tmp == x) {
                    return tmp;
                }
                else {
                    l = tmp;
                    mid = (l + r) / 2;
                }
            }
        }

        return 0;
    }
};
// @lc code=end

