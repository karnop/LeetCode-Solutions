class Solution {
public:
    int findPeakElement(vector<int>& nums) {
    int size = nums.size()-1;

    if(nums.size() == 1) return 0;
    else if(nums[0] > nums[1]) return 0;
    else if(nums[size] > nums[size-1]) return size;

    int low = 1, high = size-1;
    while(low <= high){
        int mid = low + (high-low)/2;

        if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid;

        // on increasing slope
        if(nums[mid] > nums[mid-1]){
            low = mid+1;
        }

        // on decreasing slope
        else if(nums[mid] > nums[mid+1]){
            high = mid-1;
        }

        // on trough
        else high = mid-1;
    }
    return -1;
}

};