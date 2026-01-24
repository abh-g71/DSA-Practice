class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
       unordered_set<int>st(friends.begin(),friends.end());
       vector<int>res;
       for(auto x : order){
        if(st.count(x)){
            res.push_back(x);
        }
       }
       return res;
    }
};