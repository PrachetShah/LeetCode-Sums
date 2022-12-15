class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        n = len(nums)
        total = n*(n+1)//2
        val = total - sum(nums)
        missing = total - sum(set(nums))
        return (missing-val)//(len(nums)-len(set(nums)))