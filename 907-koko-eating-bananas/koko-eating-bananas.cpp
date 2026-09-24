class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int left = 1;
        int right = *max_element(piles.begin(),piles.end());
        int k;
      
        while(left < right){
            int mid = left + (right - left)/2;
             k =0;
            for(int i = 0 ; i < n ; i++){
                int x = (piles[i]+mid-1)/mid;
                    k += x;
            }
            if(k <= h){
               
                right = mid;
            }else{

                left = mid+1;
            }
        }
        return left;
    }
};