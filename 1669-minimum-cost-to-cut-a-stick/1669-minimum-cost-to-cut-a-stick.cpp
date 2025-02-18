class Solution {
public:
    int helper(int i, int j, vector<int>& cuts, vector<vector<int>> &dp) {
        if( i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int mini = INT_MAX;
        for(int k = i; k <= j; k++) {
            int cost = cuts[j+1] - cuts[i-1] + helper(i, k-1, cuts, dp) + helper(k+1, j, cuts, dp);
            mini = min(cost, mini);
        }
        return dp[i][j] = mini;
        
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        n = cuts.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
        return helper(1, n-2, cuts, dp);
    }
};