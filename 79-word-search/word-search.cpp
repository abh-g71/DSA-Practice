class Solution {
public:
int n , m;

    bool solve(int i , int j ,vector<vector<char>>& board,string& word,int w){
        if(w==word.size()){
            return true;
        }
        if(i < 0 || j < 0 || i >= n || j >= m || board[i][j] != word[w]){
            return false;
        }
        
        char temp = board[i][j];
        board[i][j] = '@';
        bool found = 
            solve(i+1,j,board, word,w+1) ||  solve(i,j-1,board, word,w+1) ||  solve(i,j+1,board, word,w+1) ||  solve(i-1,j,board, word,w+1);

            board[i][j] = temp;

            return found;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
         n = board.size();
         m = board[0].size();
       

        for(int i = 0 ; i < n ; i++){
            for(int j =  0 ; j < m; j++){
                if(solve(i,j,board,word,0)){
                    return true;
                }
            }
        }
        return false;
    }
};