class Solution:
    def maximumUnits(self, boxTypes: List[List[int]], truckSize: int) -> int:
        boxes = sorted(boxTypes, key=lambda items: items[1], reverse=True)
        ans = 0
        curr = 0
        for box in boxes:
            if curr + box[0] > truckSize:
                ans += (truckSize-curr)*box[1]
                return ans
            else:
                ans += box[0]*box[1]
                curr += box[0]
        return ans
        return 0