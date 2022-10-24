class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        out = set()
        for num in nums1:
            if num in nums2:
                out.add(num)
        return out