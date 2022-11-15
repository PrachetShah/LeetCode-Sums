# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
   
    def countNodes(self, root: Optional[TreeNode]) -> int:
        def rightCount(node):
            return 0 if not node else 1 + rightCount(node.right)

        def leftCount(node):
            return 0 if not node else 1 + leftCount(node.left)

        def count(root):
            if not root:
                return 0

            left, right = leftCount(root), rightCount(root)
            if left == right:
                return 2**(left)-1

            return 1 + count(root.left) + count(root.right)
        return count(root)
