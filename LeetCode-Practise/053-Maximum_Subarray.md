My approaches to solve this problem evolved like this:
1. Approach 1: Using 2 for loops
Starting from index i, start adding the numbers and record the maximum sum with all the next elements.
Doing this for every i element (n-i) times will cause time complexity to become **O(n^2).**

2. Approach 2: Let's create another list that can store the maximum of total or nums[i]. Here total = (previous num + nums[i]).
Then to find the maximum of all the sums, we'll have to traverse the list and return the maximum. This was **O(n) time and O(n) space**.

3. Approach 3: In above approach, we stored maximum total until nums[i] and then found the maximum subarray total in the end. 
We aren't doing anything good with the new list because in the end we are traversing the list to find the maximum total. So, 
eliminate creating new list and start tracking the new sum and maximum number. **This becomes O(n) time and O(1) space**

Kadane's Algorithm, more written on leetcode
Perfect Discussion(7 Diff Solutions) : <a href="https://leetcode.com/problems/maximum-subarray/discuss/1595195/C%2B%2BPython-7-Simple-Solutions-w-Explanation-or-Brute-Force-%2B-DP-%2B-Kadane-%2B-Divide-and-Conquer">Link to Discussion</a>
```
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        if len(nums)==1:
            return nums[0]
        newNum = maxNum = nums[0]
        for i in range(1, len(nums)):
            newNum = max(nums[i], newNum + nums[i])
            maxNum = max(newNum, maxNum)
        return maxNum
```
