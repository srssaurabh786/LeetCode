
class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {

        vector<int> dp(n + 1, INT_MAX);

        dp[0] = 0;

        for (int i = 1; i <= n; i++) {

            int cost = costs[i - 1];

            for (int j = 1; j <= 3; j++) {

                if (i - j >= 0) {

                    dp[i] = min(
                        dp[i],
                        dp[i - j] + cost + j * j
                    );

                }
            }
        }

        return dp[n];
    }
};
