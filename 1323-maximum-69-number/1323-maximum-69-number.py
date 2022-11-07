class Solution:
    def maximum69Number (self, num: int) -> int:
        num = list(str(num))
        if '6' not in num:
            return int(''.join(char for char in num))
        rep = num.index('6')
        num[rep] = '9'
        return int(''.join(char for char in num))