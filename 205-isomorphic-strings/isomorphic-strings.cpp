class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        int m = t.size();

        if(n!=m) return false;

        vector<int>mp1(256,-1) ,mp2(256,-1);

        for(int i = 0 ;i < n ;i++){
            if(mp1[s[i]] != mp2[t[i]]) return false;
              mp1[s[i]] = mp2[t[i]]=i;
            
        }
        return true;
    }
};