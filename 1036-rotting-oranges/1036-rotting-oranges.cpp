class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int time = 0;
        int fresh = 0;

        // traversal
        queue<pair<int , int>> q;
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                }
                if(grid[i][j] == 1) fresh++;
            }
        }

        while(!q.empty() && fresh > 0) {
            time++;
            int n = q.size();

            for(int j=0; j<n; j++) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                int dx[] = {0, 0, 1, -1};
                int dy[] = {-1, 1, 0, 0};

                for(int i=0; i<4; i++) {
                    int r = x + dx[i];
                    int c = y + dy[i];
                    if(r >=0 && r < rows && c >= 0 && c < cols && grid[r][c] == 1) {
                        grid[r][c] = 2;
                        q.push({r, c});
                        fresh--;
                    } 
                }
            }
        }

        return fresh == 0 ? time : -1;
    }
};