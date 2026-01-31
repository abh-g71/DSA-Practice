class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int>freq1;
        unordered_map<string,int>freq2;
        int count =0;
        for(auto &s : words1){
            freq1[s]++;
        }
        for(auto &s : words2){
            freq2[s]++;
        }
        for(auto &c : freq1){
            if(c.second == 1 && freq2[c.first] == 1){
                count++;
            }
        }
        return count;
    }
};