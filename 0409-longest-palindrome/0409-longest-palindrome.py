class Solution:
    def longestPalindrome(self, s: str) -> int:
        dictt = set()
        for char in s:
            if char not in dictt:
                dictt.add(char)
            else:
                dictt.remove(char)
        if len(dictt) != 0:
            return len(s) - len(dictt) + 1
        return len(s)