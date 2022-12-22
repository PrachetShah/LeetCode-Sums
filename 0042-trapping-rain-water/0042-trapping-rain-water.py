class Solution:
    def trap(self, height: List[int]) -> int:
        H = height
        N = len(H)
		
        i = 0
        j = N-1
        left_max = right_max = water = 0
		
        while i <= j:
            left_max = max(left_max, H[i])
            right_max = max(right_max, H[j])
            if left_max < right_max:
                water += left_max - H[i]
                i += 1
            else:
                water += right_max - H[j]
                j -= 1
		
        return water