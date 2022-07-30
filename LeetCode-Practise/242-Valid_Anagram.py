class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        dict1 = {}
        dict2 = {}
        if len(s) == len(t) and set(s)==set(t):
            for element in set(s):
                dict1[element] = s.count(element)
                dict2[element] = t.count(element)
            if dict1 == dict2:
                return True
            return False
        return False
