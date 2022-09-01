# Good Explanation: https://leetcode.com/problems/build-array-from-permutation/discuss/1692310/Easy-explanation-for-O(1)-space-complexity
# Code:
class Solution:
    def buildArray(self, nums: List[int]) -> List[int]:
        n = len(nums)
        for i in range(n):
            nums[i] = nums[i] + n*(nums[nums[i]]%n)
        for i in range(n):
            nums[i] = nums[i]//n
        return nums
