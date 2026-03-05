class Solution {
public:
    int minOperations(string s) {
        int count1 = 0;
        int count2  = 0 ;
        for(int i = 0 ; i < s.size();i++){
           
            if((i % 2 == 0 && s[i] != '0') || (i % 2 == 1 && s[i] != '1')){
                count1++;
            }
            if((i % 2 == 0 && s[i] != '1') || (i % 2 == 1 && s[i] != '0')){
                count2++;
            }
            
        }
        
        return min(count1,count2);
    }
};