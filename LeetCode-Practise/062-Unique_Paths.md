## 3 Pyhon Sol. based on dynamic programming, math analysis, and recursion.

#### Diagram:

![Diagram](https://assets.leetcode.com/users/images/2cf56e11-729e-426b-be98-2ef81469d933_1613721428.3846037.png)

#### method_#1: Dynamic Programming
```
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:     
        rows, cols = m, n
   
        path_dp = [ [ 1 for j in range(cols)] for i in range(rows) ]
        # Dynamic Programming relation:
        
        # Base case:
        # DP(0, j) = 1 , only reachable from one step left
        # DP(i, 0) = 1 , only reachable from one step up
        
        # General case:
        # DP(i,j) = number of path reach to (i, j)
        #         = number of path reach to one step left + number of path reach to one step up
        #         = number of path reach to (i, j-1) + number of path to (i-1, j)
        #         = DP(i, j-1) + DP(i-1, j)
      
        for i in range(1, rows):
            for j in range(1, cols):
                
                path_dp[i][j] = path_dp[i][j-1] + path_dp[i-1][j]
        
        # Destination coordination = (rows-1, cols-1)
        return path_dp[rows-1][cols-1]
```

#### method_#2: Math analysis
```
from math import factorial

class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        
        rows, cols = m, n
        
        # from start to destination, we need (m-1) ↓ moves and (n-1) → moves
        # Thus, the number of unique paths is the number of permutations of (m-1) ↓ and (n-1) →
        #
        # Number of unique paths = ( m-1 + n-1 ) ! / (m-1)! * (n-1)!
        
        
        return factorial( m+n-2 ) // ( factorial( m-1 ) * factorial( n-1 ) )    
```

#### method_#3 Recursion + Memoization

```
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        
        # -----------------------------------
        
        # key: (m, n) size of grid
        # value: total path count from source to destinaion
        memo = {}
        
        def path_count(m, n):
            
            if (m, n) in memo:
                
                # look-up in memo
                return memo[(m, n)]
            
            if m == 0 or n == 0:
                
                # base case
                memo[(m, n)] = 0
                return 0
            
            elif m == 1 and n == 1:
                
                # base case
                memo[(m, n)] = 1
                return 1

            # general case
            memo[(m, n)] = path_count(m-1, n) + path_count(m, n-1)
            return memo[(m, n)]
    
        # -----------------------------------
        return path_count(m, n)
```
