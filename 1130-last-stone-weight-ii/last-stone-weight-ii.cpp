class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();

        int totalsum = 0;

        for(int i  = 0 ; i < n ; i++) totalsum += stones[i];

        vector<vector<bool>>dp(n+1,vector<bool>(totalsum+1));

        for(int i = 0 ; i <= n ; i++) dp[i][0] = true;

        for(int i = 1; i <= n ; i++){
            for(int sum = 1 ; sum <= totalsum ; sum++){
                bool notTake = dp[i-1][sum];
                bool take = false;

                if(stones[i-1] <= sum){
                    take = dp[i-1][sum-stones[i-1]];
                }
                dp[i][sum] = take || notTake;
            }
        }
        int mini = INT_MAX;

        for(int s1 = 0 ;s1<=totalsum/2; s1++){
            if(dp[n][s1]){
                int s2 = totalsum-s1;

                mini = min(mini,abs(s2-s1));
            }
        }
        return mini;
    }
};