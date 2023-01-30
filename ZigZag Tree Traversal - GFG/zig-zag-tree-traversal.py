class Solution:
    #Function to store the zig zag order traversal of tree in a list.
    def zigZagTraversal(self, root):
        # Add Your code here
        result, queue = [], []
        if root is None:
            return result
        queue.append(root)
        
        leftToRight = True
        while(queue):
            size = len(queue)
            ansStack = [0 for _ in range(size)]
            
            for i in range(size):
                front = queue.pop(0)
                if leftToRight:
                    index = i
                else:
                    index = size-i-1
                # index = leftToRight ? i : len(queue)-i-1
                ansStack[index] = front.data
                
                if front.left:
                    queue.append(front.left)
                if front.right:
                    queue.append(front.right)
                
            leftToRight = not leftToRight
            for num in ansStack:
                result.append(num)
        return result
