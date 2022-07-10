/*
 * @lc app=leetcode id=780 lang=cpp
 *
 * [780] Reaching Points
 */

/*
    √ Accepted
    √ 190/190 cases passed (0 ms)
    √ Your runtime beats 100 % of cpp submissions
    √ Your memory usage beats 100 % of cpp submissions (8 MB)
 */
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (true) {
            if (sx > tx || sy > ty) {
                return false;
            }
            if (sx == tx && sy == ty) {
                return true;
            }

            // now sx <= tx && sy <= ty (except sx == tx && sy == ty)
            if (tx > ty) {
                if (sy == ty) {
                    return (tx - sx) % ty == 0;
                }
                else {  // sy < ty
                    tx = tx % ty == 0 ? ty : tx % ty;
                }
            }
            else if (tx < ty) {
                if (sx == tx) {
                    return (ty - sy) % tx == 0;
                }
                else { // sx < tx
                    ty = ty % tx == 0 ? tx : ty % tx;
                }
            }
            else {  // tx == ty
                break;
            }
        }
        return false;
    }
};

