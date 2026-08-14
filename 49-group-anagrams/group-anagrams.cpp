class Solution {
public:
   
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>res;
        unordered_map<string,vector<string>>st;
        
        for(int i = 0 ; i < strs.size(); i++){
            string t=strs[i];

            sort(t.begin(),t.end());

            st[t].push_back(strs[i]);
           
        }

        for(auto i : st){
            res.push_back(i.second);
        }
        return res;
    }
};