class Solution:
    def minTime(self, n: int, edges: List[List[int]], hasApple: List[bool]) -> int:
        adj = defaultdict(list)
        for s, e in edges:
            adj[s].append(e)
            adj[e].append(s)
        def dfs(node, parent, ad, hasApple):
            totalTime, childTime = 0, 0
            for child in adj[node]:
                if child == parent:
                    continue
                childTime = dfs(child, node, adj, hasApple)
                if childTime or hasApple[child]:
                    totalTime += childTime + 2
            return totalTime
        return dfs(0, -1, adj, hasApple)