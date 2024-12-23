class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ans = -1;

        int start = 0, end = nums.size()-1;
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            if(nums[mid] == target)
            {
                ans = mid;
                break;
            }

            else if(nums[mid] > target)  end = mid-1;
            else if(nums[mid] < target)  start = mid+1;
        }

        return ans;
    }
};