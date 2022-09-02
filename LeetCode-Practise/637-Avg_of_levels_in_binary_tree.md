## Level-Order Traversal Solution

### Using dequeue
Code:
```
from collections import deque

class Solution:
    def averageOfLevels(self, root: TreeNode) -> List[float]:

        queue = deque([root])
        
        average_of_level = []
        
        while queue:
            
            # valid nodes on current level
            size = len(queue)
            
            totalSum = 0
            
            for _ in range(size):
                
                # pop one node from traversal queue
                node = queue.popleft()
                
                # accumulate sum of current level
                totalSum += node.val
                
                # add left child if it exists
                if node.left:
                    queue.append(node.left)
                    
                # add right child if it exists
                if node.right:
                    queue.append(node.right)
            
            # add current level's average value to list
            average_of_level.append(totalSum/size)
        
        return average_of_level
```

### Using Normal Queue
Code:
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        if not root:
            return []
        
        traversal_q = [root]
        average = []
        
        while traversal_q:
            # Compute Average
            cur_avg = sum(node.val for node in traversal_q if node) / len(traversal_q)
            
            # add to result
            average.append(cur_avg)
            
            #update next level queue
            next_level_q = [child for node in traversal_q for child in (node.left, node.right) if child]
            
            #update traversal queue as next_queue
            traversal_q = next_level_q
            
        return average
```
