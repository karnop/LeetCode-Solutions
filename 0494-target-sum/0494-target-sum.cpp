class Solution {
public:
    int helper(int i, int t, vector<int>& nums, unordered_map<int, unordered_map<int, long long int>> &dp) {
        if(i == 0) {
            if(t == 0 && nums[i] == 0) return 2;
            if(t == 0) return 1;
            return nums[i] == t;
        }
        if(t < 0) return 0;
        if (dp[i].count(t)) return dp[i][t];

        return dp[i][t] = helper(i-1, t, nums, dp) + helper(i-1, t-nums[i], nums, dp);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        long long int sum = accumulate(nums.begin(), nums.end(), 0ll);
        if ((sum - target) % 2 != 0) return 0;
        int t = (sum - target)/2;

        unordered_map<int, unordered_map<int, long long int>> dp;
        return helper(n-1, t, nums, dp);  
    }
};