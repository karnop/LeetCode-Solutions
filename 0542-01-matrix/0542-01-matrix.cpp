class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        vector<vector<int>> vis(rows, vector<int>(cols, 0));
        queue<pair<pair<int, int>, int>> q;

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(mat[i][j] == 0) {
                    q.push({{i, j}, 1});
                    vis[i][j] = 1;
                }
            }
        }

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();

            int delrow[] = {-1, 0, +1, 0};
            int delcol[] = {0, +1, 0, -1};

            for(int i=0; i<4; i++){
                int nrow = r+delrow[i];
                int ncol = c+delcol[i];

                if(nrow >= 0 && nrow < rows && ncol >= 0 && ncol < cols && vis[nrow][ncol] == 0 && mat[nrow][ncol] != 0) {
                    q.push({{nrow, ncol}, t+1});
                    mat[nrow][ncol] = t;
                    vis[nrow][ncol] = 1;
                }
            }

        }
        return mat;
    }
};