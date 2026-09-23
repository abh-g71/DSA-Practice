class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()){
            return "";
        }

        unordered_map<char,int>need;
        unordered_map<char,int>window;

        for(auto i : t){
            need[i]++;
        }

        int left = 0;
        int required = need.size();
        int formed = 0;
        int minLength = INT_MAX;
        int start = 0;

        for(int right = 0 ;right < s.size(); right++){
            window[s[right]]++;

            if(need.count(s[right]) && window[s[right]] == need[s[right]]){
                formed++;
            }
            while(formed == required){
                if(right-left+1 < minLength){
                    minLength = right-left+1;
                    start = left;
                }

                char remove = s[left];
                window[remove]--;

                if(need.count(remove) && window[remove] < need[remove]){
                    formed--;
                }

                left++;
            }
        }
        if(minLength == INT_MAX){
            return "";
        }
        return s.substr(start,minLength);

    }
};