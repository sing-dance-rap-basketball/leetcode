/**
 * 45. Jump Game II
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.
 * Each element in the array represents your maximum jump length at that position.
 * Your goal is to reach the last index in the minimum number of jumps.
 */

/**
 * Runtime: 12 ms, faster than 75.87% of C++ online submissions for Jump Game II.
 * Memory Usage: 31.2 MB, less than 5.09% of C++ online submissions for Jump Game II.
 * BFS 为了不超时肆意的废内存……
 */

class Solution {
public:
    int jump(vector<int>& nums) {
        deque<int> bfs_queue{0};
        vector<bool> check(nums.size(),0);
        if (nums.size() == 1)
            return 0;
        else
            return BFS(nums, bfs_queue, check);
    }
    
    int BFS(vector<int>& nums, deque<int> &bfs_queue, vector<bool> &check) {
        int size = bfs_queue.size();
        int end = nums.size() - 1;
        for (int i = 0; i < size; ++i) {
            int index = bfs_queue.back();
		
            for(int j = nums[index]; j > 0; --j) {
                
				if (index + j > end || check[index + j] == 1)
					continue;
				
                //cout << index + j << " " << end << endl;
                
                if (index + j == end)
                    return 1;
				
                bfs_queue.push_front(index + j);
				check[index + j] = 1;
            }
            bfs_queue.pop_back();
        }
        return BFS(nums, bfs_queue, check) + 1;
    }
};