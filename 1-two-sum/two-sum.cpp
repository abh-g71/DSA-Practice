class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int>mp;

        for(int i = 0 ; i < n ; i++){
           int d = target-nums[i];
           if(mp.find(d) != mp.end()){
            return {i,mp[d]};
           }
           mp[nums[i]] = i;
        }


        return {};

    }
};