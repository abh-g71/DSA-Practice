class Solution {
public:
    bool bfs(int src, int dest,vector<vector<int>>& adj,int n){
        vector<bool>vis(n+1,false);
        queue<int>q;

        q.push(src);
        vis[src] = true;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            if(node == dest){
                return true;
            }

            for(auto nei : adj[node]){
                if(!vis[nei]){
                    vis[nei] = true;
                    q.push(nei);
                }
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>>adj(n+1);

        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];

            if(bfs(u,v,adj,n)){
                return edge;
            }

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return {};
    }
};