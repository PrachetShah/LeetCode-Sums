# Recusrsive Solution
"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def preorder(self, root: 'Node') -> List[int]:
        output = []
        self.dfs(root, output)
        return output
    
    def dfs(self, root, output):
        if root is None:
            return
        output.append(root.val)
        for child in root.children:
            self.dfs(child, output)
            
# Iterative Solution
class Solution:
    def preorder(self, root: 'Node') -> List[int]:
        if root is None:
            return []
        stack = [root]
        output = []
        while stack:
            temp = stack.pop()
            output.append(temp.val)
            stack.extend(temp.children[::-1])
        return output
