class Solution {
public:

    void dfs (vector<vector<int>>& image,int r, int c,int x,int color){
        int n = image.size();
        int m = image[0].size();
        if(r < 0 || c < 0 || r>=n || c >= m ){
            return ;
        }
        if(image[r][c] != x){
            return;
        }
        image[r][c] = color;
        
        dfs(image ,r+1,c,x,color);
        dfs(image ,r-1,c,x,color);
        dfs(image ,r,c-1,x,color);
        dfs(image ,r,c+1,x,color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        
        int x = image[sr][sc];
        if(x == color) return image;
        
        dfs(image,sr,sc,x,color);
        return image;
    }
};