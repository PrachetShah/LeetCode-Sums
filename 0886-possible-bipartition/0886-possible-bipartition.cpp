class Solution {
public:
    bool dfs(int node, int nodeColor, vector<vector<int>>& adj, vector<int>& color) {
        color[node] = nodeColor;
        for (auto& neighbor : adj[node]) {
            if (color[neighbor] == color[node]) return false;
            if (color[neighbor] == -1) {
                if (!dfs(neighbor, 1 - color[node], adj, color)) return false;
            }
        }
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n + 1);
        for (auto& dislike : dislikes) {
            adj[dislike[0]].push_back(dislike[1]);
            adj[dislike[1]].push_back(dislike[0]);
        }
        vector<int> color(n + 1, -1); // 0 stands for red and 1 stands for blue.
        for (int i = 1; i <= n; i++) {
            if (color[i] == -1) {
                // For each pending component, run DFS.
                if (!dfs(i, 0, adj, color))
                    // Return false, if there is conflict in the component.
                    return false;
            }
        }
        return true;
    }
};