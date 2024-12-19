class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        n = len(arr)
        chunks = 0
        prefixSum = 0
        sortedPrefixSum = 0
        
        for i in range(n):
            prefixSum += arr[i]
            sortedPrefixSum += i
        
            if prefixSum == sortedPrefixSum:
                chunks += 1
        return chunks