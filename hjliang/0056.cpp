/**
 * 56. Merge Intervals
 * Given a collection of intervals, merge all overlapping intervals.
 */

/**
 * Runtime: 24 ms, faster than 49.32% of C++ online submissions for Merge Intervals.
 * Memory Usage: 12.4 MB, less than 75.86% of C++ online submissions for Merge Intervals.
 */

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ret;
        if (intervals.size() == 0)
            return ret;
        
        sort(intervals.begin(),intervals.end());
        ret.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); ++i) {
            if(ret.back()[1] >= intervals[i][0]) {
                ret.back()[1] = max(ret.back()[1],intervals[i][1]);
            }
            else {
                ret.push_back(intervals[i]);
            }
        }
        
        return ret;
    }    
};