# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        def height(root):
            nonlocal diameter
            if not root:
                return 0
            left = height(root.left)
            right = height(root.right)
            diameter = max(diameter, left+right)
            return max(left, right) + 1
        diameter = 0
        height(root)
        return diameter
            
        
