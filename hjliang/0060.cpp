/**
 * 60. Permutation Sequence
 * The set [1,2,3,...,n] contains a total of n! unique permutations.
 * By listing and labeling all of the permutations in order, we get the following sequence for n = 3:
 */

/**
 * Runtime: 4 ms, faster than 71.60% of C++ online submissions for Permutation Sequence.
 * Memory Usage: 8.2 MB, less than 76.60% of C++ online submissions for Permutation Sequence.
 * 找规律??
 */

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums(n);
        string ret;
        --k;
        for (int i = 0; i < n; ++i)
            nums[i] = i + 1;
        
        for (int i = 0; i < n; ++i) {
            int fact = 1,nTmp = n - 1 - i;
            while(nTmp > 1)
                fact *= nTmp--;
            
            int index = k / fact;
            k %= fact;
            ret += ('0' + nums[index]);
            nums.erase(nums.begin()+index);

        }
        return ret;
    }
};