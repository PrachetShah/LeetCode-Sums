- Time complexity: O(NlogN)

Sort the list according to the distance to origin. Apparently, we did more than the question asked. We sorted all the distance, the question only ask for top k. 
To improve time complexity, we need to think about how to get we ask without extra effort. This is where heap data structure comes in.
```
class Solution:
    def kClosest(self, points: List[List[int]], K: int) -> List[List[int]]:
        points.sort(key = lambda P:P[0]**2+P[1]**2)
        return points[:K]
```
- Time complexity: O(nlogn), intuitively use minimum Heap:
1. make a maximum-heap to store distance, (point's distance to original, point)
2. each time call heapq.heappop (distance), it will pop the smallest item in the heap. So heappop K times will be the result.

```
import heapq
class Solution:
    def kClosest(self, points: List[List[int]], K: int) -> List[List[int]]:
        distance = []
        for i in points:
            heapq.heappush(distance,(i[0]**2+i[1]**2,i))
        K_points = []
        for i in range(K):
            K_points.append(heapq.heappop(distance)[1])
        return K_points
```
- Time compiexity: O(NlogK)
Since python3 doesn't have a build-in maximum heap, so I use the minimum heap to achieve maximum heap's property as shown above. Here, we keep a heap 
with size of K. So we can improve the time complexity to O(NlogK).
```
import heapq
class Solution:
    def kClosest(self, points: List[List[int]], K: int) -> List[List[int]]:
        distance = []
        for p in points:
            if len(distance) <= K-1:
                heapq.heappush(distance,(-p[0]**2-p[1]**2,p))
            else:
                if -p[0]**2-p[1]**2 > distance[0][0]:
                    heapq.heappop(distance)
                    heapq.heappush(distance,(-p[0]**2-p[1]**2,p))
        res = []
        for i in range (K):
            res.append(heapq.heappop(distance)[1])
        return res
```
