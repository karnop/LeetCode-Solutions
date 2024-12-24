class Solution {
public:
    
    int findMin(vector<int>& nums) {
    int ans = 5001;

    int low = 0, high = nums.size()-1;
    while(low <= high) {
        int mid = low + (high-low)/2;
        
        //checking if left half is sorted
        if(nums[low] <= nums[mid]){
            ans = min(ans, nums[low]);
            low = mid+1;   
        }
        else {
            ans = min(ans, nums[mid]);
            high = mid-1;
        }
    }
    return ans;

} 
};