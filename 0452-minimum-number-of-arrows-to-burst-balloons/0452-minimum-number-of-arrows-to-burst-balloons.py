class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points.sort(key=lambda x: x[1])
        ans, arrow = 0, 0
        for [start, end] in points:
            if ans==0 or start>arrow:
                ans, arrow = ans+1, end
        return ans