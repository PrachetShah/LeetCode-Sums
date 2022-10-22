class Solution:
    def isValid(self, s: str) -> bool:
        valid = {"(":")", "{":"}", "[":"]"}
        check = []
        for char in s:
            if char in valid:
                check.append(char)
            elif len(check)==0 or valid[check.pop()] != char:
                return False
        return len(check) == 0