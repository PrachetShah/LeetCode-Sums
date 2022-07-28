# Solution 1
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if target in nums:
            return nums.index(target)
        else:
            return -1

# Solution 2
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        low, high = 0, len(nums)-1
        while(low <= high):
            mid = (low + (high-low)//2)
            if target == nums[mid]:
                return mid
            elif target > nums[mid]:
                low = mid + 1
            else:
                high = mid - 1
        return -1
