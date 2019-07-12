/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) 
	{
		int l = nums.size();
		int a1 = nums[0];
		int i1 = 0;
		int i2 = 0;
		for (int i = 0; i < l; i++)
		{
			
			a1 = nums[i];
			i1 = i;
		
			
			
				for (int j = 0; j < l; j++)
				{
					if (j == i)
					{
		
						continue;
						
					}
					else
						if (a1 + nums[j] == target)
						{
							i2 = j;
							int l2[2];
							l2[0] = i1;
							l2[1] = i2;
							vector<int> l1(l2, l2 + 2);
							return l1;
							
						}
				}
				
			

		}
		
	}
	

};
