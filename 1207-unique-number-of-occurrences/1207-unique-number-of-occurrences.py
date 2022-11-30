class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        count = Counter(arr)
        print(count)
        x = list()
        
        for key, val in count.items():
            if val in x:
                return False
            x.append(val)
        return True