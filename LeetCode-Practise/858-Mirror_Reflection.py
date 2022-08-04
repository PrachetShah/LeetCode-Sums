# Explanation: https://leetcode.com/problems/mirror-reflection/discuss/2376191/C%2B%2B-Java-Python-or-Faster-then-100-or-Full-explanations-or

class Solution:
    def mirrorReflection(self, p: int, q: int) -> int:
        while p % 2 == 0 and q % 2 == 0: 
            p, q = p / 2, q / 2
        return int(1 - p % 2 + q % 2)
