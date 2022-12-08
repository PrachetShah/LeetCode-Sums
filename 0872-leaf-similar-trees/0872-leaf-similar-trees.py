# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def leafSimilar(self, root1, root2):
        """
        :type root1: TreeNode
        :type root2: TreeNode
        :rtype: bool
        """
        return self.iterative(root1,[]) == self.iterative(root2,[])
        
    def iterative(self,root,s):
        if root is not None:
            stack = []
            stack.append(root)
            while stack:
                x = stack.pop(-1)
                if x.left is None and x.right is None:
                    s.append(x.val)
                    continue
                if x.right is not None:
                    stack.append(x.right)
                if x.left is not None:
                    stack.append(x.left)
        return s