/*
 * 1. Two Sum
 * Given an array of integers, return indices of the two numbers such that they 
 * add up to a specific target.
 * You may assume that each input would have exactly one solution, and you may 
 * not use the same element twice.
 *
 * Example:
 * 		Given nums = [2, 7, 11, 15], target = 9,
 * 		Because nums[0] + nums[1] = 2 + 7 = 9,
 * 		return [0, 1].
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int nums_size = nums.size();
        
        for(int i = 0; i < nums_size; ++i){
            int res = target - nums[i];	/* reduce the access of nums[i] */
            for(int j = i + 1; j < nums_size; ++j){
                if(res ==  nums[j])
                    return vector<int> {i,j};
            }
        }
        
    return vector<int>{-1,-1};
    }
};

/*
 * another solution using hash to reduce time complexity
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        unordered_map<int,int> hash;
        
        for(int i = 0; i < size; ++i){
            int comp = target - nums[i];
            if(hash.find(comp) != hash.end())
                return vector<int> {hash[comp],i};
            
            hash.insert({nums[i],i});
        }
		
        return vector<int> {-1,-1}; 
    }
};
