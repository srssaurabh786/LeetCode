
class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        vector<long long> cost(n - x + 1);

        multiset<int> left, right;
        long long leftSum = 0, rightSum = 0;

        // Maintain sliding window of size x
        for (int i = 0; i < n; i++) {
            int val = nums[i];

            if (left.empty() || val <= *left.rbegin()) {
                left.insert(val);
                leftSum += val;
            } else {
                right.insert(val);
                rightSum += val;
            }

            // Remove element outside the window
            if (i >= x) {
                int out = nums[i - x];

                auto it = left.find(out);

                if (it != left.end()) {
                    left.erase(it);
                    leftSum -= out;
                } else {
                    right.erase(right.find(out));
                    rightSum -= out;
                }
            }

            // Balance the two sets
            while (left.size() < right.size()) {
                int v = *right.begin();

                right.erase(right.begin());
                rightSum -= v;

                left.insert(v);
                leftSum += v;
            }

            while (left.size() > right.size() + 1) {
                int v = *left.rbegin();

                left.erase(prev(left.end()));
                leftSum -= v;

                right.insert(v);
                rightSum += v;
            }

            // Calculate cost for each window
            if (i >= x - 1) {
                int median = *left.rbegin();

                long long operations =
                    1LL * median * left.size() - leftSum
                    + rightSum - 1LL * median * right.size();

                cost[i - x + 1] = operations;
            }
        }

        // DP
        const long long INF = 1e18;

        vector<long long> prevDP(n + 1, 0);
        vector<long long> currDP(n + 1, INF);

        for (int j = 1; j <= k; j++) {
            fill(currDP.begin(), currDP.end(), INF);

            for (int i = n - 1; i >= 0; i--) {
                // Skip current position
                currDP[i] = currDP[i + 1];

                // Select a window starting at i
                if (i + x <= n) {
                    currDP[i] = min(
                        currDP[i],
                        cost[i] + prevDP[i + x]
                    );
                }
            }

            prevDP.swap(currDP);
        }

        return prevDP[0];
    }
};
