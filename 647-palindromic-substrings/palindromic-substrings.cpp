class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int left =0;
        int count = 0;
        while(left < n){
            for(int right = left ; right < n ; right++){
                bool palindrome = true;
                int r = right;
                int l = left;
                while(l < r){
                    if(s[l] != s[r]){
                        palindrome = false;
                    }
                    l++;
                    r--;
                }
                if(palindrome){
                    count++;
                }
            }
            left++;
        }
        return count;
    }
};