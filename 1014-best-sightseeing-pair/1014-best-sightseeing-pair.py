class Solution:
    def maxScoreSightseeingPair(self, values: List[int]) -> int:
        n = len(values)
        maxLeftScore = [0]*n
        maxLeftScore[0] = values[0]
        maxScore = 0
        
        for i in range(1, n):
            currentRightScore = values[i] - i
            maxScore = max(maxScore, maxLeftScore[i-1]+currentRightScore)
            
            currLeft = values[i] + i
            maxLeftScore[i] = max(maxLeftScore[i-1], currLeft)
        return maxScore