class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();

        string t;
        int l = 0; 
        int r= n-1;
        while(s[r]==' ' && r>0){
            r--;
        }
        
        string u;
        while( r>=0){
            if(s[r] == ' '){
                    r--;
                    continue;
                }
                u = "";
            while(r >= 0 && s[r] != ' '){
                u += s[r];
                r--;
            }
            reverse(u.begin(),u.end());
           if(!t.empty()){
            t += ' ';
           }
           t += u;
        }
        return t;
    }
};