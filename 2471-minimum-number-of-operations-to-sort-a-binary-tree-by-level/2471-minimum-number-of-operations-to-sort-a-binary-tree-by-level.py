# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minimumOperations(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return None
        queue = [root]
        minOper = 0
        
        def perm(arr):
            tot = 0
            n = len(arr)
            arrPos = [*enumerate(arr)]
            arrPos.sort(key=lambda k:k[1])
            vis = {k:False for k in range(n)}
            
            for i in range(n):
                if vis[i] or arrPos[i][0] == i:
                    continue
                
                cycleSize = 0
                j = i
                while not vis[j]:
                    vis[j] = True
                    j = arrPos[j][0]
                    cycleSize += 1
                if cycleSize > 1:
                    tot += cycleSize-1
            return tot
                    
            
        
        while queue:
            vals = []
            for _ in range(len(queue)):
                n = queue.pop(0)
                vals.append(n.val)
                if n.left:
                    queue.append(n.left)
                if n.right:
                    queue.append(n.right)
            minOper += perm(vals)
        return minOper
                
            
                