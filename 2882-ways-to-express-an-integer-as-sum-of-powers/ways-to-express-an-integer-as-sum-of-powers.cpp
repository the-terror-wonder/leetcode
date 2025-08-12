class Solution {
public:
    const int MOD = 1e9 + 7;


    int solve(int n, int x, int sum, int last, vector<vector<int>> &dp) {
        if (sum == n) return 1;
        if (dp[sum][last] != -1) return dp[sum][last];

        long long ways = 0;
        int next = last + 1;
        while(true) {
            long long num = pow(next, x);
            if (sum + num > n) break;
            ways = (ways + solve(n, x, sum + num, next, dp)) % MOD;
            next++;
        }

        return dp[sum][last] = ways;
    }

    int numberOfWays(int n, int x) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(n, x, 0, 0, dp);
    }
};

