class Solution:
    def mergeSimilarItems(self, items1: List[List[int]], items2: List[List[int]]) -> List[List[int]]:
        dictt = {}
        for item in items1:
            dictt[item[0]] = item[1]
        for item in items2:
            if item[0] in dictt:
                dictt[item[0]] += item[1]
            else:
                dictt[item[0]] = item[1]

        result = []
        for key in sorted(dictt.keys()):
            result.append([key, dictt[key]])
        return result
