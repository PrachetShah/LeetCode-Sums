class MyQueue:

    def __init__(self):
        self.queue = []
        self.index = 0

    def push(self, x: int) -> None:
        self.queue.append(x)

    def pop(self) -> int:
        self.index += 1
        return self.queue[self.index-1]

    def peek(self) -> int:
        return self.queue[self.index]

    def empty(self) -> bool:
        return self.index >= len(self.queue)


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()