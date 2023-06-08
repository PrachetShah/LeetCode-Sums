class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        int currRowNegativeIndex = grid[0].size() - 1;
        
        for(int i=0; i<grid.size(); i++){
            while (currRowNegativeIndex >= 0 && grid[i][currRowNegativeIndex] < 0) {
                currRowNegativeIndex--;
            }
            
            count += (grid[0].size()-(currRowNegativeIndex+1));
        }
        return count;
    }
};