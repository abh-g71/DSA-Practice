class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int left = *max_element(weights.begin(),weights.end());
        int right = 0;
        for(int i = 0 ;  i < n ; i++){
            right += weights[i];
        }
        int k;
      
        while(left < right){
            int mid = left + (right - left)/2;
            
             int requiredDays = 1;
             int sum  =0 ;

             
            for(int i = 0 ; i < n ; i++){
                if(sum+weights[i] > mid){
                    requiredDays++;
                    sum = 0;
                }
                sum += weights[i];
                
            }
            if(requiredDays <= days){
               
                right = mid;
            }else{

                left = mid+1;
            }
        }
        return left;
    }
};