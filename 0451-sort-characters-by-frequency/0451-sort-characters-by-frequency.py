class Solution:
    def frequencySort(self, s: str) -> str:
        return ''.join([ch*ct for ch, ct in sorted(Counter(s).items(), key = lambda x: (-x[1], x[0]))])