class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int>d(1001,0);

        for(auto &i : trips){
            int num = i[0];
            int from = i[1];
            int to = i[2];

            d[from] += num;
            d[to] -= num;
        }

        int ans = 0;

        for(int i = 0 ; i <= 1000; i++){
            ans += d[i];

            if(ans > capacity) return false;
        }
        return true;
    }
};