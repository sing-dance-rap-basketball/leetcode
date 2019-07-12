/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int length = nums1.size() + nums2.size();
		int *l = new int[length];
		unsigned i = 0;
		int flag=0;
		unsigned j = 0;
		int k = 1;
		
		if (nums1.empty()==false && nums2.empty()==false)
		{
			//cout << 2 << endl;
			l[0] = (nums1[0] <= nums2[0] ? nums1[0] : nums2[0]);
			
		}
		else
		if (nums1.empty())
		{
			l[0] = nums2[0];
		}
		else
			l[0] = nums1[0];
		if (nums2.empty()||(!nums1.empty()&&nums1[0] <= nums2[0]))
		{
			flag = 0; 
			i = 1;
		}
		else
		{
			flag = 1; 
			j = 1;
		}
		if (flag == 0)
		{
			while (i < nums1.size() || j < nums2.size())
			{
				if (i < nums1.size() && j < nums2.size())
				{
					if (nums2[j] >= l[k] && nums2[j] < nums1[i])
					{
						l[k] = nums2[j];
						j++;
						k++;
					}
					else
					{
						l[k] = nums1[i];
						i++;
						k++;
					}
				}
				else if (i >= nums1.size())
				{
					l[k] = nums2[j];
					j++;
					k++;
				}
				else if (j >= nums2.size())
				{
					l[k] = nums1[i];
					i++;
					k++;
				}
			}
            sort(l,l+length);
			for (int m = 0; m < length; m++)
				cout << l[m] << endl;
			if (length % 2 == 0)
				return (double(l[length / 2 - 1]) + (double)l[length / 2]) / 2;
			else
				return (double)l[(length-1) / 2];
		}
		else
		{
			while (i < nums1.size() || j < nums2.size())
			{
				if (i < nums1.size() && j < nums2.size())
				{
					if (nums1[i] >= l[k] && nums1[i] < nums2[j])
					{
						l[k] = nums1[i];
						i++;
						k++;
					}
					else
					{
						l[k] = nums2[j];
						j++;
						k++;
					}
				}
				else if (i >= nums1.size())
				{
					l[k] = nums2[j];
					j++;
					k++;
				}
				else if (j >= nums2.size())
				{
					l[k] = nums1[i];
					i++;
					k++;
				}
			}
             sort(l,l+length);
			for (int m = 0; m < length; m++)
				cout << l[m] << endl;
			if (length % 2 == 0)
				return (double(l[length / 2 - 1]) + (double)l[length / 2]) / 2;
			else
				return (double)l[length / 2];

		}
		
	}
	
};
