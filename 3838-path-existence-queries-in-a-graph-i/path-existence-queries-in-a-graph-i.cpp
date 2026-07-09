class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int>c(n);
        int id = 0;

        for(int i = 1; i  < n ; i++){
            if(nums[i] - nums[i-1] > maxDiff){
                id++;
            }
            c[i] = id;
        }

        vector<bool>ans;
        for(auto &q : queries){
            ans.push_back(c[q[0]] == c[q[1]]);
        }
        return ans;
    }
};