// Remove characters from a string except alphabet

#include<bits/stc++.h>
using namespace std;

class Solution {
public:
    // Function to remove non-alphabet characters
    string removeNonAlphabets(string s) {
        string result = "";
        for (char c : s) {
            // Check if character is alphabet
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
                result += c;
            }
        }
        return result;
    }
};
