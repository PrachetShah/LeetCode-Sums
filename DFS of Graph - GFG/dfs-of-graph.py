#User function Template for python3

class Solution:
    
    #Function to return a list containing the DFS traversal of the graph.
    def util(self, v, visited, adj, output):
        visited.add(v)
        output.append(v)
        for i in adj[v]:
            if i not in visited:
                self.util(i, visited, adj, output)
    def dfsOfGraph(self, V, adj):
        # code here
        visited = set()
        output = []
        self.util(0, visited, adj, output)
        return output


#{ 
 # Driver Code Starts
if __name__ == '__main__':
    T=int(input())
    while T>0:
        V,E=map(int,input().split())
        adj=[[] for i in range(V+1)]
        for i in range(E):
            u,v=map(int,input().split())
            adj[u].append(v)
            adj[v].append(u)
        ob=Solution()
        ans=ob.dfsOfGraph(V,adj)
        for i in range(len(ans)):
            print(ans[i],end=" ")
        print()
        T-=1
# } Driver Code Ends