class Solution {
public:
    void dfs(int i , int j , vector<vector<int>>& heights,vector<vector<bool>> & vis){
         int n = heights.size();
        int m = heights[0].size();
        vis[i][j] = true;

        if(i+1 < n && heights[i+1][j] >= heights[i][j] && !vis[i+1][j]){
            dfs(i+1,j,heights,vis);
        }
        if(i-1  >= 0 && heights[i-1][j] >= heights[i][j] && !vis[i-1][j]){
            dfs(i-1,j,heights,vis);
        }
        if(j+1 < m && heights[i][j+1] >= heights[i][j] && !vis[i][j+1]){
            dfs(i,j+1,heights,vis);
        }
        if(j-1 >= 0 && heights[i][j-1] >= heights[i][j] && !vis[i][j-1]){
            dfs(i,j-1,heights,vis);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<bool>>pacific(n,vector<bool>(m,false));
        vector<vector<bool>>atlantic(n,vector<bool>(m,false));

        for(int i = 0 ; i < n ; i++){
            dfs(i,0,heights,pacific);
        }
        for(int i = 0 ; i < m ; i++){
            dfs(0,i,heights,pacific);
        }
        for(int i = 0 ; i < n ; i++){
            dfs(i,m-1,heights,atlantic);
        }
        for(int i = 0 ; i < m ; i++){
            dfs(n-1,i,heights,atlantic);
        }
        vector<vector<int>>ans;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(atlantic[i][j] && pacific[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};