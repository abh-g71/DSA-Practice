class Solution {
public:

    void dfs(int node, vector<vector<int>>& adj,vector<int> &vis){
        vis[node] = 1;

        for(auto neig : adj[node]){
            if(!vis[neig]){
                dfs(neig,adj,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int m = isConnected[0].size();
        vector<vector<int>>adj(n);

        for(int i = 0 ; i < n ; i++){
           for(int j = 0 ; j < m ; j++){
            if(isConnected[i][j] == 1){
                adj[i].push_back(j);
            }
           }
        }
        int count = 0;

           vector<int>vis(n,0);

           for(int i = 0 ; i < m ; i++){
            if(!vis[i]){
                count++;
                dfs(i,adj,vis);
                
            }
           }

        
        return count;
    }
};