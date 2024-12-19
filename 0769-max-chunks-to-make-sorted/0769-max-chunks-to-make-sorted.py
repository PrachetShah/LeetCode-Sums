class Solution:
    def maxChunksToSorted(self, arr: List[int]) -> int:
        n = len(arr)
        prefixMax = arr[:]
        suffixMin = arr[:]
        
        for i in range(1, n):
            prefixMax[i] = max(prefixMax[i], prefixMax[i-1])
        
        for i in range(n-2, -1, -1):
            suffixMin[i] = min(suffixMin[i], suffixMin[i+1])
        
        chunks = 0
        for i in range(n):
            if i==0 or suffixMin[i]>prefixMax[i-1]:
                chunks += 1
        return chunks