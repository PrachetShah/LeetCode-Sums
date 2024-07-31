class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        nSum = (n*(n+1))//2
        return nSum - sum(nums)