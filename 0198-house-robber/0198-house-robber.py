class Solution:
    def rob(self, nums: List[int]) -> int:
        sum1, sum2 = 0, 0
        for i in nums:
            sum1, sum2 = sum2, max(sum1+i, sum2)
        return sum2