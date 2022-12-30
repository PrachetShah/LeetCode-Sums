class Solution:
    # Best Solution:
    # https://leetcode.com/problems/all-paths-from-source-to-target/discuss/986429/Python-Iterative-DFS-with-detailed-time-complexity-and-visuals
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        if not graph:
            return []
        
        # build di-graph
        d = {}
        for i in range(len(graph)):
            d[i] = graph[i]
        
        # apply DFS on DAG
        n = len(graph)
        stack = [(0, [0])]
        res = []
        while stack:
            node, path = stack.pop()
            if node == n-1:
                res.append(path)
            # traverse rest
            for nei in d[node]:
                stack.append((nei, path+[nei]))
        return res
        