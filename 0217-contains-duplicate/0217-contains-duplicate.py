class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        data = {}
        data = defaultdict(bool)
        for num in nums:
            if data[num]:
                return True
            data[num] = True
        return False