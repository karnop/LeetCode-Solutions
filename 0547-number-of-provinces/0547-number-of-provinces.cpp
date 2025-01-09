class Solution {
public:
    vector<vector<int>> convertToAdjList(const vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adjList(n);

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(isConnected[i][j] == 1 && i != j) {
                    adjList[i].push_back(j);
                }
            }
        }
        return adjList;
    }

    // DFS 
    void dfs(int node, vector<bool> &visited, const vector<vector<int>> &adjList){
        visited[node] = true;
        for(int neighbor : adjList[node]){
            if(!visited[neighbor]) {
                dfs(neighbor, visited, adjList);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        // generating adjacency list
        vector<vector<int>> adjList = convertToAdjList(isConnected);
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int provinces = 0;

        // performing DFS for each unvisited node
        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                dfs(i, visited, adjList);
                provinces++;
            }
        }

        return provinces;
    }
};