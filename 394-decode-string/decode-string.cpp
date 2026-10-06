class Solution {
public:
    string decodeString(string s) {
        stack<int>nums;
        stack<string>st;
        int num =0;
        string ans = "";

        for(auto ch : s){
            if(isdigit(ch)){
                num = num*10 + (ch-'0');
            }else if(ch == '['){
                nums.push(num);
                st.push(ans);
                num =0;
                ans="";
            }else if(ch == ']'){
                int times = nums.top();
                nums.pop();
                string temp = st.top();
                st.pop();

                while(times--){
                    temp += ans;
                }
                ans = temp;
            }else{
                ans += ch;
            }
        }
        return ans;
    }
};