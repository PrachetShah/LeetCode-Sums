class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        unordered_map<int, int> rows;
        unordered_map<int, int> cols;
        int m = grid.size();
        int n = grid[0].size();
        
        for(int i=0; i<m; i++){
            int countZero = 0;
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0){
                    countZero++;
                }
            }
            rows[i] = countZero;
        }
        
        for(int i=0; i<n; i++){
            int countZero = 0;
            for(int j=0; j<m; j++){
                if(grid[j][i] == 0){
                    countZero++;
                }
            }
            cols[i] = countZero;
        }
        
        vector<vector<int>> ans(m, vector<int> (n, 0));
        for(int i=0; i<m ;i++){
            for(int j=0; j<n; j++){
                ans[i][j] = n+m-2*rows[i]-2*cols[j];
            }
        }
        
        return ans;
    }
};