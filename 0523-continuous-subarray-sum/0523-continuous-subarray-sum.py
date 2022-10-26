class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        det = {0:0}
        s = 0
        for i in range(len(nums)):
            s += nums[i]
            if s%k not in det:
                det[s%k] = i + 1
            elif det[s%k] < i:
                return True
        return False