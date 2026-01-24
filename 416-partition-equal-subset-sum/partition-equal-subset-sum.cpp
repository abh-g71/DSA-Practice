class Solution {
public:
    bool solveMem(int index,vector<int>& nums,int target,vector<vector<int>> &dp){
        int n = nums.size();
        if(index == n ){
            return false;
        }
        if(target < 0){
            return false;
        }
        if(target == 0){
            return true;
        }
        if(dp[index][target] != -1){
            return dp[index][target];
        }
        bool incl=solveMem(index+1,nums,target-nums[index],dp);
        bool excl=solveMem(index+1,nums,target-0,dp);

        // if(incl){
        //     dp[index][target] = incl;
        // }
        // if(excl){
        //     dp[index][target] = excl;
        // }
        return dp[index][target] =  incl or excl ;
    }
    bool canPartition(vector<int>& nums) {
        int total = 0 ;
        int n = nums.size();

        for(int i = 0 ; i < nums.size(); i++){
            total += nums[i];
        }

        if(total % 2 != 0){
            return false;
        }
        int target = total/2;
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return  solveMem(0,nums,target,dp);
    }
};