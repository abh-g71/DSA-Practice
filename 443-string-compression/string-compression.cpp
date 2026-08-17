class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();

        string s="";
        int count = 1;
        if(n==1) return 1;
        for(int i =  0; i < n-1 ; i++){
            if(chars[i] == chars[i+1]){
                count++;
            }else{
                s += chars[i];
                if(count > 1)
                  s += to_string(count);
                  
                count = 1;
            }
        }
        s += chars[n-1] ;
        if(count > 1)
                  s += to_string(count);
        //chars.erase();
         int m = s.size();
        for(int i = 0 ;i < m ; i++){
            chars[i] = s[i];
        }
       
        return m;
    }
};