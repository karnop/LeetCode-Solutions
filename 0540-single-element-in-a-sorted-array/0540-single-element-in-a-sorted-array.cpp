class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
    int low = 0, high = nums.size()-1;

    while(low < high) {
        int mid = low + (high-low)/2;

        // even, odd index is a pair of same nos
        // mid is an odd index
        if(mid&1){
            if(nums[mid] == nums[mid-1]) low = mid+1;
            else high = mid-1;
        }

        // mid is an even index
        else {
            if(nums[mid] == nums[mid+1]) low = mid+2;
            else high = mid-1;
        }
    }

    return nums[low];
}
};