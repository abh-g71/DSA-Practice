class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,int>freq;

        for(int i = 0 ; i < n ; i++){
            freq[nums[i]]++;
        }
        int ans = INT_MIN;
        for(auto i : freq){
            ans = max(i.second,ans);
        }
        
        int res = 0 ;

        for(auto i : freq){
            if(i.second==ans){
                return i.first;
            }
        }
        return -1;
    }
};