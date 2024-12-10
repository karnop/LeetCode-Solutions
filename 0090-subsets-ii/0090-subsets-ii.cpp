class Solution {
public:
void helper(int ind, vector<int>&temp, vector<int> arr, set<vector<int>>&ans)
{
    if(ind == arr.size())
    {
        vector<int> temp2 = temp;
        sort(temp2.begin(), temp2.end());
        ans.insert(temp2);
        return;
    }

    temp.push_back(arr[ind]);
    helper(ind+1, temp, arr, ans);
    temp.pop_back();
    helper(ind+1, temp, arr, ans);
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    set<vector<int>> ans;
    vector<int> temp;
    helper(0, temp, nums, ans);
    vector<vector<int>> v(ans.begin(), ans.end());
    return v;
}


};