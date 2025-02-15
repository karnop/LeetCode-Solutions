class Solution {
public:
    int helper(int ind, int buy, vector<int>& prices, vector<vector<int>> &dp) {
        // note : in dp stock problems always move in forward direction not in reverse 
        if (ind >= prices.size()) {
            return 0;
        }
        if (dp[ind][buy] != -1) return dp[ind][buy];

        if (buy == 0) {
            return dp[ind][buy] = max(helper(ind+1, 1, prices, dp) - prices[ind], helper(ind+1, 0, prices, dp));
        } else {
            return dp[ind][buy] = max(helper(ind+2, 0, prices, dp) + prices[ind], helper(ind+1, 1, prices, dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        return helper(0, 0, prices, dp);
    }
};