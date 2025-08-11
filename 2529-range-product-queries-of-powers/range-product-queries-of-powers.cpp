class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        const long long MOD = 1e9 + 7;
        vector<int> powers;

        // Extract powers of 2 from n
        for (int i = 0; i < 32; ++i) {
            if ((n >> i) & 1) {
                powers.push_back(1 << i);
            }
        }

        // Precompute prefix products
        vector<long long> prefix(powers.size() + 1, 1);
        for (int i = 0; i < powers.size(); ++i) {
            prefix[i + 1] = (prefix[i] * powers[i]) % MOD;
        }

        // Helper to compute modular inverse
        auto modInverse = [&](long long a) -> long long {
            long long res = 1, b = MOD - 2;
            while (b) {
                if (b & 1) res = (res * a) % MOD;
                a = (a * a) % MOD;
                b >>= 1;
            }
            return res;
        };

        // Process queries
        vector<int> ans;
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            long long prod = (prefix[r + 1] * modInverse(prefix[l])) % MOD;
            ans.push_back(prod);
        }

        return ans;
    }
};