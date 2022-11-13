class Solution:
    def reverseWords(self, s: str) -> str:
        s = s.strip()
        s = s.split()
        output = ''
        for char in s[::-1]:
            output += char.strip()
            output += ' '
        return output.strip()