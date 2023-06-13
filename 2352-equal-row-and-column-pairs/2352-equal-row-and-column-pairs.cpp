class Solution {
public:
   int equalPairs(vector<vector<int>>& grid) {
        vector<vector<int>> grid2=grid;
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=i; j<grid[0].size(); j++)
            {
                swap(grid[i][j],grid[j][i]);
            }
        }
        int ans=0;
        for(int i=0;i<grid2.size(); i++)
        {
            for(int j=0;j<grid.size(); j++)
            {
                if(grid2[i]==grid[j])
                    ans++;
            }
        }
        return ans;
    }
};