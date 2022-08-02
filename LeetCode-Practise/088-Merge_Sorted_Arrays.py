class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        a, b, write_index = m-1, n-1, m+n-1
        
        while b>=0:
            if a>=0 and nums1[a] > nums2[b]:
                nums1[write_index] = nums1[a]
                a -= 1
            else:
                nums1[write_index] = nums2[b]
                b -= 1
            write_index -= 1
        
