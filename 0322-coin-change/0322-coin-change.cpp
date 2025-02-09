class Solution {
public:
    int helper(int i, int t, vector<int>& coins, vector<vector<int>> &dp) {
        if(i == 0) {
            if(t%coins[i] == 0) return t/coins[i];
            return 1e9;
        }
        if(t == 0) return 0;
        if(t < 0) return 1e9;

        if(dp[i][t] != -1) return dp[i][t];
        return dp[i][t] = min(helper(i-1, t, coins, dp), 1 + helper(i, t-coins[i], coins, dp)); 
    }

    int coinChange(vector<int>& coins, int amount) {
        int size = coins.size();
        vector<vector<int>> dp(size, vector<int>(amount+1, -1));

        long long int ans =  helper(size-1, amount, coins, dp);
        if(ans == 1e9) return -1;
        return ans;
    }
};