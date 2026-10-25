class Solution {
public:
    bool solve(int i,int j,vector<vector<int>>& grid){
        int n = grid.size();

        int m = grid[0].size();

        if(i < 0 || j < 0 || i>= n || j >= m ){
            return false;
        }
        
        if(grid[i][j] == 1 || grid[i][j] == 2){
            return true;
        }
            grid[i][j] = 2;
        bool left = solve(i+1,j,grid);
        bool right = solve(i-1,j,grid);
        bool up = solve(i,j+1,grid);
        bool down =solve(i,j-1,grid) ;
        
        return left && right && up && down;
        
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();

        int m = grid[0].size();
        int count = 0;

        for(int i = 1 ; i < n-1 ; i++){
            for(int j =  1 ; j < m-1 ; j++){
                if(grid[i][j] == 0){
                    if(solve(i,j,grid)){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};