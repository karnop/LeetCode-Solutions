class Solution {
public:
    int area(int i, int j, vector<int>& height) {
        return (j-i) * min(height[i], height[j]);
    }
    int maxArea(vector<int>& height) {
        int n = height.size()-1;
        int i = 0, j = n;
        int ans = 0;
        while(i < j) {
            ans = max(ans, area(i, j, height));
            if(height[i] < height[j]) i++;
            else j--;
        }

        return ans;
    }
};