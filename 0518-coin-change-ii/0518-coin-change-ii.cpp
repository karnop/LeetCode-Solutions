class Solution {
public:
    int helper(int i, int t, vector<int>& coins, vector<vector<int>> &dp) {
        if(i == 0) {
            if(t%coins[i] == 0) return 1;
            return 0;
        }
        if(t == 0) return 1;

        if(dp[i][t] != -1) return dp[i][t];
        int notTake = helper(i-1, t, coins, dp);
        int take = 0;
        if(t-coins[i] >= 0) take = helper(i, t-coins[i], coins, dp);

        return dp[i][t] = take + notTake; 
    }

    int change(int amount, vector<int>& coins) {
        int size = coins.size();
        vector<vector<int>> dp(size, vector<int>(amount+1, -1));

        long long int ans =  helper(size-1, amount, coins, dp);
        return ans;   
    }
};