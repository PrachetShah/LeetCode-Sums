# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        output = []
        stack = [root]
        while stack:
            curr = stack.pop(-1)
            if curr:
                output.append(curr.val)
                stack.append(curr.right)
                stack.append(curr.left)

        return output