class Solution {
	public:
	void sortColors(vector<int>& nums) {
		int start = 0, end = nums.size() - 1;
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] == 0) {
				swap(nums[start],nums[i]);
				++start;
			}
			else if (nums[i] == 2 && i < end) {
				swap(nums[end],nums[i]);
				--end;--i;
			}
		}
	}
};