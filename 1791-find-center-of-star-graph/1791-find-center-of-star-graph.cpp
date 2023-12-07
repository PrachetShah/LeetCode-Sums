class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int, bool> visited;
        visited[edges[0][0]] = 1;
        visited[edges[0][1]] = 1;
        
        if(visited.find(edges[1][0]) != visited.end()){
            return edges[1][0];
        }else{
            return edges[1][1];
        }
        return 0;
    }
};