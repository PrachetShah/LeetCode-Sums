class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
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