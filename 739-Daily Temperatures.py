class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        s, days = [], [0]*len(temperatures)
        
        for i, t in enumerate(temperatures):
            while s and t > temperatures[s[-1]]:
                days[s.pop()] = i - s[-1]
            s.append(i)
        return days
