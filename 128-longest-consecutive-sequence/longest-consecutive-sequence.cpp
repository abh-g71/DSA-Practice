class Solution {
public:
    int longestConsecutive(vector<int>& a) {
    unordered_set<int> s(a.begin(), a.end());
    int ans = 0;
    for(int x : s) if(!s.count(x-1)){
        int y = x;
        while(s.count(y)) y++;
        ans = max(ans, y-x);
    }
    return ans;
}
};