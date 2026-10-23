class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int lowest = prices[0];
        int highest = 0;
        for(int i = 1; i < n; i++){
            if(prices[i] < lowest){
                lowest = prices[i];
            }
            highest = max(highest,prices[i]-lowest);
        }
        return highest;
    }
};