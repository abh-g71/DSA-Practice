class Solution {
public:
    bool solve(vector<int>& nums,int i ,int target,vector<vector<int>> &dp){
    if(target ==0){
        return true;
    }
    if(i < 0 ){
        return false;
    }
    if(dp[i][target] != -1){
        return dp[i][target];
    }
    bool pick=false;
    if(target-nums[i] >= 0)
     pick = solve(nums,i-1,target-nums[i],dp);

    bool notPick= solve(nums,i-1,target,dp);
    dp[i][target] = pick || notPick;
    return dp[i][target];
}
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0;i < n ; i++){
            sum += nums[i];
        }
        if(sum%2!=0){
            return false;
        }
        vector<vector<int>>dp(n+1,vector<int>(sum/2+1,-1));
        return solve(nums,n-1,sum/2,dp);
    }
};