### My First Solution
```
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        counter = {}
        for char in set(magazine):
            counter[char] = magazine.count(char)
        
        for char in set(ransomNote):
            if char not in counter:
                return False
            if ransomNote.count(char) > counter[char]:
                return False
        return True
```

### Better and Efficient based on previous
```
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        for char in set(ransomNote):
            if ransomNote.count(char) > magazine.count(char):
                return False
        return True
```
