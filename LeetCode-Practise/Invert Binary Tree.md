<h2>Illustration and Visualization:</h2>
<img src="https://assets.leetcode.com/users/brianchiang_tw/image_1591067976.png" />

Here what we need to do is just use definition of inverted tree. We go from top to bottom of our tree 
and if we reached the leaf, we do not do anything. If current subtree is not a leaf, 
we recursively call our function for both its children, first inverting them.

Complexity is O(h), where h is the height of our tree.

```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if root is None:
            return
        else:
            self.invertTree(root.left)
            self.invertTree(root.right)
            root.left, root.right = root.right, root.left
        return root
```
