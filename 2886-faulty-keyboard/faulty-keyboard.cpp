class Solution {
public:
    string finalString(string s) {
        int n = s.size();
        string t = "";
        for(int i = 0 ;i < n ; i++){
            if(s[i] == 'i'){
                reverse(t.begin(),t.end());
            }else
            t += s[i];
        }
        return t;
    }
};