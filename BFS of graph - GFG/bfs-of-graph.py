#User function Template for python3

from typing import List
from queue import Queue
class Solution:
    #Function to return Breadth First Traversal of given graph.
    def bfsOfGraph(self, V: int, adj: List[List[int]]) -> List[int]:
        ans = []
        
        #boolean list to mark all the vertices as not visited.
        vis = [False for i in range(V)]
        
        #creating a queue for BFS and pushing first vertex in queue.
        q = Queue(maxsize = 0)
        q.put(0)
        
        #initially we mark first vertex as visited(true).
        vis[0] = True
        
        while(q.empty() == False):
            
            #adding front element in output list and popping it from queue.
            v = q.get()
            ans.append(v)
            
            #traversing over all the connected components of front element.
            for i in adj[v]:
                
                #if they aren't visited, we mark them visited and add to queue.
                if(vis[i] == False):
                    vis[i] = True
                    q.put(i)
                    
        #returning the output list.
        return ans

#{ 
 # Driver Code Starts


if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		V, E = map(int, input().split())
		adj = [[] for i in range(V)]
		for _ in range(E):
			u, v = map(int, input().split())
			adj[u].append(v)
		ob = Solution()
		ans = ob.bfsOfGraph(V, adj)
		for i in range(len(ans)):
		    print(ans[i], end = " ")
		print()
        

# } Driver Code Ends