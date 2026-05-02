class Solution {
public:
    int rotatedDigits(int n) {
        int count =0;
        
        
        for(int i = 1 ; i <= n ; i++){
            int num = i;
            bool isV = true;
            bool isD=false;
             
           
            while(num>0){
                if(num%10 == 3 || num%10==4 || num%10==7){
                    isV = false;
                    break;
                }
                if(num%10 == 2 || num%10 == 5 || num%10 == 6 || num%10 == 9){
                    isD = true;
                }
                num /= 10;
            }
            if(isD && isV){
                count++;
            }
           
        }
        return count;
    }
};