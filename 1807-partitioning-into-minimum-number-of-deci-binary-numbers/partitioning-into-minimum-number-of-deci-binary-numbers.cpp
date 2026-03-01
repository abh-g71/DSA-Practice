class Solution {
public:
    int minPartitions(string n) {
        int maxi = INT_MIN;
        for(int i = 0 ; i < n.size() ; i++){
            maxi = max(n[i] - '0',maxi);
        }     
        return maxi;
    }
};