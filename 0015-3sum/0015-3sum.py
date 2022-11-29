class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        result = set()
        p, n , z = [], [], []
        for num in nums:
            if num > 0:
                p.append(num)
            elif num < 0:
                n.append(num)
            else:
                z.append(0)
        
        # Checking if 3 zeroes exist
        if z.count(0)>=3:
            result.add((0,0,0))
          
        # if zero exists check if there exists a complement
        P, N = set(p), set(n)
        if z:
            for num in P:
                if -num in N:
                    result.add((-num, 0, num))
                    
        # for all negative nums, check if positive num exists
        for i in range(len(n)):
            for j in range(i+1, len(n)):
                target = -(n[i]+n[j])
                if target in P:
                    result.add(tuple(sorted([n[i], n[j], target])))
        
        # for all positive nums, check if negative num exists
        for i in range(len(p)):
            for j in range(i+1, len(p)):
                target = -(p[i]+p[j])
                if target in N:
                    result.add(tuple(sorted([p[i], p[j], target])))
                    
        return result