class Solution {
public:
    bool can(long long T, int h, vector<int>& w){
        long long removed = 0;

        for(long long t : w){
            long long k = (2 * T) / t;

            long long x = (sqrt(1 + 4.0 * k) - 1) / 2;

            removed += x;

            if(removed >= h)
                return true;
        }

        return false;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long left = 1, right = 1e18;
        long long ans = right;

        while(left <= right){
            long long mid = (left + right) / 2;

            if(can(mid, mountainHeight, workerTimes)){
                ans = mid;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }

        return ans;
    }
};