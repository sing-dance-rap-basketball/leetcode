/**
 * 57. Insert Interval
 * Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
 * You may assume that the intervals were initially sorted according to their start times.
 */

/**
 * Runtime: 40 ms, faster than 9.18% of C++ online submissions for Insert Interval.
 * Memory Usage: 12.4 MB, less than 71.15% of C++ online submissions for Insert Interval.
 * 直接用上一题改的…… 这题的条件使得sort略显多余 应直接插入合适的位置
 */

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        return merge(intervals);
    }
    
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