/**
 * 4. Median of Two Sorted Arrays
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 * You may assume nums1 and nums2 cannot be both empty.
 */
 
 
 /**
  * Runtime: 12 ms, faster than 99.10% of C++ online submissions for Median of Two Sorted Arrays.
  * Memory Usage: 9.4 MB, less than 96.89% of C++ online submissions for Median of Two Sorted Arrays.
  *
  * note: more like a C program
  */
 
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        int len =len1 + len2;
        int mid1 = len / 2, mid2 = len / 2 + 1;
        int count = 0, midValue1 = 0, midValue2 =0;
        int index1 = 0, index2 = 0;
        while(count < len + 1){
            int tmp = 0;
            
            if(index1 == len1 || index2 == len2){
                tmp = (index1 == len1)? nums2[index2++] : nums1[index1++];
            }
            else{
                if(nums1[index1] < nums2[index2]){
                    tmp = nums1[index1];
                    ++index1;  
                }
                else
                {
                    tmp = nums2[index2];
                    ++index2;                    
                }
            }
               
            ++count;           
            if(count == mid1)
                midValue1 = tmp;
            else if(count == mid2){
                midValue2 = tmp;
                break;
            }         
        }

        double ret = len%2 ? (double)midValue2 : (midValue1 + midValue2)/2.0;
        return ret;
    }
};