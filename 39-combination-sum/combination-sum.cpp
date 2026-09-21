class Solution {
public:
    vector<vector<int>>ans;
    void solve(int i,vector<int>& candidates, int target,vector<int> &lvl){
        int n = candidates.size();
        if(target == 0){
            ans.push_back(lvl);
            return;
        }
        if(i>=n || target < 0){
            return;
        }
       
        lvl.push_back(candidates[i]);
        solve(i,candidates,target-candidates[i],lvl);
        lvl.pop_back();
        solve(i+1,candidates,target,lvl);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<int>lvl;

        solve(0,candidates,target,lvl);
        return ans;   
    }
};