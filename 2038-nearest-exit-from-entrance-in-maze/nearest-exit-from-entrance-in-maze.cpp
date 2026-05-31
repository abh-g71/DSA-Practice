class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();

        queue<pair<int,int>>q;

        q.push({entrance[0],entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';

        
        int count = 0;
        while(!q.empty()){
            int size = q.size();
            

            for(int i = 0 ; i < size ; i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                if((x==0 || y == 0 || x == n-1 || y== m-1 ) && (x!=entrance[0] || y != entrance[1])){
                    return count;
                }
                
                if(x+1 < n && maze[x+1][y] == '.' ){
                    q.push({x+1,y});
                    maze[x+1][y] = '+';
                }
                if(x-1 >= 0 && maze[x-1][y] == '.' ){
                    q.push({x-1,y});
                    maze[x-1][y] = '+';
                }
                if(y+1 < m && maze[x][y+1] == '.' ){
                    q.push({x,y+1});
                    maze[x][y+1] = '+';
                }
                if(y-1 >= 0 && maze[x][y-1] == '.' ){
                    q.push({x,y-1});
                    maze[x][y-1] = '+';
                }
                
            }
            count++;

        }
        return -1;
    }
};