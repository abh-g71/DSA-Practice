class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(),nums.end());
        int maxi = INT_MIN;
        int cnt = 1;
        if(n <= 1){
return n;
        }
        for(int i = 1 ;  i < n ; i++){
            if(nums[i] - nums[i-1] == 1){
                cnt++;
            }
            else if(nums[i] - nums[i-1] == 0) continue;
            else{
                maxi = max(cnt,maxi);
                cnt = 1;
            }
        }
        maxi = max(cnt,maxi);
        return maxi;
    }
};