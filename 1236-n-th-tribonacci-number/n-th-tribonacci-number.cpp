class Solution {
public:
    int solve(int n){
        int prev1 = 0;
        int prev2 = 1;
        int prev3 = 1;
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return 1;
        }
        if(n == 2){
            return 1;
        }
        int ans ;
        for(int i = 3; i <=n ; i++){
            ans = prev1 + prev2 + prev3;
            prev1 = prev2;
            prev2 = prev3;
            prev3 = ans;
        }
        return ans;
    }
    int tribonacci(int n) {
        return solve(n);
    }
};