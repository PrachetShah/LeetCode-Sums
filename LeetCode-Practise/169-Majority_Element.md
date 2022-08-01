### Approach: HashMap
```
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        counts = collections.Counter(nums)
        return max(counts.keys(), key=counts.get)
```
- Time complexity : O(n)
<br>We iterate over nums once and make a constant time HashMap insertion on each iteration. Therefore, the algorithm runs in O(n) time.

- Space complexity : O(n)
### Approach: Sorting
```
class Solution:
    def majorityElement(self, nums):
        nums.sort()
        return nums[len(nums)//2]
```
- Time complexity : O(nlgn)
<br>Sorting the array costs O(nlgn)time in Python and Java, so it dominates the overall runtime.

- Space complexity : O(1) or (O(n)

### Approach: Boyer-Moore Voting Algorithm
```
class Solution:
    def majorityElement(self, nums):
        count = 0
        candidate = None

        for num in nums:
            if count == 0:
                candidate = num
            count += (1 if num == candidate else -1)

        return candidate
```
- Time complexity : O(n)
<br>Boyer-Moore performs constant work exactly nn times, so the algorithm runs in linear time.

- Space complexity : O(1)
<br>Boyer-Moore allocates only constant additional memory.



