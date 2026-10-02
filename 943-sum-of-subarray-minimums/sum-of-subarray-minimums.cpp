class Solution {
public:
    vector<int>getNSL(vector<int>& arr,int n){
        stack<int>st;
        vector<int>l(n);
        for(int i = 0 ;  i < n ;i++){
            if(st.empty()){
                l[i]= -1;

            }else{
                while(!st.empty() && arr[st.top()] > arr[i]){
                    st.pop();

                    
                }
                l[i] = st.empty() ? -1 : st.top();
            }
            st.push(i);
        }
        return l;
    }
    vector<int>getRSL(vector<int>& arr,int n){
        stack<int>st;
        vector<int>l(n);
        for(int i = n-1 ;  i >=0 ;i--){
            if(st.empty()){
                l[i]= n;

            }else{
                while(!st.empty() && arr[st.top()] >= arr[i]){
                    st.pop();

                    
                }
                l[i] = st.empty() ? n : st.top();
            }
            st.push(i);
        }
        return l;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int>left = getNSL(arr,n);
        vector<int>right = getRSL(arr,n);

        const int mod = 1e9 + 7;
        long long sum = 0;

        for(int i = 0 ; i < n ; i++){
            int ls = i-left[i];
            int rs = right[i]-i;

            long long  ways = 1LL * ls * rs;

           sum = (sum + ways * arr[i]) % mod;
        }
        return sum;
    }
};