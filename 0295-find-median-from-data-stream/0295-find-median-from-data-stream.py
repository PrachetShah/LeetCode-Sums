class MedianFinder:

    def __init__(self):
        self.s = [float("inf")]
        self.l = [float("inf")]
        self.nS = self.nL = 1
        
    def addNum(self, num: int) -> None:
        if num <= self.l[0]:
            heappush(self.s, -num)
            self.nS += 1
        else:
            heappush(self.l, num)
            self.nL += 1
        if self.nL - self.nS > 1:
            heappush(self.s, -heappop(self.l))
            self.nL -= 1
            self.nS += 1
        elif self.nS - self.nL > 1:
            heappush(self.l, -heappop(self.s))
            self.nL += 1
            self.nS -= 1
            
    def findMedian(self) -> float:
        if self.nS > self.nL: return -self.s[0]
        elif self.nS < self.nL: return self.l[0]
        else: return (-self.s[0] + self.l[0]) / 2
        


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()