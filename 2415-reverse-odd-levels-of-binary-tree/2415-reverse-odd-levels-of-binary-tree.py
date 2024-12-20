# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def reverseOddLevels(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        isOdd = False
        def solve(leftC, rightC, isOdd):
            if leftC is None or rightC is None:
                return
            if isOdd%2 == 0:
                leftC.val, rightC.val = rightC.val, leftC.val
            solve(leftC.left, rightC.right, isOdd+1)
            solve(leftC.right, rightC.left, isOdd+1)
        solve(root.left, root.right, 0)
        return root