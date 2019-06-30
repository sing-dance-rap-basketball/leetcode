/**
 * 1. Two Sum
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i, j, complement;
    int* result = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;
    
    if(result != NULL){
        for(i = 0; i < numsSize; ++i){
            complement = target - nums[i];
            for(j = i+1; j < numsSize; ++j){
                if(nums[j] == complement){
                    result[0] = i;
                    result[1] = j;
                    return result;
                }
            }
        }
    }

    return result;
}