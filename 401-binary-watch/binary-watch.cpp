class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string>ans;

        for(int i = 0 ; i < 12 ; i++){
            for(int j = 0 ; j < 60; j++){
                int totalBits = __builtin_popcount(i) + __builtin_popcount(j);

                if(totalBits == turnedOn){

                    string time =to_string(i) + ":";

                    if(j < 10){
                        time += "0";
                    }

                    time += to_string(j);

                        ans.push_back(time);

                }
            }

        }
        return ans ;
    }
};