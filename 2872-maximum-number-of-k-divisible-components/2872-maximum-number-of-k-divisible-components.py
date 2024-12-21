class Solution:
    def maxKDivisibleComponents(self, n: int, edges: List[List[int]], values: List[int], k: int) -> int:
        if n<2:
            return 1
        
        componentCount = 0
        graph = defaultdict(list)
        inDegree = [0 for _ in range(n)]
        
        # build graph and cal; indegree
        for node1, node2 in edges:
            graph[node1].append(node2)
            graph[node2].append(node1)
            inDegree[node1] += 1
            inDegree[node2] += 1
        
        # init dequeu with leaf nodes
        queue = deque(node for node in range(n) if inDegree[node]==1)
        
        while queue:
            currentNode = queue.popleft()
            inDegree[currentNode] -= 1
            addVal = 0
            
            # check if currentNode val % k ==0
            if values[currentNode]%k == 0:
                componentCount += 1
            else:
                addVal = values[currentNode]
                
            # propogate value to other nodes
            for neighbor in graph[currentNode]:
                if inDegree[neighbor] == 0:
                    continue
                inDegree[neighbor] -= 1
                values[neighbor] += addVal
                
                # if neighbor's indegree becomnes 1, add it to queue
                if inDegree[neighbor] == 1:
                    queue.append(neighbor)
        return componentCount