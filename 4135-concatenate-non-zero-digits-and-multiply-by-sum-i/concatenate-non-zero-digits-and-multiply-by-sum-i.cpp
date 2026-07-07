class Solution {
public:
    long long sumAndMultiply(int n) {
         string s1;
        string s2 =  to_string(n);
        
        for(int i = 0 ; i < s2.size(); i++){
            if(s2[i] != '0'){
                s1.push_back(s2[i]);
            }
        }
        if(s1==""){
            return 0;
        }
        long long ans = stoll(s1);
        long long num = ans;
        long long sum = 0;
        while(num){
            sum += num%10;
            num /= 10;
        }

        return sum * ans;
    }
};