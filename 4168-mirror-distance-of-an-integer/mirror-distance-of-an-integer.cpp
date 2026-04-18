class Solution {
public:
    
    int mirrorDistance(int n) {
        int sum = 0 ;
        int num = n;
        while(n > 0){
           int rem = n %10;
           sum = sum * 10 + rem;
           n /= 10;
        }
        return abs(num - sum);
    }
};