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
            pos = {m:j for j,m in enumerate(sorted(arr))}
            vis = [0]*len(arr)
            tot = 0
            
            for i in range(len(arr)):
                cnt = 0
                while not vis[i] and i != pos[arr[i]]:
                    vis[i], i = 1, pos[arr[i]]
                    cnt += 1
                tot += max(0, cnt-1)
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
                
            
                