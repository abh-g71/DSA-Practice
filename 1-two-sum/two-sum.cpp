class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l  ;
         int n = nums.size();
         int r;
         for(int i = 0 ; i < n; i++){
            l = i;
            r = n-1;
         
            while( l < r){
                if(nums[l] + nums[r] == target){
                     return {l,r};
                }
                r--;
            }

         }
        return {};
    }
};