# Solution 1: https://leetcode.com/problems/poor-pigs/discuss/2386378/python-binary-(kill-mosquitoes-instead-of-pigs)
# Solution 2: https://leetcode.com/problems/poor-pigs/discuss/935581/C%2B%2BPythonPicture-1-line-greedy-solution-with-N-dimension-puzzle-cube-scan
class Solution:
    def poorPigs(self, buckets: int, minutesToDie: int, minutesToTest: int) -> int:
        return ceil(log(buckets) / log(minutesToTest / minutesToDie + 1))
