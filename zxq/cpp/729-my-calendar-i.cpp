/*
 * @lc app=leetcode id=729 lang=cpp
 *
 * [729] My Calendar I
 */
/*
    √ Accepted
    √ 108/108 cases passed (124 ms)
    √ Your runtime beats 40.63 % of cpp submissions
    √ Your memory usage beats 100 % of cpp submissions (34.6 MB)
    √ Accepted
    √ 108/108 cases passed (116 ms)
    √ Your runtime beats 48.75 % of cpp submissions
    √ Your memory usage beats 100 % of cpp submissions (34.8 MB)
 */
class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if (start >= end) {
            return false;
        }
        if (timepairs.empty()) {
            timepairs.push_back(std::make_pair(start, end));
            return true;
        }
        if (end <= timepairs.front().first) {
            timepairs.insert(timepairs.begin(), std::make_pair(start, end));
            return true;
        }
        if (start >= timepairs.back().second) {
            timepairs.push_back(std::make_pair(start, end));
            return true;
        }
        for (int i = 0; i < timepairs.size()-1; ++i) {
            if (start >= timepairs[i].second && end <= timepairs[i+1].first) {
                timepairs.insert(timepairs.begin()+i+1, std::make_pair(start, end));
                return true;
            }
        }
        return false;
    }
private:
    std::vector<std::pair<int, int>> timepairs;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

