class Solution:
    def minimumDiameterAfterMerge(self, edges1: List[List[int]], edges2: List[List[int]]) -> int:
        n = len(edges1)+1
        m = len(edges2) + 1
        
        adjList1 = self.buildAdj(n, edges1)
        adjList2 = self.buildAdj(m, edges2)
        
        diam1 = self.findDia(n, adjList1)
        diam2 = self.findDia(m, adjList2)
        
        combinedDia = ceil(diam1/2) + ceil(diam2/2) + 1
        
        return max(diam1, diam2, combinedDia)
    
    def buildAdj(self, size, edges):
        adjList = [[] for _ in range(size)]
        for edge in edges:
            adjList[edge[0]].append(edge[1])
            adjList[edge[1]].append(edge[0])
        return adjList
    
    def findDia(self, n, adjList):
        fart, _ = self.findFarthestNode(n, adjList, 0)
        _, diameter = self.findFarthestNode(n, adjList, fart)
        return diameter
    
    def findFarthestNode(self, n, adjList, sourceNode):
        queue = deque([sourceNode])
        visited = [False]*n 
        visited[sourceNode] = True
        
        maxDist = 0
        farthestNode = sourceNode
        
        while queue:
            for _ in range(len(queue)):
                curr = queue.popleft()
                farthestNode = curr
                
                for neigh in adjList[curr]:
                    if not visited[neigh]:
                        visited[neigh] = True
                        queue.append(neigh)
            if queue:
                maxDist += 1
        return farthestNode, maxDist