class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int>ans(n*n);
        int x = 0;
        for(int i =  0 ; i < n ; i++){
            for(int j= 0 ; j  < n ; j++){
                ans[x] = (grid[i][j]);
                x++;
            }
        }

        sort(ans.begin(),ans.end());
        int mis= n*n,twice = 0; 
        for(int i = 1 ; i < n*n ; i++){
            if( ans[i] == ans[i-1]){
                twice = ans[i];
            }
            else if(ans[i] != ans[i-1]+1){
                mis = ans[i-1]+1;
            }
        }
        if(ans[0] != 1) mis = 1;
        return {twice,mis};
    }
};