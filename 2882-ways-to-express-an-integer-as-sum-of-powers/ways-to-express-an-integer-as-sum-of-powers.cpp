class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long power(long long base, int exp) {
        long long result = 1;
        for (int i = 0; i < exp; i++) {
            result *= base;
        }
        return result;
    }

    long long f(long long n, long long x, long long sum, long long ele, vector<vector<long long>> &dp) {
        if (sum == n) return 1;
        if (sum > n) return 0;
        if (ele > n) return 0;
        if (dp[sum][ele] != -1) return dp[sum][ele];

        long long nott = f(n, x, sum, ele + 1, dp) % MOD;
        long long take = f(n, x, sum + pow(ele, x), ele + 1, dp) % MOD;

        return dp[sum][ele] = (take + nott) % MOD;
    }

    int numberOfWays(int n, int x) { 
        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, -1));
        return (int)f(n, x, 0, 1, dp);
    }
};
