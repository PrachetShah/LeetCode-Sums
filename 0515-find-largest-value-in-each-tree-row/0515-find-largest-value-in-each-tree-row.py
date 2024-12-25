# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        if root is None:
            return []
        queue = [[root]]
        maxArr = []
        
        while queue:
            lvlNodes = queue.pop(0)
            maxi = float('-inf')
            nextLvl = []
            for node in lvlNodes:
                maxi = max(node.val, maxi)
                if node.left:
                    nextLvl.append(node.left)
                if node.right:
                    nextLvl.append(node.right)
            if len(nextLvl) > 0:
                queue.append(nextLvl)
            maxArr.append(maxi)
        return maxArr
                    
                 