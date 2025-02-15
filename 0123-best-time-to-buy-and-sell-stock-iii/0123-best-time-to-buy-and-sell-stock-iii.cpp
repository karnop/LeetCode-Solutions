class Solution {
public:
    int helper(int ind, int buy, int cap, vector<int>& prices, vector<vector<vector<int>>> &dp) {
        // note : in dp stock problems always move in forward direction not in reverse 
        if (ind == prices.size()) {
            return 0;
        }
        if(cap == 0) return 0;
        if (dp[ind][buy][cap] != -1) return dp[ind][buy][cap];

        if (buy == 0) {
            return dp[ind][buy][cap] = max(helper(ind+1, 1, cap, prices, dp) - prices[ind], helper(ind+1, 0, cap, prices, dp));
        } else {
            return dp[ind][buy][cap] = max(helper(ind+1, 0, cap-1, prices, dp) + prices[ind], helper(ind+1, 1, cap, prices, dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return helper(0, 0, 2, prices, dp);
    }
};