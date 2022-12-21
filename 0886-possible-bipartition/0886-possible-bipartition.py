class Solution:
    def possibleBipartition(self, n: int, dislikes: List[List[int]]) -> bool:
        def dfs(node, node_color):
            color[node] = node_color
            for neighbor in adj[node]:
                if color[neighbor] == color[node]: return False
                if color[neighbor] == -1:
                    if not dfs(neighbor, 1 - node_color):
                        return False

            return True
        
        adj = [[] for _ in range(n + 1)]
        for dislike in dislikes:
            adj[dislike[0]].append(dislike[1])
            adj[dislike[1]].append(dislike[0])
        
        color = [-1] * (n + 1) # 0 stands for red and 1 stands for blue.
        for i in range(1, n + 1):
            if color[i] == -1:
                # For each pending component, run DFS.
                if not dfs(i, 0):
                    # Return false, if there is conflict in the component.
                    return False
        
        return True