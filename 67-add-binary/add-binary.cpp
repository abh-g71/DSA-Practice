class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.size();
        int m = b.size();
        int r1 = n-1;
        int r2 = m-1;
        string ans = "";
        int carry = 0;

        while(r1>=0 || r2 >= 0 || carry){
            int sum = carry;
            
            if(r1 >= 0){
                sum += a[r1]-'0';
                r1--;
            }
            if(r2 >= 0){
                sum += b[r2]-'0';
                r2--;
            }
            ans += (sum%2)+'0';
            carry = sum/2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};