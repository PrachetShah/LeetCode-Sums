#### Explanation with all types of algos: Check before reading [Link](https://leetcode.com/problems/squares-of-a-sorted-array/discuss/310865/Python%3A-A-comparison-of-lots-of-approaches!-Sorting-two-pointers-deque-iterator-generator)

### Really Bad Solution: Uses O(nlogn)
```
class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        # Using new array instead of in-place operations
        # seq = [i**2 for i in nums]
        # seq.sort()
        # return seq
        
        # Using in-place operations
        for i in range(len(nums)):
            nums[i] = nums[i]**2
        nums.sort()
        return nums
```

