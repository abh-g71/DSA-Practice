class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int ans = 0 ;
        for(auto i : sentences){
            ans = max(ans, (int)count(i.begin(),i.end(),' ')+1);
        }
        return ans;
    }
};