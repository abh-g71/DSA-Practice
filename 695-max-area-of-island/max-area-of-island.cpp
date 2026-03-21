class Solution {
public:

    void solve(int i , int j , vector<vector<int>> &grid,int &count){
        int n = grid.size();
        int m = grid[0].size();
        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0 ){
            return ;
        } 
        grid[i][j] = 0;
        count++;
        solve(i+1,j,grid,count);
        solve(i-1,j,grid,count);
        solve(i,j+1,grid,count);
        solve(i,j-1,grid,count);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxi = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j =  0 ; j < m ; j++){
                int count = 0;
                if(grid[i][j] == 1){
                    solve(i,j,grid,count);
                    maxi = max(count,maxi);
                }
            }
        }
        return maxi;
    }
};