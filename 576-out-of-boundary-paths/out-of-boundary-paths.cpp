class Solution {
public:
    const int MOD = 1e9 + 7;

    int f(int m, int n, int mov, int r, int c,
          vector<vector<vector<int>>>& dp) {

        if (r >= m || r < 0 || c >= n || c < 0)
            return 1;

        if (mov == 0)
            return 0;

        if (dp[r][c][mov] != -1)
            return dp[r][c][mov];

        int dx[4] = {+1, 0, -1, 0};
        int dy[4] = {0, -1, 0, +1};
        long long ans = 0;

        for (int i = 0; i < 4; i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];
            ans = (ans + f(m, n, mov - 1, nr, nc, dp)) % MOD;
        }

        return dp[r][c][mov] = ans;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
        return f(m, n, maxMove, startRow, startColumn, dp);
    }
};
