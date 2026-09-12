class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>v;

        for(int i =  0 ; i < strs.size() ; i++){
            string s = strs[i];
            sort(s.begin(),s.end());
            v[s].push_back(strs[i]);
        }
        vector<vector<string>>ans;
        for(auto x : v){
            ans.push_back(x.second);
        }
        return ans;
    }
};