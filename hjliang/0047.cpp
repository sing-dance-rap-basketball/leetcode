/**
 * 47. Permutations II
 * Given a collection of numbers that might contain duplicates, return all possible unique permutations.
 */

/**
 * Runtime: 372 ms, faster than 5.12% of C++ online submissions for Permutations II.
 * Memory Usage: 174.4 MB, less than 5.09% of C++ online submissions for Permutations II.
 * 这种涉及重复不重复的 写的都很烂
 */

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ret;
        unordered_map<string, int> lut;
        recurPermute(ret, nums, 0, lut);
        return ret;        
    }
    
private:
    void recurPermute(vector<vector<int>>& ret, vector<int>& nums, int n, 
                                                unordered_map<string, int> &lut){
        if (nums.size() == n) {
            string tmp = vec2str(nums);
            if (lut.find(tmp) == lut.end()) {
                ret.push_back(nums);
                lut.insert({tmp,1});
            }
            
        }
        else {
            for (int i = n; i < nums.size(); ++i) {
                swap(nums[n],nums[i]);
                recurPermute(ret, nums, n + 1, lut);
                swap(nums[n],nums[i]);
            }
        }
    }
    
    string vec2str(vector<int> nums) {
        stringstream ss;
        for (int i = 0; i < nums.size(); ++i) {
            ss << nums[i] << endl;
        }
        return ss.str();
    }
};
