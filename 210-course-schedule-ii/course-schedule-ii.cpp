class Solution {
public:
    bool dfs(int node , vector<int> &topo, vector<int>&vis,vector<vector<int>>& adj){
        vis[node] = 1;

        for(auto v : adj[node]){

            if(vis[v] == 1){
                    return true;
                }
            if(vis[v] == 0){
                if(dfs(v,topo,vis,adj)){
                    return true;
                }
                
                
            }
        }
        vis[node] = 2;
        topo.push_back(node);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>>adj(numCourses);
        for(int i = 0 ; i  < prerequisites.size(); i++){
           
                int u = prerequisites[i][0];
                int v = prerequisites[i][1];

                adj[v].push_back(u);
            
        }
        vector<int>vis(numCourses,0);
        vector<int>topo;

        for(int i = 0 ; i < numCourses ; i++){
            if(vis[i] == 0){
                if(dfs(i,topo,vis,adj)){
                    return {};
                }
            }
        }
        reverse(topo.begin(),topo.end());
        return topo;
    }
};