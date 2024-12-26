class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        # using python itertator map
        totalSum = sum(nums)
        d = defaultdict(int)
        d[0] = 1
        
        for num in nums:
            dp = defaultdict(int)
            for k, v in d.items():
                dp[k+num] += v
                dp[k-num] += v
            d = dp
        return d[target] if target in d else 0
        
        
        # space optimised 1D DP Sol
        totalSum = sum(nums)
        dp = [0]*(2*totalSum+1)
        
        # init first row
        dp[nums[0] + totalSum] = 1
        dp[-nums[0] + totalSum] += 1
        
        # fill the dp table
        for index in range(1, len(nums)):
            nextDp = [0]*(2*totalSum+1)
            for sumVal in range(-totalSum, totalSum+1):
                if dp[sumVal + totalSum]>0:
                    nextDp[sumVal+totalSum + nums[index]] += dp[sumVal + totalSum]
                    nextDp[sumVal+totalSum - nums[index]] += dp[sumVal + totalSum]
            dp = nextDp
            
                    
                    
        # return res if target in valid range
        return (0 if abs(target) > totalSum 
                else dp[target+totalSum]
               )