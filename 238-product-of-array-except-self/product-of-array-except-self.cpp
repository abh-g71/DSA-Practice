class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int n = nums.size();
        int count = 0;
        vector<int>res(n,0);
        int mul = 1;
        for(int i = 0; i < n ; i++){
            if(nums[i] == 0){
                count++;
                continue;
            }
            mul *= nums[i];
        }
        if(count > 1){
            return res;
        }else if(count ==1){
            for(int i = 0; i < n ; i++){
                if(nums[i] == 0){
                    res[i] = mul;
                }else{
                    res[i] = 0;
                }
            }
        }
        else{
            for(int i = 0 ; i < n ; i++){
                res[i] = mul/nums[i];
            }
        }
        return res;
    }
};