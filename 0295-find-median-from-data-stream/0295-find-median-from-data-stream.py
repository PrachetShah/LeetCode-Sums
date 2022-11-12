class MedianFinder:
    
    def __init__(self):
        self.lst=[]

    def addNum(self, num: int) -> None:
        self.lst.append(num)
        

    def findMedian(self) -> float:
        k=len(self.lst)
        self.lst.sort()
        if(k%2==0):
           return ((self.lst[k//2]+self.lst[(k-1)//2])/2)
        else:
            return self.lst[k//2]
        


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()