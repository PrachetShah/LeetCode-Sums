# My Solution
from collections import OrderedDict
class Solution:
    def firstUniqChar(self, s: str) -> int:
        od = OrderedDict()
        for char in s:
            if char in od:
                od[char] += 1
            else:
                od[char] = 0
        for key, value in od.items():
            if value == 0:
                return s.index(key)
        return -1
      
# Given Solution
class Solution:
    def firstUniqChar(self, s: str) -> int:
        """
        :type s: str
        :rtype: int
        """
        # build hash map : character and how often it appears
        count = collections.Counter(s)
        
        # find the index
        for idx, ch in enumerate(s):
            if count[ch] == 1:
                return idx     
        return -1
