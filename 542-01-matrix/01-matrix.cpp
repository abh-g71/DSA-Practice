class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>>dist(n,vector<int>(m,-1));
        queue<pair<int,int>>q;

        for(int i = 0 ; i  <n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                    dist[i][j] = 0;
                }
            }
        }

        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();

             if(x + 1 < n && dist[x + 1][y] == -1) {
                dist[x + 1][y] = dist[x][y] + 1;
                q.push({x + 1, y});
            }

            // Up
            if(x - 1 >= 0 && dist[x - 1][y] == -1) {
                dist[x - 1][y] = dist[x][y] + 1;
                q.push({x - 1, y});
            }

            // Right
            if(y + 1 < m && dist[x][y + 1] == -1) {
                dist[x][y + 1] = dist[x][y] + 1;
                q.push({x, y + 1});
            }

            // Left
            if(y - 1 >= 0 && dist[x][y - 1] == -1) {
                dist[x][y - 1] = dist[x][y] + 1;
                q.push({x, y - 1});
            }


        }
        return dist;
    }
};