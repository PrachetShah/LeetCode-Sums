class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        max_so_far = -inf
        max_ending = -inf
        for num in nums:
            max_ending = max(max_ending + num, num)
            max_so_far = max(max_so_far, max_ending)
        return max_so_far
        