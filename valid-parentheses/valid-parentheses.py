class Solution:
    def isValid(self, s: str) -> bool:
        check = {
            "{":"}",
            "(":")",
            "[":"]"
        }
        stack = []
        for char in s:
            if char in '({[':
                stack.append(char)
            else:
                if not stack or char != check[stack.pop()]:
                    return False
        return len(stack)==0
                    