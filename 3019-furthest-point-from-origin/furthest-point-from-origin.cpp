class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n = moves.size();
        int c1 = 0;
        int c2 = 0;
        int c3 = 0;
        for(int i = 0 ; i < n ; i++){
            if(moves[i] == 'L') c1++;
            if(moves[i] == 'R') c2++;
            if(moves[i] == '_') c3++;
        }
        return abs(c1-c2)+c3;
    }
};