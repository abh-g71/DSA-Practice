class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();

        int ans = 0;
        int left = 0;
        unordered_map<char,int>freq;
        int maxFreq = 0;

        for(int r= 0 ; r < n ; r++){
            freq[s[r]]++;
            maxFreq = max(maxFreq,freq[s[r]]);

            while((r-left+1) - maxFreq > k){
                freq[s[left]]--;
                left++;
            }
            ans = max(ans,r-left+1);
        }
        return ans;
    }
};