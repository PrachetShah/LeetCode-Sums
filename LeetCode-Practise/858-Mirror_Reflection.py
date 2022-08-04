# Explanation: https://leetcode.com/problems/mirror-reflection/discuss/2376191/C%2B%2B-Java-Python-or-Faster-then-100-or-Full-explanations-or
# Explanation2: https://leetcode.com/problems/mirror-reflection/discuss/2376176/C%2B%2Boror-JAVA-oror-PYTHON-oror100-Faster-Solution-Explained

class Solution:
    def mirrorReflection(self, p: int, q: int) -> int:
        while p % 2 == 0 and q % 2 == 0: 
            p, q = p / 2, q / 2
        return int(1 - p % 2 + q % 2)
