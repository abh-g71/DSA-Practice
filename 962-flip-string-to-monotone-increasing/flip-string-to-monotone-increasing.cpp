class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int ones = 0;
        int flips = 0;

        for(int  i= 0 ; i < s.size(); i++){
            if(s[i] == '1'){
                ones++;
            }else{
                flips = min(flips+1,ones);
            }
        }
        return flips;
    }
};