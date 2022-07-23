/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */

/*
√ Accepted
  √ 154/154 cases passed (20 ms)
  √ Your runtime beats 59.29 % of cpp submissions
  √ Your memory usage beats 19.68 % of cpp submissions (12.7 MB)
√ Accepted
  √ 154/154 cases passed (16 ms)
  √ Your runtime beats 83.92 % of cpp submissions
  √ Your memory usage beats 34.57 % of cpp submissions (12.5 MB)
√ Accepted
  √ 154/154 cases passed (12 ms)
  √ Your runtime beats 98.49 % of cpp submissions
  √ Your memory usage beats 23.91 % of cpp submissions (12.6 MB)
*/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        if (intervals.empty()) {
            res.push_back(newInterval);
            return res;
        }

        int left = newInterval[0], right = newInterval[1];
        for (int i = 0; i < intervals.size(); ++i) {
            if (intervals[i][1] < left) {
                res.push_back(intervals[i]);
            }
            else if (intervals[i][0] <= left && intervals[i][1] >= left) {
                if (intervals[i][1] >= right) {
                    res.insert(res.end(), intervals.begin()+i, intervals.end());
                    return res;
                }
                else {  // intervals[i][1] < right
                    for (int j = i+1; j < intervals.size(); ++j) {
                        if (intervals[j][0] > right) {
                            res.push_back(vector<int> {intervals[i][0], right});
                            res.insert(res.end(), intervals.begin()+j, intervals.end());
                            return res;
                        }
                        else if (intervals[j][0] <= right && intervals[j][1] >= right) {
                            res.push_back(vector<int> {intervals[i][0], intervals[j][1]});
                            res.insert(res.end(), intervals.begin()+j+1, intervals.end());
                            return res;
                        }
                        else {  // intervals[j][1] < right
                            continue;
                        }
                    }
                    res.push_back(vector<int> {intervals[i][0], right});
                    return res;
                }
            }
            else {  // intervals[i][0] > left
                for (int j = i; j < intervals.size(); ++j) {
                    if (intervals[j][0] > right) {
                        res.push_back(newInterval);
                        res.insert(res.end(), intervals.begin()+j, intervals.end());
                        return res;
                    }
                    else if (intervals[j][0] <= right && intervals[j][1] >= right) {
                        res.push_back(vector<int> {left, intervals[j][1]});
                        res.insert(res.end(), intervals.begin()+j+1, intervals.end());
                        return res;
                    }
                    else {  // intervals[j][1] < right
                        continue;
                    }
                }
                res.push_back(newInterval);
                return res;
            }
        }
        res.push_back(newInterval);
        return res;
    }
};

