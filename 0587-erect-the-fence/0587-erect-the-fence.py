class Solution:
    def outerTrees(self, trees: List[List[int]]) -> List[List[int]]:
        # implement with Monotone Chain
        
        # corner case, only one tree
        if len(trees) == 1:
            return trees
        
        # orientation() to calculate the counterclockwise order
        def orientation(p:List[int], q:List[int], r:List[int]) -> int:
            # |(q[x] - p[x])  (q[y] - p[y]) |
            # |(r[x] - q[x])  (r[y] - q[y]) |
            return (q[0] - p[0]) * (r[1] - q[1]) - (q[1] - p[1]) * (r[0] - q[0])
        
        # traverse() to traverse from left to right or right to left.
        def traverse(trees: List[List[int]], stack:List[int]):
            for tree in trees:
                while len(stack) >= 2:
                    if orientation(stack[-2], stack[-1], tree) > 0:
                        stack.pop()
                    else:
                        break
                stack.append(tree)
            # pop the last item, it will be taken care in the other bound
            stack.pop()
            
        # sort left to right
        trees = sorted(trees, key=lambda x: (x[0], x[1]))
        hull = []
        traverse(trees, hull)
        traverse(reversed(trees), hull)
        
        # remvoe dup items
        result = set(tuple(h) for h in hull)
        return list(result)