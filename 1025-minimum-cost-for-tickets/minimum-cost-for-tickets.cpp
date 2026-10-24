class Solution {
public:
    int solve(vector<int>& days, vector<int>& costs,int i,vector<int> &dp){
        int n = days.size();
        if(i >= n){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        
        int j = i;
        int x = costs[0]+solve(days,costs,i+1,dp);

        while(j < n && days[j] < days[i]+7){
            j++;
        }
        int y = costs[1]+solve(days,costs,j,dp);
        j = i;
        while(j < n && days[j] < days[i]+30){
            j++;
        }
        int z = costs[2]+solve(days,costs,j,dp);
    dp[i] =  min(min(x,y),z);
    return dp[i];

        
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int>dp(n,-1);

        return solve(days,costs,0,dp);
    }
};