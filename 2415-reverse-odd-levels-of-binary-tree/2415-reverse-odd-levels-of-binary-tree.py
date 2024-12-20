# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def reverseOddLevels(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
#         dfs approach
        # isOdd = False
        # def solve(leftC, rightC, isOdd):
        #     if leftC is None or rightC is None:
        #         return
        #     if isOdd%2 == 0:
        #         leftC.val, rightC.val = rightC.val, leftC.val
        #     solve(leftC.left, rightC.right, isOdd+1)
        #     solve(leftC.right, rightC.left, isOdd+1)
        # solve(root.left, root.right, 0)
        # return root
#         BFS Approach
        if root is None:
            return None
        queue = [root]
        level = 0
        while queue:
            size = len(queue)
            currentLvl = []
            for _ in range(size):
                node = queue.pop(0)
                currentLvl.append(node)
                
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
                
            if level%2==1:
                left, right = 0, len(currentLvl)-1
                while left < right:
                    currentLvl[left].val, currentLvl[right].val = currentLvl[right].val, currentLvl[left].val
                    left += 1
                    right -= 1
            level += 1
        return root
        