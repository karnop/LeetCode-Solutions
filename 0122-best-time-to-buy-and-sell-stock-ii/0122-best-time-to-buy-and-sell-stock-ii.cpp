class Solution {
public:
    int helper(int ind, int buy, vector<int>& prices, vector<vector<int>> &dp) {
        // note : in dp stock problems always move in forward direction not in reverse 
        if (ind == prices.size()) {
            return 0;
        }
        if (dp[ind][buy] != -1) return dp[ind][buy];

        if (buy == 0) {
            return dp[ind][buy] = max(helper(ind+1, 1, prices, dp) - prices[ind], helper(ind+1, 0, prices, dp));
        } else {
            return dp[ind][buy] = max(helper(ind+1, 0, prices, dp) + prices[ind], helper(ind+1, 1, prices, dp));
        }
    }

    int helperTabulation(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        int ind = n;
        dp[ind][0] = 0;
        dp[ind][1] = 0;

        for(ind = n-1; ind>=0; ind--) {
            for(int buy = 1; buy >= 0; buy--) {
                if (buy == 0) {
                    dp[ind][buy] = max(dp[ind+1][1] - prices[ind], dp[ind+1][0]);
                } else {
                    dp[ind][buy] = max(dp[ind+1][0] + prices[ind], dp[ind+1][1]);
                }
            }
        }

        return dp[0][0];
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        return helper(0, 0, prices, dp);  // Start with not holding stock
        // return helperTabulation(prices);
    }
};
