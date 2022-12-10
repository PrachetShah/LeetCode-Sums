class Solution:
    def maxProduct(self, root: Optional[TreeNode]) -> int:
        vals = []
        
        def fn(node): 
            """Return sum of sub-tree."""
            if not node: return 0 
            ans = node.val + fn(node.left) + fn(node.right)
            vals.append(ans)
            return ans
        
        total = fn(root)
        return max((total-x)*x for x in vals) % 1_000_000_007