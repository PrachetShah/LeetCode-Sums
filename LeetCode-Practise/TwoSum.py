class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        result = {}
        for index, value in enumerate(nums):
            difference = target - value
            if difference in result:
                return [result[difference], index]      
            result[value] = index
            
            
'''
Runtime: 95 ms, faster than 65.04% of Python3 online submissions for Two Sum.
Memory Usage: 15.1 MB, less than 50.46% of Python3 online submissions for Two Sum.
'''
