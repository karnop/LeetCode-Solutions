class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int originalColor = image[sr][sc];

        if(originalColor == color) return image;

        // directions fro moving up, down left, right
        vector<pair<int, int>> directions = {{-1, 0}, {1,0}, {0, -1}, {0, 1}};
        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;

        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();

            // check all 4 directions
            for(auto [dx, dy] : directions) {
                int nx = x + dx;
                int ny = y + dy;

                // constraints
                if(nx >= 0 && nx < m && ny >= 0 && ny < n && image[nx][ny] == originalColor){
                    image[nx][ny] = color;
                    q.push({nx, ny});
                }
            }
        } 
        return image;
    }
};