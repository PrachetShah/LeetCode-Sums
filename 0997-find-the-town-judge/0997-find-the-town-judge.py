class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        data = [0]*(n+1)
        
        for a,b in trust:
            data[a] -= 1
            data[b] += 1
        
        for i in range(1, n+1):
            if data[i]==n-1:
                return i
        return -1