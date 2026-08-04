class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
       
        unordered_set<int>st;
        int small = INT_MAX;
        int maxi = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            st.insert(nums[i]);
            small = min(small,nums[i]);
            maxi = max(maxi,nums[i]);
        }
        
        vector<int>ans;

        for(int i = small + 1; i < maxi ; i++){
            if(st.find(i) == st.end()){
                ans.push_back(i);
            }
        }

        return ans;
    }
};