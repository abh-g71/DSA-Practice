class Solution {
public:
    int numberOfSpecialChars(string word) {
        int count = 0 ;
        
        unordered_set<char>s(word.begin(),word.end());

        for(char c = 'a'; c <= 'z' ; c++){
            if(s.count(c) && s.count(toupper(c))){
                count++;
            }
        }
        return count;

    }
};