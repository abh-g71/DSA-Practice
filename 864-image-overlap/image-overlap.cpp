class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int,int>>a,b;

        for(int i = 0 ; i < img1.size(); i++){
            for(int j = 0 ; j < img1.size(); j++){
                if(img1[i][j] == 1){
                    a.push_back({i,j});
                }
                if(img2[i][j] == 1){
                    b.push_back({i,j});
                }
            }
        }

        unordered_map<string,int>mp;
        int ans = 0;

        for(auto [r1,c1] : a){
            for(auto [r2,c2] : b){
                int dr = r2-r1;
                int dc = c2-c1;

                string key = to_string(dr) + "," + to_string(dc);

                mp[key]++;
                ans= max(ans,mp[key]);
            }

        }
        return ans;
    }
};