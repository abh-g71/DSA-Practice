class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int s = flowerbed.size();

        if(s==1){
            return (flowerbed[0] == 0 && n<=1 || n==0);
        }
        if(s>1 &&flowerbed[0] == 0 && flowerbed[1] == 0){
            flowerbed[0] = 1;
            n--;
        }
        if( s > 1 &&flowerbed[s-1] == 0 && flowerbed[s-2] == 0){
            flowerbed[s-1] = 1;
            n--;
        }
        for(int i = 1 ;i <s-1 ; i++){

            if(flowerbed[i] == 0 && flowerbed[i-1] != 1 && flowerbed[i+1] != 1){
                flowerbed[i] = 1;
                n--;
            }
        }
        if(n<=0){
            return true;
        }
        return false;
    }
};