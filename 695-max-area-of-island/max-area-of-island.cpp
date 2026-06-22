class Solution {
public:
    void dfs(int i , int j ,vector<vector<int>>& grid,int &count){
        int n = grid.size();
        int m = grid[0].size();
        if(i < 0 || j < 0 || i>=n || j>=m || grid[i][j] == 2 || grid[i][j] == 0){
            return ;
        }
        if(grid[i][j] ==1){
            count++;
        }
        grid[i][j] = 2;

        dfs(i+1,j,grid,count);
        dfs(i-1,j,grid,count);
        dfs(i,j+1,grid,count);
        dfs(i,j-1,grid,count);


    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxi = INT_MIN;
        int count = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] != 2){
                    if(grid[i][j] == 1){
                        dfs(i,j,grid,count);
                        maxi = max(count,maxi);
                        count = 0;
                    }
                }
                
            }
        }
        maxi = max(maxi,count);
        return maxi;
    }
};