class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        int mini = INT_MAX;
        vector<vector<int>>ans;
        for(int i = 1 ; i < n ;i++ ){
            mini = min(mini,arr[i]-arr[i-1]);
        }
        for(int i = 1 ; i < n ;i++ ){
            if(mini == arr[i]-arr[i-1]){
                ans.push_back({arr[i-1],arr[i]});
            }
        }
        return ans;
    }
};