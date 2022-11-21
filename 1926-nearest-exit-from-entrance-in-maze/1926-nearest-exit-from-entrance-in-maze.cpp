class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int rows = int(maze.size()), cols = int(maze[0].size());
        vector<pair<int, int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        
        int startRow = entrance[0], startCol = entrance[1];
        maze[startRow][startCol] = '+';
        
        queue<array<int, 3>> queue;
        queue.push({startRow, startCol, 0});
        
        while(!queue.empty()){
            auto [currRow, currCol, currDistance] = queue.front();
            queue.pop();
            
            for(auto dir:dirs){
                int nextRow = currRow + dir.first, nextCol = currCol+dir.second;
                
                if(0<=nextRow && nextRow<rows && 0<=nextCol && nextCol<cols && maze[nextRow][nextCol]=='.'){
                    if(nextRow==0 || nextRow==rows-1 || nextCol==0 || nextCol == cols-1){
                        return currDistance+1;
                    }
                    
                    maze[nextRow][nextCol] = '+';
                    queue.push({nextRow, nextCol, currDistance+1});
                }
            }
        }
        return -1;
    }
};