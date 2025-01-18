class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = rows;
        vector<vector<int>> dist(rows, vector<int>(cols));
        vector<pair<int, int>> directions = {
            {1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
        };

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++) {
                dist[i][j] = 1e9;
            }
        }

        queue<pair<int, pair<int, int>>> q;
        if(grid[0][0] == 0) {
            dist[0][0] = 1;
            q.push({1, {0,0}});
        }

        while(!q.empty()) {
            int r = q.front().second.first;
            int c = q.front().second.second;
            int step = q.front().first;
            q.pop();

            for(auto dir : directions) {
                int delr = dir.first;
                int delc = dir.second;
                int nrow = r + delr;
                int ncol = c + delc;

                if(nrow >= 0 && ncol >= 0 && nrow < rows && ncol < cols && grid[nrow][ncol] == 0 
                && dist[nrow][ncol] > step+1) {
                    dist[nrow][ncol] = step+1;
                    q.push({step+1, {nrow, ncol}});
                }
            }
        }

        if(dist[rows-1][cols-1] == 1e9) return -1;
        return dist[rows-1][cols-1];

    }
};