class Solution {
public:
    map<pair<int,int>,int>dp;
    int  solve(vector<int>& nums, int target,int i){
        int n = nums.size();
        
        if(i==n && target==0){
            return 1;
        }
        if(i==n && target != 0){
            return 0;
        }
        auto key = make_pair(i,target);
        if(dp.count(key)){
            return dp[key];
        }
        int pickn = solve(nums,target-nums[i],i+1);
        int pickp = solve(nums,target+nums[i],i+1);
        return dp[key] = pickn + pickp;

        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
       
        dp.clear();
        
        
        return solve(nums,target,0);
    }
};