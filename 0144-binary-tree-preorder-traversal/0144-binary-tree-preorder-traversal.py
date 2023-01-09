# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        output = []
        def traverse(output, root):
            if root == None:
                return False
            output.append(root.val)
            traverse(output, root.left)
            traverse(output, root.right)
        traverse(output, root)
        return output