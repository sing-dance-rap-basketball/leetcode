/*
 * @lc app=leetcode id=689 lang=cpp
 *
 * [689] Maximum Sum of 3 Non-Overlapping Subarrays
 */

// // @lc code=start
// /*
//     Wrong Answer
//         34/42 cases passed (N/A)
//     Testcase
//         [17,9,3,2,7,10,20,1,13,4,5,16,4,1,17,6,4,19,8,3]
//         4
//     Answer
//         [4,8,14]
//     Expected Answer
//         [3,8,14]
//  */
// class Solution
// {
// public:
//     vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k)
//     {
//         vector<int> copy(nums);
//         int sum1, sum2, sum3;
//         int start1, start2, start3;
//         this->maxSumOfOneSubarray(copy, start1, sum1, k);
//         copy.erase(copy.begin() + start1, copy.begin() + start1 + k);
//         this->maxSumOfOneSubarray(copy, start2, sum2, k);
//         copy.erase(copy.begin() + start2, copy.begin() + start2 + k);
//         this->maxSumOfOneSubarray(copy, start3, sum3, k);
//         //copy.erase(copy.begin() + start3, copy.begin() + start3 + k);

//         // modify three start indices
//         if (start2 <= start1 - k)
//         {
//             std::swap(start1, start2);
//         }
//         else if (start2 < start1)
//         {
//             start1 = start2;
//             start2 = start1 + k;
//         }
//         else
//         { // start2 >= start1
//             start2 += k;
//         }
//         if (start3 <= start1 - k)
//         {
//             int temp = start2;
//             start2 = start1;
//             start1 = start3;
//             start3 = temp;
//         }
//         else if (start3 < start1)
//         {
//             int temp = start2;
//             start1 = start3;
//             start2 = start3 + k;
//             start3 = start2 + k <= temp ? temp : start2 + k;
//         }
//         else
//         {
//             start3 += k;
//             if (start3 <= start2 - k)
//             {
//                 std::swap(start3, start2);
//             }
//             else if (start3 < start2)
//             {
//                 start2 = start3;
//                 start3 = start2 + k;
//             }
//             else
//             {
//                 start3 += k;
//             }
//         }

//         return vector<int>{start1, start2, start3};
//     }

//     void maxSumOfOneSubarray(vector<int> &v, int &start, int &sum, int k)
//     {
//         int currSum = 0;
//         for (int i = 0; i < k; ++i)
//         {
//             currSum += v[i];
//         }
//         start = 0;
//         sum = currSum;

//         for (int i = k; i < v.size(); ++i)
//         {
//             currSum = currSum + v[i] - v[i - k];
//             if (currSum > sum)
//             {
//                 sum = currSum;
//                 start = i - k + 1;
//             }
//         }
//         return;
//     }
// };
// // @lc code=end

// @lc code=start
class Solution
{
public:
    vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k)
    {
    }
}
// @lc code=end
