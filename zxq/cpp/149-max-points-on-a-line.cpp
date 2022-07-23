/*
 * @lc app=leetcode id=149 lang=cpp
 *
 * [149] Max Points on a Line
 */

// @lc code=start
/**
 * Accepted
 *  37/37 cases passed (24 ms)
 *  Your runtime beats 49.94 % of cpp submissions
 *  Your memory usage beats 78.57 % of cpp submissions (9.4 MB)
 */
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if (points.empty()) {
            return 0;
        }

        map<pair<long, long>, int> map;
        int ans = 0;

        for (int i = points.size() - 1; i > 0; --i) {
            int currMax = 0;
            int samePoint = 0;
            for (int j = i - 1; j >= 0; --j) {
                pair<long, long> direction(points[j][0] - points[i][0], points[j][1] - points[i][1]);
                if (direction != make_pair(0L, 0L)) {
                    reduce(direction);
                    int cnt = ++map[direction];
                    if (cnt > currMax) {
                        currMax = cnt;
                    }
                }
                else {
                    ++samePoint;
                }
            }
            if (currMax + samePoint > ans) {
                ans = currMax + samePoint;
            }
            currMax = 0;
            samePoint = 0;
            map.clear();
        }

        return ans + 1;
    }

    void reduce(pair<long, long>& direction) {
        if (direction.first == 0L) {
            direction.second = 1L;
            return;
        }
        if (direction.second == 0L) {
            direction.first = 1L;
            return;
        }

        long x1 = abs(direction.first);
        long x2 = abs(direction.second);
        if (x1 < x2) {
            long temp = x1;
            x1 = x2;
            x2 = temp;
        }
        
        // compute gcd(x1, x2)
        while (x2 != 0) {
            long remainder = x1 % x2;
            x1 = x2;
            x2 = remainder;
        }

        // reduce
        direction.first /= x1;
        direction.second /= x1;
        
        // keep the first item positive
        if (direction.first < 0) {
            direction.first *= -1L;
            direction.second *= -1L;
        }
    }
};

// class Solution {
// public:
//     int maxPoints(vector<vector<int>>& points) {
//         if (points.empty()) {
//             return 0;
//         }

//         unordered_map<pair<long, long>, int, pair_hash> umap;
//         int ans = 0;

//         for (int i = points.size() - 1; i > 0; --i) {
//             int currMax = 0;
//             int samePoint = 0;
//             for (int j = i - 1; j >= 0; --j) {
//                 pair<long, long> direction(points[j][0] - points[i][0], points[j][1] - points[i][1]);
//                 if (direction != make_pair(0L, 0L)) {
//                     reduce(direction);
//                     int cnt = ++umap[direction];
//                     if (cnt > currMax) {
//                         currMax = cnt;
//                     }
//                 }
//                 else {
//                     ++samePoint;
//                 }
//             }
//             if (currMax + samePoint > ans) {
//                 ans = currMax + samePoint;
//             }
//             currMax = 0;
//             samePoint = 0;
//             umap.clear();
//         }

//         return ans + 1;
//     }

//     struct pair_hash
//     {
//         template<class T1, class T2>
//         std::size_t operator() (const std::pair<T1, T2>& p) const
//         {
//             auto h1 = std::hash<T1>{}(p.first);
//             auto h2 = std::hash<T2>{}(p.second);
//             return h1 ^ h2;
//         }
//     };

//     void reduce(pair<long, long>& direction) {
//         if (direction.first == 0L) {
//             direction.second = 1L;
//             return;
//         }

//         long x1 = abs(direction.first);
//         long x2 = abs(direction.second);
//         if (x1 < x2) {
//             long temp = x1;
//             x1 = x2;
//             x2 = temp;
//         }
        
//         // compute gcd(x1, x2)
//         while (x2 != 0) {
//             long remainder = x1 % x2;
//             x1 = x2;
//             x2 = remainder;
//         }

//         // reduce
//         direction.first /= x1;
//         direction.second /= x1;
        
//         // keep the first item positive
//         if (direction.first < 0) {
//             direction.first *= -1L;
//             direction.second *= -1L;
//         }
//     }
// };
// @lc code=end

