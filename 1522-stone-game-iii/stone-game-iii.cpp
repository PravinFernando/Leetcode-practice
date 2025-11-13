class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(4, 0);

        for (int i = n - 1; i >= 0; --i) {
            int total = 0;
            dp[i % 4] = INT_MIN;
            for (int j = i; j < min(i + 3, n); ++j) {
                total += stoneValue[j];
                dp[i % 4] = max(dp[i % 4], total - dp[(j + 1) % 4]);
            }
        }

        if (dp[0] == 0) return "Tie";
        return dp[0] > 0 ? "Alice" : "Bob";
    }
};