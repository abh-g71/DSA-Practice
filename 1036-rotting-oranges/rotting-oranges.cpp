class Solution {
public:

    
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        queue<pair<int,int>>q;
        int fresh = 0;
        

        for(int i = 0 ; i < n ; i++){
            for(int j = 0; j < m ; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                    
                }
                if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }


        while(!q.empty() && fresh > 0){
            int size = q.size();
            
            

            for(int i = 0 ;  i < size ; i++){
                int x = q.front().first;
            int y = q.front().second;
            q.pop();
                if(y+1 < m && grid[x][y+1] == 1){
                    grid[x][y+1] = 2;
                    fresh--;
                    q.push({x,y+1});
                }
                if(y-1 >= 0 && grid[x][y-1] == 1){
                    grid[x][y-1] = 2;
                    fresh--;
                    q.push({x,y-1});
                }
                if(x+1 < n && grid[x+1][y] == 1){
                    grid[x+1][y] = 2;
                    fresh--;
                    q.push({x+1,y});
                }
                if(x-1 >= 0 && grid[x-1][y] == 1){
                    grid[x-1][y] = 2;
                    fresh--;
                    q.push({x-1,y});
                }
            }
            count++;
        }

        if(fresh > 0){
            return -1;
        }
        return count;
        
    }
};