class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = -1, last = -1;

        // finding the first pos
        int st = 0, end = nums.size()-1;
        while(st <= end)
        {
            int mid = st + (end - st)/2;
            if(nums[mid] == target)
            {
                first = mid;
                end = mid-1;
            }
            if(nums[mid] > target)
            {
                end = mid-1;
            }
            if(nums[mid] < target)
            st = mid+1;
        }

        // finding the last pos
        st = 0, end = nums.size()-1;
        while(st <= end)
        {
            int mid = st + (end - st)/2;
            if(nums[mid] == target)
            {
                last = mid;
                st = mid+1;
            }
            if(nums[mid] > target)
            {
                end = mid-1;
            }
            if(nums[mid] < target)
            st = mid+1;
        }
        
        vector <int> v;
        v.push_back(first); v.push_back(last);
        return v;
    }
};