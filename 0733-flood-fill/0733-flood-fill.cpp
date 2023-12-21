class Solution {
public:
    void dfs(vector<vector<int>> &image, int r, int c, int color, int newColor){
        if(image[r][c] == color){
            image[r][c] = newColor;
            if(r >= 1){
                dfs(image, r-1, c, color, newColor);
            }
            if(c >= 1){
                dfs(image, r, c-1, color, newColor);
            }
            if(r+1 < image.size()){
                dfs(image, r+1, c, color, newColor);
            }
            if(c+1 < image[0].size()){
                dfs(image, r, c+1, color, newColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int prev = image[sr][sc];
        if(prev != color){
            dfs(image, sr, sc, prev, color);
        }
        return image;
    }
};