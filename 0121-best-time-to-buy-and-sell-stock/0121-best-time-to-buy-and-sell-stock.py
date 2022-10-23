class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        minProfit = float('inf')
        maxProfit = 0
        for i in range(len(prices)):
            if prices[i] < minProfit:
                minProfit = prices[i]
            elif prices[i] - minProfit > maxProfit:
                maxProfit = prices[i] - minProfit
        return maxProfit