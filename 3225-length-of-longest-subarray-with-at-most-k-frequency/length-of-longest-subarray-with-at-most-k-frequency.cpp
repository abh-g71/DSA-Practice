class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();

        int left = 0;
        int right =0 ;

        unordered_map<int,int>freq;

        for(int i = 0 ; i < n ; i++){
            
            freq[nums[i]]++;
            while(freq[nums[i]] > k){
                freq[nums[left]]--;
                left++;
            }
            right = max(right,i-left+1);
        }
        return right;
    }
};