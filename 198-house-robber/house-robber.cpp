class Solution {
public:
    
    int rob(vector<int>& nums) {
        int n = nums.size();
       if(n == 1){
        return nums[0];
       } 

       int prev1 = 0;
       int prev2 = nums[0];

       for(int i = 1; i < n ; i++){
        int incl = nums[i] + prev1;
        int excl = prev2;
        int ans = max(incl,excl);
        prev1 = prev2;
        prev2 = ans;
       }
       return prev2;
    }
};