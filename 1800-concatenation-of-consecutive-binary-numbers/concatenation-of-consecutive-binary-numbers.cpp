class Solution {
public:
    int concatenatedBinary(int n) {
        int MOD = 1e9+7;

        long long res = 0;
        long long len = 0;

        for(int i = 1 ; i <= n ; i++){
            if((i & (i-1)) == 0){
                len++;
            }
            res = ((res << len) % MOD +i) %MOD;
        }
        return res;
    }
};