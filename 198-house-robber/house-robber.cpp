class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 2){
            return max(nums[0],nums[1]);
        }
        if(n==1){
            return nums[0];
        }
        int prev1 = nums[0];
        int prev2 = 0;

        for(int i = 1; i < nums.size() ; i++){
            int curr = max(prev1,prev2+nums[i]);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};