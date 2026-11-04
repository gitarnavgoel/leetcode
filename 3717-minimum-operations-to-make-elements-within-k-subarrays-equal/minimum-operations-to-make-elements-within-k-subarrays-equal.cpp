
class Solution {
public:
    class SlidingMedian {
    public:
        multiset<long long> low, high;
        long long sumLow = 0, sumHigh = 0;

        void balance() {
            while (low.size() > high.size() + 1) {
                auto it = prev(low.end());
                long long val = *it;
                low.erase(it);
                sumLow -= val;
                high.insert(val);
                sumHigh += val;
            }

            while (low.size() < high.size()) {
                auto it = high.begin();
                long long val = *it;
                high.erase(it);
                sumHigh -= val;
                low.insert(val);
                sumLow += val;
            }
        }

        void add(long long val) {
            if (low.empty() || val <= *low.rbegin()) {
                low.insert(val);
                sumLow += val;
            } else {
                high.insert(val);
                sumHigh += val;
            }
            balance();
        }

        void remove(long long val) {
            auto it = low.find(val);

            if (it != low.end()) {
                low.erase(it);
                sumLow -= val;
            } else {
                it = high.find(val);
                high.erase(it);
                sumHigh -= val;
            }
            balance();
        }

        long long getCost() {
            long long med = *low.rbegin();
            return med * low.size() - sumLow
                 + sumHigh - med * high.size();
        }
    };

    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        SlidingMedian sm;
        vector<long long> cost(n - x + 1);

        for (int i = 0; i < n; i++) {
            sm.add(nums[i]);

            if (i >= x) {
                sm.remove(nums[i - x]);
            }

            if (i >= x - 1) {
                cost[i - x + 1] = sm.getCost();
            }
        }

        const long long INF = 4e18;
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, INF));
        dp[0][0] = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                if (dp[i][j] == INF) continue;

                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);

                if (j < k && i + x <= n) {
                    dp[i + x][j + 1] = min(
                        dp[i + x][j + 1],
                        dp[i][j] + cost[i]
                    );
                }
            }
        }

        return dp[n][k];
    }
};
