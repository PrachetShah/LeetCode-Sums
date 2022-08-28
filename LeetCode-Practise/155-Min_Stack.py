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
