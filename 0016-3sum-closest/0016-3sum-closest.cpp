class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int minAbsDiff = INT_MAX;
        int reqSum = 0;

        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int i=0; i<n-2; i++) {
            int j=i+1, k=n-1;
            while(j < k) {
                int sum = nums[i]+nums[j]+nums[k];
                if(sum == target) return sum;

                int absDiff = abs(target-sum);
                if(absDiff < minAbsDiff) {
                    minAbsDiff = absDiff;
                    reqSum = sum;
                }

                if(sum < target) j++;
                else k--;
            }
        }

        return reqSum;
    }
};