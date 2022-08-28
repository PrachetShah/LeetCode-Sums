 ## RC ##
## APPROACH : make tuples (x,y) 
# where x is element directly given and y is always minElement i.e y will have minElement in the current existing list ##
        
## TIME COMPLEXITY : O(1) ##
## SPACE COMPLEXITY : O(N) ##
class MinStack:
    def __init__(self):
        self.stack = []
    def push(self, x: int) -> None:
        if self.stack:
            self.stack.append((x, min(x, self.getMin())))
        else:
            self.stack.append((x,x))

    def pop(self) -> None:
        if self.stack:
            self.stack.pop()

    def top(self) -> int:
        return self.stack[-1][0] if self.stack else None

    def getMin(self) -> int:
        return self.stack[-1][1] if self.stack else None

     
     ## USing Linked List
     class Node:
    def __init__(self, val=None, mini=None, next=None):
        # Initialize Node
        self.val = val
        self.minimum = mini
        self.next = next

class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.head = None
        

    def push(self, x: int) -> None:
	# insert at beginning of the list
	# check if head is Null
        if self.head is None:
            node = Node(x, x)
            self.head = node
        else:
		# using min inbuilt function to check for minimum value between the current inserted value and previous minimum value
            node = Node(x, min(x, self.head.minimum), self.head)
            self.head = node
        

    def pop(self) -> None:
	# just change the head pointer to next node
        self.head = self.head.next
        

    def top(self) -> int:
	# returns top of the linked list
        return self.head.val
        

    def getMin(self) -> int:
	# returns minimum value
        return self.head.minimum
