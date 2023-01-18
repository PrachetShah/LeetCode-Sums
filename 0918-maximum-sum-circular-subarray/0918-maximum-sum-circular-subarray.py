class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        if len(nums)==0:
            return 0
        
        maxTotal, maxsoFar, minTotal, minsoFar, s = nums[0], nums[0], nums[0], nums[0], nums[0]
        
        for i in range(1, len(nums)):
            maxsoFar = max(maxsoFar+nums[i], nums[i])
            maxTotal = max(maxTotal, maxsoFar)
        
            minsoFar = min(minsoFar+nums[i], nums[i])
            minTotal = min(minTotal, minsoFar)
            
            s += nums[i]
        if s == minTotal:
            return maxTotal
        return max(s - minTotal, maxTotal)