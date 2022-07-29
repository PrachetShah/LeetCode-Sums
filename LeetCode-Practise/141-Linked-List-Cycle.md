- Took 88 ms and the "Accepted Solutions Runtime Distribution" doesn't show any faster Python submissions. 
The "trick" is to not check all the time whether we have reached the end but to handle it via an exception. 
"Easier to ask for forgiveness than permission."

The algorithm is of course Tortoise and hare.
```
def hasCycle(self, head):
    try:
        slow = head
        fast = head.next
        while slow is not fast:
            slow = slow.next
            fast = fast.next.next
        return True
    except:
        return False
```

## My Code:
- Using Dictionary/HashMap
```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        root = head
        seen = {}
        while root:
            if root in seen:
                return True
            else:
                seen[root] = True
            root = root.next
        return False
```
