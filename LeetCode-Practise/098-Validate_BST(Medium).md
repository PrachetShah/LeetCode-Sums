### Python O(n) sol. by divide-and-conquer.

### Hint:

Think of BST rule:
- Left sub-tree nodes' value < current node value
- Right sub-tree nodes' value > current node value

### Algorithm:

1. Step_#1:
Set upper bound as maximum integer, and lower bound as minimum integer in run-time environment.

2. Step_#2:
Start DFS traversal from root node, and check whether each level follow BST rules or not.
Update lower bound and upper bound before going down to next level.

3. Step_#3:
Once we find the violation, reject and early return False.
Otherwise, accept and return True if all tree nodes follow BST rule.

```
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        
        # Use maximal system integer to represent infinity
        INF = sys.maxsize
        
        def helper(node, lower, upper):
            
            if not node:
				# empty node or empty tree
                return True
            
            if lower < node.val < upper:
				# check if all tree nodes follow BST rule
                return helper(node.left, lower, node.val) and helper(node.right, node.val, upper)
            
            else:
				# early reject when we find violation
                return False
            
        # ----------------------------------
        
        return helper( node=root, lower=-INF, upper=INF )
```
