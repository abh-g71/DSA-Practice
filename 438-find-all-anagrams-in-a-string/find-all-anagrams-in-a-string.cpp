class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();
        
        int left = 0;
        vector<int>ans;
        sort(p.begin(),p.end());
        vector<int>freq(26,0);
        vector<int>freqs(26,0);
        for(int i =  0;i<m;i++){
            freq[p[i]-'a']++;
        }


        for(int right = 0; right < n ; right++){
            freqs[s[right]-'a']++;
            if(right-left+1 == m){
                if(freq == freqs){
                    ans.push_back(left);
                    
                }
                freqs[s[left]-'a']--;
                left++;
            }
        }
        
        return ans;
    }
};