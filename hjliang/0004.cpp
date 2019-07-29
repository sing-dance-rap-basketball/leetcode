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


/**
 * Runtime: 16 ms, faster than 91.58% of C++ online submissions for Median of Two Sorted Arrays.
 * Memory Usage: 9.6 MB, less than 75.25% of C++ online submissions for Median of Two Sorted Arrays.
 * O(log(min(m,n)))     看公众号看到的……  https://mp.weixin.qq.com/s/OE4lHO8-jOIxIfWO_1oNpQ
 */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> *pnums1 = &nums1;
        vector<int> *pnums2 = &nums2;
        
        int m = nums1.size(), n = nums2.size();
        if (m > n) {
            swap(m,n);
            pnums1 = &nums2;
            pnums2 = &nums1;  
        }
        
        int start = 0, end = m;
        while (start <= end) {
            int i = (start + end) / 2;
            int j = (m + n + 1)/2 - i;
            if (i < end && (*pnums1)[i] < (*pnums2)[j - 1]) 
                start = i + 1;
            else if (i > start && (*pnums1)[i - 1] > (*pnums2)[j]) 
                end = i - 1;
            else {
                int leftNum;
                if(i == 0) {
                    leftNum = (*pnums2)[j-1];
                }
                else if (j == 0) {
                    leftNum = (*pnums1)[i-1];
                }
                else {
                    leftNum = max((*pnums1)[i-1],(*pnums2)[j-1]);
                }
                
                if ((m + n)%2 != 0) {
                    return leftNum;
                }
                else {
                    int rightNum;
                    if (i == m)
                        rightNum = (*pnums2)[j];
                    else if (j == n)
                        rightNum = (*pnums1)[i];
                    else
                        rightNum = min((*pnums1)[i],(*pnums2)[j]);
                        
                    return (leftNum + rightNum) / 2.0;
                }
            }
        }
        return 0.0;
    }
};