class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int>mp(26);

        for(int i = 0; i < order.size(); i++){
            mp[order[i]-'a'] = i;
        }

        
        for(int j = 0;j<words.size()-1;j++){
            string a = words[j];
            string b = words[j+1];

            int i = 0;
            for(; i < min(a.size(),b.size()); i++){
                if(a[i] != b[i]){
                    if(mp[a[i]-'a'] > mp[b[i]-'a']){
                        return false;
                        
                    }
                    break;
                }
            }
            if(i == min(a.size(),b.size()) && a.size() > b.size()){
                return false;
            }
        }
        return true;
    }
};