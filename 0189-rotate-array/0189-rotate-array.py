class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # Using O(n) time and O(n) space
        val = nums[-1]
        a = [0]*len(nums)
        for i in range(len(nums)):
            a[(i+k)%len(nums)] = nums[i]
        
        for i in range(len(nums)):
            nums[i] = a[i]