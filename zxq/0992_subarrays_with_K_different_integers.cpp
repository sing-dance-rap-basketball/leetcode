/**
 * 问题描述：
 * 992. Subarrays with K Different Integers
 * Given an array A of positive integers, call a (contiguous, not necessarily distinct) 
 * subarray of A good if the number of different integers in that subarray is exactly K.
 * (For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.)
 * Return the number of good subarrays of A.
 * 
 * Note:
 * 1 <= A.length <= 20000
 * 1 <= A[i] <= A.length
 * 1 <= K <= A.length
 */

/**
 * 提交结果：
 * Runtime: 108 ms, faster than 63.05% of C++ online submissions for Subarrays with K Different Integers.
 * Memory Usage: 18.4 MB, less than 69.28% of C++ online submissions for Subarrays with K Different Integers.
 */

int subarraysWithKDistinct(vector<int>& A, int K) {
    int num = 0;
    const int len = A.size();
    
    int start = 0, end = 0;
    int i = 0;      // 反正有用
    std::unordered_map<int, int> map;
    for (end = 0; end < len; ++end) {
        map[A[end]] = end;
        if (map.size() == K) { 
            ++num;
            for (i = start; i < end; ++i) {
                if (i < map[A[i]]) { ++num; }
                else { break; }
            }
        }
        else if (map.size() > K) {
            for (i = start; i < end; ++i) {
                if (i == map[A[i]]) { break; }
            }
            map.erase(A[i]);
            start = i + 1;
            ++num;
            for (i = start; i < end; ++i) {
                if (i < map[A[i]]) { ++num; }
                else { break; }
            }
        }
    }

    return num;
}

/**
 * 提交结果：
 * Runtime: 100 ms, faster than 65.71% of C++ online submissions for Subarrays with K Different Integers.
 * Memory Usage: 18.4 MB, less than 69.28% of C++ online submissions for Subarrays with K Different Integers.
 */

int subarraysWithKDistinct(vector<int>& A, int K) {
    int num = 0;
    const int len = A.size();
    
    int start = 0, end = 0;
    int i = 0;      // 反正有用
    std::unordered_map<int, int> map;
    for (end = 0; end < len; ++end) {
        map[A[end]] = end;
        if (map.size() == K) { 
            ++num;
            for (i = start; i < end; ++i) {
                if (i < map[A[i]]) { ++num; }
                else { break; }
            }
        }
        else if (map.size() > K) {
            map.erase(A[i]);
            start = i + 1;
            ++num;
            for (i = start; i < end; ++i) {
                if (i < map[A[i]]) { ++num; }
                else { break; }
            }
        }
    }

    return num;
}