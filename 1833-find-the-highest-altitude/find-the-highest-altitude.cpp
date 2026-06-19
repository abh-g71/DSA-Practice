class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int prefixSum = 0;
        int maxi = INT_MIN;

        for(int i = 0 ;  i < n ; i++){
            prefixSum += gain[i];
            maxi = max(maxi,prefixSum);
        }
        maxi = max(maxi,0);
        return maxi;
    }
};