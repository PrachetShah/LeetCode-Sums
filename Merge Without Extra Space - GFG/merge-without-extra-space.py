#User function Template for python3

class Solution:
    
    #Function to merge the arrays.
    def merge(self,arr1,arr2,n,m):
        #code here
        i,j,k = 0,0,n-1
        while(i<=k and j<m):
            if arr1[i] < arr2[j]:
                i += 1
            else:
                arr2[j], arr1[k] = arr1[k], arr2[j]
                j += 1
                k -= 1
        arr1.sort()
        arr2.sort()
            
    



#{ 
 # Driver Code Starts
#Initial template for Python

if __name__ == '__main__':
    t = int(input())
    for tt in range(t):
        n,m = map(int, input().strip().split())
        arr1 = list(map(int, input().strip().split()))
        arr2 = list(map(int, input().strip().split()))
        ob=Solution()
        ob.merge(arr1, arr2, n, m)
        print(*arr1,end=" ")
        print(*arr2)
# } Driver Code Ends