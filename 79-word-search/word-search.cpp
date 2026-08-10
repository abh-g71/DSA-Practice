class Solution {
public:

    bool solve(vector<vector<char>>& board, string word,int i , int j , int  k){
        int n = board.size();
        int m = board[0].size();
        int o = word.size();

        if(k==o){
            return  true;
        }
        
        if(i >= n || j >= m || i<0 || j<0 || board[i][j] != word[k] ){
           return false;
        } 

        char temp = board[i][j];
        board[i][j] = '#';

        bool found = 

           solve(board,word,i+1,j,k+1) ||
            solve(board,word,i,j+1,k+1) ||
             solve(board,word,i-1,j,k+1) ||
              solve(board,word,i,j-1,k+1);
        
        board[i][j] = temp;

        return found;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        int o = word.size();
       
       

        for(int i = 0; i < n ; i++){
            for(int j = 0 ;  j < m ; j++){
            
                if(board[i][j] == word[0]){
                     if(solve(board,word,i,j,0)){
                        return true;
                     }
                }
               
            }
           
        }
        
        return false;
    }
};