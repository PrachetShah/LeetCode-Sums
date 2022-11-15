# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def countNodes(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        q=deque()
        q.append(root)
        ans=0
        while q:
            head=q.popleft()
            ans+=1
            if head.left:
                q.append(head.left)
            if head.right:
                q.append(head.right)
        return ans