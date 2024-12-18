class Solution:
    def finalPrices(self, prices: List[int]) -> List[int]:
        result = prices.copy()
        stack = []
        
        for i in range(len(prices)):
            while stack and prices[stack[-1]] >= prices[i]:
                result[stack.pop()] -= prices[i]
            stack.append(i)
        return result
        