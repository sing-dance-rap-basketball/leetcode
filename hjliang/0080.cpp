class Solution {
	public:
	int removeDuplicates(vector<int>& nums) {
		int count = 1;
		int size = nums.size();
		if (size < 3)
			return size;
		int preEle = nums[0];
		for (int i = 1; i < nums.size(); ++i) {
			if (preEle == nums[i])
				++count;
			else {
				preEle = nums[i];
				count = 1;
			}
			if (count > 2) {
				nums[i] = nums[nums.size()-1];
				--size;
			}
		}
		sort(nums.begin(),nums.end());
		for (int i = 0; i < nums.size(); i++) cout << nums[i];
		return size;
	}
};