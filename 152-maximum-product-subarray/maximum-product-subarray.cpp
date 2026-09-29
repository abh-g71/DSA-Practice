class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        int maxProduct = nums[0];
        int currMax = nums[0];
        int currMin = nums[0];

        for(int i = 1; i < n ; i++){
             if(nums[i] < 0){
                swap(currMax,currMin);
             }
             currMax = max(nums[i],currMax*nums[i]);
             currMin = min(currMin*nums[i],nums[i]);

             maxProduct = max(currMax,maxProduct);
        }
        return maxProduct;
    }
};