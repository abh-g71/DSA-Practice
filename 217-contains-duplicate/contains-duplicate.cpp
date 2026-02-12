class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(auto num : nums){
            freq[num]++;
        }
        for(auto num : freq){
            if(num.second >= 2){
                return true;
            }
        }
        return false;
    }
};