`
class Solution(object):
    def duplicateZeros(self, arr):
        n = len(arr)
        cntZero = arr.count(0)
        newLen = n + cntZero # Length of new array if we don't trim up to length `n`
        
        # Let's copy values from the end
        i = n - 1
        j = newLen - 1
        while j >= 0:
            if j < n: arr[j] = arr[i]
            j -= 1
            if arr[i] == 0: # Copy twice if arr[i] == 0
                if j < n: arr[j] = arr[i]
                j -= 1
            i -= 1
`
