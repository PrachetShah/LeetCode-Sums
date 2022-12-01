class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        n = len(s)
        a,b = s[:n//2], s[n//2:]
        # print(a,  b)
        
        vowels = ('aeiouAEIOU')
        c1, c2 = 0, 0
        for i in range(n//2):
            if a[i] in vowels:
                c1 += 1
            if b[i] in vowels:
                c2 += 1
        return c1 == c2