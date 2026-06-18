class Solution {
public:

    bool dfs(int src,int dest, vector<vector<int>> &adj,vector<int>& vis){
        if(src == dest){
            return true;
        }
        vis[src] = 1;

        for(auto v : adj[src]){
            if(!vis[v]){
                if(
                dfs(v,dest,adj,vis)){
                    return true;
                }
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);
        
        for(int i = 0 ;  i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[v].push_back(u);
            adj[u].push_back(v);
        }
        vector<int>vis(n,0);
        

        return dfs(source,destination,adj,vis);
    }
};