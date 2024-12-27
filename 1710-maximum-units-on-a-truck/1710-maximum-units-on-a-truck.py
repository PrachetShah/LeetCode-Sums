class Solution:
    def maximumUnits(self, boxTypes: List[List[int]], truckSize: int) -> int:
        boxTypes.sort(key=lambda x:-x[1])
        ans = 0
        for box in boxTypes:
            if truckSize > box[0]:
                truckSize -= box[0]
                ans += box[0]*box[1]
            else:
                ans += (truckSize)*box[1]
                return ans
        return ans