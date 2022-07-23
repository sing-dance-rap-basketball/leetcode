/*
 * @lc app=leetcode id=866 lang=cpp
 *
 * [866] Prime Palindrome
 * 
 * Find the smallest prime palindrome greater than or equal to N.
 * Recall that a number is prime if it's only divisors are 1 and itself, and it is greater than 1. 
 * For example, 2,3,5,7,11 and 13 are primes.
 * Recall that a number is a palindrome if it reads the same from left to right as it does from right to left. 
 * For example, 12321 is a palindrome.
 * 
 */

// @lc code=start

/**
 * Accepted
    60/60 cases passed (1716 ms)
    Your runtime beats 5.16 % of cpp submissions
    Your memory usage beats 100 % of cpp submissions (6 MB)
 */
// class Solution {
// public:
//     int primePalindrome(int N) {
//         if (N <= 2) return 2;

//         int ans;
//         for (int i = N % 2 == 0 ? N + 1 : N; 
//                 i <= __INT_MAX__; i += 2) {
//             if (isPalindrome(i)) {
//                 if (isPrime(i)) {
//                     ans = i;
//                     break;
//                 }
//             }
//         }
//         return ans;
//     }

//     bool isPrime(int num) {
//         if (num <= 1) return false;
//         if (num == 2) return true;
//         if (num % 2 == 0) return false;

//         int root = int(sqrt(num));
//         for (int i = 3; i <= root; i += 2) {
//             if (num % i == 0) return false;
//         }
//         return true;
//     }

//     bool isPrime(int num, vector<int>& primeTable) {
//         int root = (int) sqrt(num);
//         for (int prime : primeTable) {
//             if (num % prime == 0) return false;
//             if (prime > root) break;
//         }
//         return true;
//     }

//     bool isPalindrome(int num) {
//         if (num < 0) return false;
//         int rev = 0;
//         int num_ = num;
//         while (num_ > 0) {
//             rev = rev * 10 + num_ % 10;
//             num_ /= 10;
//         }
//         return num == rev;
//     }
// };

/**
 * Accepted
    60/60 cases passed (156 ms)
    Your runtime beats 42.41 % of cpp submissions
    Your memory usage beats 100 % of cpp submissions (5.9 MB)
 */
class Solution {
public:
    int primePalindrome(int N) {
        if (8 <= N && N <= 11) return 11;
        for (int x = 1; x < 100000; ++x) {
            string s = to_string(x), r(s.rbegin(), s.rend());
            int y = stoi(s + r.substr(1));
            if (y >= N && isPrime(y)) return y;
        }
        return -1;
    }
    bool isPrime(int num) {
        if (num < 2 || num % 2 == 0) return num == 2;
        for (int i = 3; i * i <= num; i += 2)
            if (num % i == 0) return false;
        return true;
    }
};
// @lc code=end

