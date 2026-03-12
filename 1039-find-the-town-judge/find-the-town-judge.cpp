class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>indeg(n+1,0) , outdeg(n+1,0);

        for(auto &trusts : trust){
            indeg[trusts[1]]++;
            outdeg[trusts[0]]++;
        }

        for(int i = 1; i <= n ; i++){
            if(outdeg[i] == 0 && indeg[i] == n-1){
                return i;
            }
        }
        return -1;
        
    }
};