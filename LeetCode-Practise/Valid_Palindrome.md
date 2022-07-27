Solution 1 (2 Lines)
```
class Solution:
    def isPalindrome(self, s: str) -> bool:
    	s = [i for i in s.lower() if i.isalnum()]
    	return s == s[::-1]
```
Solution 2: O(1) space (two-pointer)
```
class Solution:
    def isPalindrome(self, s: str) -> bool:
        word = ''.join(ch for ch in s if ch.isalnum())
        i = 0
        j = len(word) - 1

        while i < j:
            a, b = word[i].lower(), word[j].lower()
            
            if a.isalnum() and b.isalnum():
                if a != b:
                    return False
                else:
                    i += 1
                    j -= 1
            i, j = i + (not a.isalnum()), j - (not b.isalnum())
        return True
```
