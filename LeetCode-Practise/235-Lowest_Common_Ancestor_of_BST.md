Let ```large = max(p.val, q.val), small = min(p.val, q.val).```
## We keep iterate root in our BST:
- If root.val > large then both node p and q belong to the left subtree, go to left by root = root.left.
- If root.val < small then both node p and q belong to the right subtree, go to right by root = root.right.
- Now, small <= root.val <= large the current root is the LCA between q and p.

### Intuition
<img src="https://assets.leetcode.com/users/images/c9441871-3cdd-49fa-b4f4-7ab1f88779f1_1626682525.9321432.png" alt='algo' />

```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        small = min(p.val, q.val)
        large = max(p.val, q.val)
        while root:
            if root.val > large:
                root = root.left
            elif root.val < small:
                root = root.right
            else:
                return root
        return None
```


## LCA using 2 Approaches
1. Recursive: Time Complexity: O(h), Space Complexity: O(h)
2. Iterative: Time Complexity: O(h), Space Complexity: O(1)

- Recusrive:
```
# A Binary tree node
class Node:
	# Constructor to create a new node
	def __init__(self, data):
		self.data = data
		self.left = None
		self.right = None

# Function to find LCA of n1 and n2. The function assumes
# that both n1 and n2 are present in BST
def lca(root, n1, n2):
	
	# Base Case
	if root is None:
		return None

	# If both n1 and n2 are smaller than root, then LCA
	# lies in left
	if(root.data > n1 and root.data > n2):
		return lca(root.left, n1, n2)

	# If both n1 and n2 are greater than root, then LCA
	# lies in right
	if(root.data < n1 and root.data < n2):
		return lca(root.right, n1, n2)

	return root
```

- Iterative
```
# A Binary tree node
class Node:
	# Constructor to create a new node
	def __init__(self, data):
		self.data = data
		self.left = None
		self.right = None

# Function to find LCA of n1 and n2.
# The function assumes that both
# n1 and n2 are present in BST
def lca(root, n1, n2):
	while root:
		# If both n1 and n2 are smaller than root,
		# then LCA lies in left
		if root.data > n1 and root.data > n2:
			root = root.left
		
		# If both n1 and n2 are greater than root,
		# then LCA lies in right
		elif root.data < n1 and root.data < n2:
			root = root.right

		else:
			break

	return root
```
