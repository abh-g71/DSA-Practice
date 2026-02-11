class Solution {
public:
    int solve(vector<int>& nums,int start,int end){
        int n = nums.size();
        int prev1 = 0;
        int prev2 = 0;

        for(int i = start ; i <= end ; i++){
            int incl = nums[i] + prev2;
            int excl = prev1;
            int ans  = max(incl,excl);
            prev2 = prev1;
            prev1 = ans;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        if( n == 1){
            return nums[0];
        }
        int case1 = solve(nums,0,n-2);
        int case2 = solve(nums,1,n-1);

        return max(case1,case2);
    }
};