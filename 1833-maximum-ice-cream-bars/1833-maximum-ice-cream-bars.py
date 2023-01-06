class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        if sum(costs) < coins:
            return len(costs)
        if min(costs) > coins:
            return 0
        costs.sort()
        ans = 0
        for cost in costs:
            if cost <= coins:
                ans += 1
                coins -= cost
            else:
                break
        return ans