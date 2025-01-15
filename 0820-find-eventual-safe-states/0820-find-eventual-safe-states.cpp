class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<vector<int>> adj(graph.size());
        vector<int> inDegree(graph.size(), 0);
        for(int i=0; i<graph.size(); i++) {
            for (auto it : graph[i]) {
                adj[it].push_back(i);
                inDegree[i]++;
            }
        }

        queue<int> q;
        for(int i=0; i<graph.size(); i++) {
            if(inDegree[i] == 0) q.push(i);
        }

        vector<int> topo;
        while(!q.empty()) {
            int front = q.front();
            q.pop();
            topo.push_back(front);

            for(auto it : adj[front]) {
                inDegree[it]--;
                if(inDegree[it] == 0) q.push(it);
            }
        }

        sort(topo.begin(), topo.end());
        return topo;
    }
};