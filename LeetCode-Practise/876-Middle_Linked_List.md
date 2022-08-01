#### Approach 1: Output to Array
Intuition and Algorithm

Put every node into an array ```A``` in order. Then the middle node is just ```A[A.length // 2]```, since we can retrieve each node by index.
<br>We can initialize the array to be of length ```100```, as we're told in the problem description that the input contains between ```1``` and ```100``` nodes.
```
class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        arr = [head]
        while arr[-1].next:
            arr.append(arr[-1].next)
        return arr[len(arr) // 2]
```
Complexity Analysis

- Time Complexity: O(N), where NN is the number of nodes in the given list.

- Space Complexity: O(N), the space used by A.

#### Approach 2: Fast and Slow Pointer
Intuition and Algorithm

When traversing the list with a pointer ```slow```, make another pointer fast that traverses twice as ```fast```. 
When fast reaches the end of the list, ```slow``` must be in the middle.
```
class Solution:
    def middleNode(self, head):
        slow = fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        return slow
```
Complexity Analysis

- Time Complexity: O(N), where N is the number of nodes in the given list.

- Space Complexity: O(1), the space used by `slow` and `fast`.
