#
# @lc app=leetcode id=46 lang=python3
#
# [46] Permutations
#

# @lc code=start

# Accepted
# 26/26 cases passed (97 ms)
# Your runtime beats 5.33 % of python3 submissions
# Your memory usage beats 83.74 % of python3 submissions (13.9 MB)
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        if len(nums) == 1:
            return [nums]
        
        res = []
        for i in range(len(nums)):
            new_nums = nums[:i] + nums[i+1:]
            res_i = self.permute(new_nums)
            for l in res_i:
                l.append(nums[i])
            res += res_i

        return res
    
# @lc code=end

