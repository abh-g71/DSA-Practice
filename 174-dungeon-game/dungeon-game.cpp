class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m  = dungeon[0].size();

        vector<int>dp(m,INT_MAX);
        for(int i = n - 1; i >= 0 ; i--){
            for(int j = m -1; j >= 0 ; j--){
                if(i == n-1 && j == m-1){
                    dp[j] = max(1,1-dungeon[i][j]);

                }
                else{
                    int right = (j+1 < m ) ? dp[j+1] : INT_MAX;
                    int down = dp[j];

                    int need = min(right,down)-dungeon[i][j];
                    dp[j] = max(1,need);
                }
            }
        }
        return dp[0];
    }
};