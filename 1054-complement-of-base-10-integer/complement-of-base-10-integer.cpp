class Solution {
public:
    int bitwiseComplement(int n) {
        int power  = 1;
        int result = 0;
        if(n==0){
            return 1;
        }
        while(n>0){
            int bit = n%2;
            bit = 1-bit;
             result += power * bit ;

            power *= 2;
            n /= 2;
        }
        return result;
    }
};