class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead
        """
        zero, one, two = nums.count(0), nums.count(1), nums.count(2)
        index = 0
        for i in range(zero):
            nums[index] = 0
            index += 1
        for i in range(one):
            nums[index] = 1
            index += 1
        for i in range(two):
            nums[index] = 2
            index += 1
