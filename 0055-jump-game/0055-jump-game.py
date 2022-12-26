class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n = len(nums)
        maxPos = 0
        i = 0
        while i <= maxPos:
            maxPos = max(maxPos, i + nums[i])
            if maxPos >= n - 1: return True
            i += 1
        
        return False