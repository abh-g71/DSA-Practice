class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size() > k){
            string t="";
            for(int i = 0 ; i < s.size(); i += k){
                int x =0;
                for(int j = i ; j < min(i + k, (int)s.size()); j++){
                    x += s[j]-'0';
                }
                t += to_string(x);
            }
            s = t;
        }
        return s;
    }
};