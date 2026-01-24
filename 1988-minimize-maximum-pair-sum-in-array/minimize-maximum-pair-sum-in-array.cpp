class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxi = INT_MIN;
        int n =  nums.size();
        int left = 0;
        int right  = n-1;
        while(left < right){
            maxi = max(maxi,(nums[left]+nums[right]));
            left++;
            right--;
        }
        return maxi;
    }
};