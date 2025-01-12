class Solution {
public:
    
    bool isBipartite(vector<vector<int>>& graph) {
        int nodes = graph.size();
        vector<int> color(nodes, -1);
    
        for(int i=0; i<graph.size(); i++) {
            if(color[i] == -1) {
                queue<pair<int, int>> q;
                q.push({i, 1});
                color[i] = 1;
                
                while(!q.empty()) {
                    int elem = q.front().first;
                    int clr = q.front().second;
                    q.pop();

                    for(auto neighbor : graph[elem]) {
                        if(color[neighbor] == -1) {
                            q.push({neighbor, 1-clr});
                            color[neighbor] = 1-clr;
                        }
                        else if(color[neighbor] != -1 && color[neighbor] == clr) return false;
                    }
                }
            }
        }
        return true;
    }
};