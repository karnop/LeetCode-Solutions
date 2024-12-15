class Solution {
public:
    int helper(vector<int>& nums, int goal){
        if(goal < 0) return 0;
    int ans = 0;
    int sum = 0;
    int left = 0;
    for(int right = 0; right < nums.size(); right++)
    {
        sum += nums[right];

        while(sum > goal) {
            sum = sum-nums[left];
            left++;
        }

        if(sum <= goal) ans += right-left+1;
    }

    return ans;
}

int numSubarraysWithSum(vector<int>& nums, int goal) {
    return helper(nums, goal) - helper(nums, goal-1);
}
};