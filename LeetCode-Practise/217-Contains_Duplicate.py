class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        data = {}
        for num in nums:
            if num in data:
                return True
            data[num] = num
        return False
