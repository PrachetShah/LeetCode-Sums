class Solution:
    def reverseVowels(self, s: str) -> str:
        left, right = 0, len(s)-1
        s = list(s)
        val = ['a', 'e', 'i', 'o', 'u','A', 'E', 'O', 'I', 'U']
        
        while left < right:
            while left < len(s) and (s[left] not in val):
                left += 1
            
            while right >=0 and s[right] not in val:
                right -= 1
            
            if left < right:
                s[left], s[right] = s[right], s[left]
                left += 1
                right -= 1

        return ''.join(char for char in s)