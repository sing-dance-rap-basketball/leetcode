/*
 * @lc app=leetcode id=495 lang=cpp
 *
 * [495] Teemo Attacking
 */

/*
    √ Accepted
    √ 39/39 cases passed (56 ms)
    √ Your runtime beats 94.05 % of cpp submissions
    √ Your memory usage beats 83.33 % of cpp submissions (10.9 MB)
 */
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if (timeSeries.empty() || duration == 0) { return 0; }
        int res = 0;
        int curr_poison_end;
        int last_poison_end = timeSeries[0] - 1;
        for (auto time : timeSeries) {
            curr_poison_end = time + duration - 1;
            if (time > last_poison_end) {
                res += duration;
            }
            else {
                res += (curr_poison_end - last_poison_end);
            }
            last_poison_end = curr_poison_end;
        }
        return res;
    }
};

