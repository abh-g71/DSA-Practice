class Solution {
public:
    bool judgeCircle(string moves) {
        unordered_map<char,int>freq;

        for(auto i : moves){
            freq[i]++;
        }
        
        for(auto i : freq){
            
            if(freq['R'] != freq['L'] || freq['U'] != freq['D']){
                return false;
            }
        }
        
        return true;
    }
};