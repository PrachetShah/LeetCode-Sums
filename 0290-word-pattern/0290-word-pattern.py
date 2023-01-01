class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        n = len(pattern)
        words = s.split(' ')
        sim = {}
        if len(words) != n:
            return False
        if len(set(words)) != len(set(pattern)):
            return False
        for i in range(len(pattern)):
            if pattern[i] in sim.keys():
                if sim[pattern[i]] != words[i]:
                    return False
            else:
                sim[pattern[i]] = words[i]
        print(sim)
        return True