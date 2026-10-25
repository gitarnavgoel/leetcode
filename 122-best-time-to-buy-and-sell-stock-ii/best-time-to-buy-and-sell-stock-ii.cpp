
class Solution {
public:
    int solver(int i, int buy, vector<int>& arr,
               vector<vector<int>>& dp) {

        if (i == arr.size()) return 0;

        if (dp[i][buy] != -1) return dp[i][buy];

        if (buy) {
            int take = -arr[i] + solver(i + 1, 0, arr, dp);
            int skip = solver(i + 1, 1, arr, dp);

            return dp[i][buy] = max(take, skip);
        }

        int sell = arr[i] + solver(i + 1, 1, arr, dp);
        int skip = solver(i + 1, 0, arr, dp);

        return dp[i][buy] = max(sell, skip);
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));

        return solver(0, 1, prices, dp);
    }
};
