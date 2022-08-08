## Idea:
A binary tree level order traversal generally recommends a **breadth first search (BFS)** approach with the use of a **queue data structure**. 
When we process a **node (curr)**, we'll push the node's children onto the end of the **queue** in the order in which we want to traverse 
(in this case, left to right). In this way, we'll have finished putting the next row in the **queue** at the same time we finish iterating through this row.
<br><br>
To help us keep track of the rows, we just nest the main loop inside another loop. At the beginning of the outer loop, we capture the **queue length**, 
which will tell us how long the row is. Then we can iterate through that many nodes, popping them off the **queue's** front one at a time, 
then process any end-of-row instructions. In the case of this problem, that will mean pushing the current row array **(row)** onto our answer array **(ans)**.
<br><br>
We'll continue this process until the **queue is empty**, at which point we will have reached the end of the binary tree, and can return **ans**.
<br><br>
- Time Complexity: O(N) where N is the number of nodes in the binary tree
- Space Complexity: O(N) for our answer array
<br><br>
## Python Code:
```
class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        queue, ans = deque([root] if root else []), []
        while len(queue):
            qlen, row = len(queue), []
            for _ in range(qlen):
                curr = queue.popleft()
                row.append(curr.val)
                if curr.left: queue.append(curr.left)
                if curr.right: queue.append(curr.right)
            ans.append(row)
        return ans
```
