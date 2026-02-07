class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int>aCount(n,0);
        vector<int>bCount(n,0);

        for(int i  = 1; i < n ; i++){
            char prev = s[i-1];
            bCount[i] = bCount[i-1];
            if(prev == 'b'){
                bCount[i] += 1;
            }
        }

        for(int i  = n-2; i >= 0 ; i--){
            char prev = s[i+1];
            aCount[i] = aCount[i+1];
            if(prev == 'a'){
                aCount[i] += 1;
            }
        }
        int mini = INT_MAX;

        for(int i = 0; i < n ; i++){
            mini = min(mini,aCount[i] + bCount[i]);
        }
        return mini;
    }
};