class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        int ans = 0;
        int sum = 0;
        mp[0] = -1;

        for(int i = 0 ; i< n ; i++){
            if(nums[i] == 0){
                sum--;
            }else{
                sum++;
            }
            if(mp.count(sum)){
                ans = max(ans,i-mp[sum]);
            }else{
                mp[sum] = i;
            }
        }
        return ans;
    }
};