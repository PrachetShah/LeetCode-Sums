class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        if arr.count(0)>1:
            return True
        seen = set(arr) - {0}
        for ele in arr:
            if ele*2 in seen:
                return True
        return False
