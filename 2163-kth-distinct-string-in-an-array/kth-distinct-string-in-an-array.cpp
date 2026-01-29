class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int>freq;
        for(auto &ch : arr){
            freq[ch]++;
        }
        for(auto &s : arr){
           if(freq[s] == 1){
            k--;
            if(k==0){
                return s;
            }
           }
        }
        return "";
    }
};