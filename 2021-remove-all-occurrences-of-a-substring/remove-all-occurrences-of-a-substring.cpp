class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n = s.size();
        int m = part.size();

        vector<char>st;

        for(char c : s){
            st.push_back(c);

            if(st.size() >=m){
                bool match = true;

                for(int j = 0 ; j < m ; j++){
                    if(st[st.size()-m +j] != part[j]){
                        match = false;
                        break;
                    }
                }
            

            if(match){
                for(int i = 0; i < m ;i++){
                    st.pop_back();
                }
            }
            }
        }
        return string(st.begin(),st.end());
    }
};