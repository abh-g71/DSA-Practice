class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        const int  MOD = 1e9 + 7; 

        vector<vector<long long>>mini(n,vector<long long>(m));
        vector<vector<long long>>maxi(n,vector<long long>(m));

        mini[0][0] = maxi[0][0]=grid[0][0];

        for(int j = 1; j < m ; j++){
            mini[0][j] = maxi[0][j] = maxi[0][j-1] *grid[0][j];
        }
        for(int i = 1; i < n ; i++){
            mini[i][0] = maxi[i][0] = maxi[i-1][0] *grid[i][0];
        }

        for(int i = 1 ; i < n ; i++){
            for(int j = 1; j < m ; j++){
                long long val  = grid[i][j];

                long long a = maxi[i-1][j]*val;
                long long b = mini[i-1][j]*val;
                long long c = maxi[i][j-1]*val;
                long long d = mini[i][j-1]*val;

                mini[i][j] = min({a,b,c,d});
                maxi[i][j] = max({a,b,c,d});
            }
        }
        long long ans = maxi[n-1][m-1];

        return ans < 0 ? -1 : ans % MOD;
    }
};