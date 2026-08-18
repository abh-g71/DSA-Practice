class Solution {
public:
    void solve(int index,vector<int>& candidates, int target,vector<int> &ans,vector<vector<int>> &res){
        int n = candidates.size();
        if( target  == 0){
             res.push_back(ans);
            return;
        }
        if( target < 0 || index >= n){
            return;
        }
            ans.push_back(candidates[index]);
        
        
        solve(index,candidates,target-candidates[index],ans,res);
        ans.pop_back();
        solve(index+1,candidates,target,ans,res);

       
    
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        int n = candidates.size();
        vector<vector<int>>res;
        vector<int>ans;

        
            
            solve(0,candidates,target,ans,res);
           
        return res;
    }
};