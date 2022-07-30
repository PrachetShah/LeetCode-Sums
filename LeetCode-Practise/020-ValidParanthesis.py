class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        dictt={"(":")","{":"}","[":"]"}
        for i in s:
            if i in dictt:
                stack.append(i)
            elif stack==[] or dictt[stack.pop()]!=i:
                return False
        return stack==[]
'''
1. if it's the left bracket then we append it to the stack
2. else if it's the right bracket and the stack is empty(meaning no matching left bracket), or the left bracket doesn't match
3. finally check if the stack still contains unmatched left bracket
'''
