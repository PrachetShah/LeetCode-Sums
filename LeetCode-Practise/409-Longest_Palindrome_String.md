## GFG has 2 articles explaining 3 algorithms for it which explains LONGEST PALINDROME IN SUBSTRING
1. Using Brute Force
2. Using DP with O(n^2) Space
3. Using DP with O(1) Space

- Links: 
1. [Set 1](https://www.geeksforgeeks.org/longest-palindrome-substring-set-1/)
2. [Set 2](https://www.geeksforgeeks.org/longest-palindromic-substring-set-2/)

## My Solutions: (LEETCODE HAS LONGEST PALINDROME) not in SUBSTRING, any string can be considered here
#### Idea:
Start adding letters to a set. If a given letter not in the set, add it. If the given letter is already in the set, remove it from the set.
If the set isn't empty, you need to return length of the string minus length of the set plus 1.
Otherwise, you return the length of the string (example 'bb.' Your set is empty, you just return 2).
<br>
Essentially, your set contains non-paired letters. It's one of those bad questions where you need to go over all possible cases and somehow fit them into the solution.
```
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
```
