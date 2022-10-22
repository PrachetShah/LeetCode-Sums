class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        result = {}
        for index, value in enumerate(nums):
            difference = target - value
            if difference in result:
                return [result[difference], index]
            result[value] = index
        