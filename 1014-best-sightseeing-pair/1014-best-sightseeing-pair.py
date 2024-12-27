class Solution:
    def maxScoreSightseeingPair(self, values: List[int]) -> int:
        n = len(values)
        maxLeftScore = values[0]
        maxScore = 0
        
        for i in range(1, n):
            currentRightScore = values[i] - i
            maxScore = max(maxScore, maxLeftScore+currentRightScore)
            
            currLeft = values[i] + i
            maxLeftScore = max(maxLeftScore, currLeft)
        return maxScore