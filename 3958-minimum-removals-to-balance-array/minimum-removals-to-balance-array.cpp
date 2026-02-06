class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==1){
            return 0;
        }
        int maxlen = 1;
        int j = 0 ;
        sort(nums.begin(),nums.end());
        for(int i = 0 ; i < n ; i++){
            while(j < n && nums[j] <= (long long)k*nums[i]){
                j++;
            }
            maxlen = max(maxlen,j-i);
        }
        return n-maxlen;
    }
};