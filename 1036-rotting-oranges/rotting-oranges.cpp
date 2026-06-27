class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

       
        queue<pair<int,int>>q;
        int fresh = 0;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j  < m ; j++){
                if(grid[i][j] == 1){
                    fresh++;
                }
               else if(grid[i][j] == 2){
                    
                    q.push({i,j});
                }
            }
        }
        if(fresh == 0){
            return 0;
        }
        int ans = 0;
        int dr[] = {0,0,1,-1};
        int dc[] = {-1,1,0,0};
        while(!q.empty() && fresh > 0){
            int size = q.size();
            
            while(size-- ){
                auto [x,y] = q.front();
                q.pop();

                for(int i = 0 ; i < 4 ; i++){
                    int nr = x + dr[i];
                    int nc = y + dc[i];

                    if(nc < m && nc >= 0 && nr < n && nr >= 0 && grid[nr][nc] == 1){
                        fresh--;
                        grid[nr][nc] = 2;
                        q.push({nr,nc});
                    }
                }
            }
            ans++;
            
        }
        if(fresh > 0 ){
            return -1;
        }
        return ans;
    }
};