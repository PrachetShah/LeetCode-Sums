class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # Using O(n) time and O(n) space
#         val = nums[-1]
#         a = [0]*len(nums)
#         for i in range(len(nums)):
#             a[(i+k)%len(nums)] = nums[i]
        
#         for i in range(len(nums)):
#             nums[i] = a[i]
        
        # Using Cyclic Replacements
#         k = k % len(nums)
#         count, start = 0, 0
#         while count < len(nums):
#             current = start
#             prev = nums[start]
            
#             while True:
#                 next = (current+k)%len(nums)
#                 temp = nums[next]
#                 nums[next] = prev
#                 prev = temp
#                 current = next
#                 count += 1
                
#                 if start == current:
#                     break
#             start += 1
            
        # Using Reverse
        k %= len(nums)
        self.reverse(nums, 0, len(nums)-1)
        self.reverse(nums, 0, k-1)
        self.reverse(nums, k ,len(nums)-1)
    
    def reverse(self, nums, start, end) -> None:
        while start < end:
            nums[start], nums[end] = nums[end], nums[start]
            start += 1
            end -= 1
        
        
        