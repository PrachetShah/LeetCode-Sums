The product of elements except the ith one is equal to a product of elements on the left side and on the right side of that element. So the idea is to do two passes over the input nums and use an auxiliary list res to store intermediate results. First pass we do from the start to the end and on each iteration we store the accumulated product in the res at the according index such that the value of the res at the ith index equal to product of all elements in nums starting from 0 to i-1, i.e: res[i] = product(nums[0:i-1]). The second pass we do from the end to the start of the nums. We again accumulate a product of met elements and modify the res such that the value at the index i is equal to the product of the value at this index and accumulated value from the pass. In the end, the res is the required answer.

Time: O(n) for two passes over nums

Space: O(1) since the result doesn't count against the space complexity

```
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        res = []
        
        acc = 1
        for n in nums:
            res.append(acc)
            acc *= n

        acc = 1
        for i in reversed(range(len(nums))):
            res[i] *= acc
            acc *= nums[i]
            
        return res
```
