/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 */

// @lc code=start

/**
 * Time Limit Exceeded
 * Testcase: 499979
 */
// class Solution {
// public:
//     int countPrimes(int n) {
//         if (n <= 2) {
//             return 0;
//         }

//         vector<int> primes {2};
//         for (int num = 3; num < n; ++num) {
//             bool isPrime = true;
//             for (int prime : primes) {
//                 if (num % prime == 0) {
//                     isPrime = false;
//                     break;
//                 }
//             }
//             if (isPrime) {
//                 primes.push_back(num);
//             }
//         }

//         return primes.size();
//     }
// };

/**
 * Accepted
 *  20/20 cases passed (372 ms)
 *  Your runtime beats 17.68 % of cpp submissions
 *  Your memory usage beats 20.83 % of cpp submissions (9 MB)
 */
// class Solution {
// public:
//     int countPrimes(int n) {
//         if (n <= 2) {
//             return 0;
//         }

//         vector<int> primes {2};
//         for (int num = 3; num < n; num += 2) {
//             bool isPrime = true;
//             int root = (int) sqrt(num);
//             for (int i = 1; i < primes.size() && primes[i] <= root; ++i) {
//                 if (num % primes[i] == 0) {
//                     isPrime = false;
//                     break;
//                 }
//             }
//             if (isPrime) {
//                 primes.push_back(num);
//             }
//         }

//         return primes.size();
//     }
// };

/**
 * Accepted
    20/20 cases passed (192 ms)
    Your runtime beats 27.81 % of cpp submissions
    Your memory usage beats 100 % of cpp submissions (6.5 MB)
 */
// class Solution {
// public:
//     int countPrimes(int n) {
//         if (n <= 2) {
//             return 0;
//         }

//         vector<bool> isPrime(n, true);
//         isPrime[0] = false;
//         isPrime[1] = false;

//         int ans = 0;
//         for (int i = 2; i < n; ++i) {   
//             if (isPrime[i] == true) {
//                 ++ans;
//                 for (int j = (n-1) / i; j > 1; --j) {
//                     isPrime[i * j] = false;
//                 }
//             }
//         }
        
//         return ans;
//     }
// };

/**
 * Accepted
    20/20 cases passed (160 ms)
    Your runtime beats 35.33 % of cpp submissions
    Your memory usage beats 100 % of cpp submissions (6.5 MB)
 */
// class Solution {
// public:
//     int countPrimes(int n) {
//         if (n <= 2) {
//             return 0;
//         }

//         vector<bool> isPrime(n, true);
//         isPrime[0] = false;
//         isPrime[1] = false;

//         int ans = 0;
//         int root = (int) sqrt(n);
//         for (int i = 2; i <= root; ++i) {   
//             if (isPrime[i]) {
//                 ++ans;
//                 for (int j = (n-1) / i; j > 1; --j) {
//                     isPrime[i * j] = false;
//                 }
//             }
//         }

//         for (int i = root + 1; i < n; ++i) {
//             if (isPrime[i]) {
//                 ++ans;
//             }
//         }
        
//         return ans;
//     }
// };

/**
 * Accepted
    20/20 cases passed (156 ms)
    Your runtime beats 36.8 % of cpp submissions
    Your memory usage beats 100 % of cpp submissions (6.5 MB)
 */
// class Solution {
// public:
//     int countPrimes(int n) {
//         if (n <= 2) {
//             return 0;
//         }

//         vector<bool> isPrime(n, true);
//         isPrime[0] = false;
//         isPrime[1] = false;

//         int ans = 0;
//         int root = (int) sqrt(n);
//         for (int i = 2; i <= root; ++i) {   
//             if (isPrime[i]) {
//                 ++ans;
//                 for (int j = (n-1) / i; j >= i; --j) { // 比 i 小的不需要考虑
//                     isPrime[i * j] = false;
//                 }
//             }
//         }

//         for (int i = root + 1; i < n; ++i) {
//             if (isPrime[i]) {
//                 ++ans;
//             }
//         }
        
//         return ans;
//     }
// };

/**
 * Accepted
    20/20 cases passed (68 ms)
    Your runtime beats 59.33 % of cpp submissions
    Your memory usage beats 100 % of cpp submissions (6.5 MB)
 */
class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) {
            return 0;
        }

        vector<bool> isPrime(n, true);

        // ans 的初始值代表小于 n 且大于 1 的奇数数量，再把偶素数 2 统计进去
        int ans = n / 2;
        int root = (int) sqrt(n);
        for (int i = 3; i <= root; i += 2) {   
            if (isPrime[i]) {
                for (int j = i * i; j < n; j += i * 2) {
                    if (isPrime[j]) {
                        --ans;
                        isPrime[j] = false;
                    }
                }
            }
        }

        return ans;
    }
};

// @lc code=end

