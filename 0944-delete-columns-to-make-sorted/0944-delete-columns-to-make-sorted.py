class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        cols = len(strs[0])
        ans = 0
        for i in range(cols):
            # order = ord('a')
            for j in range(1, len(strs)):
                if ord(strs[j-1][i]) > ord(strs[j][i]):
                    ans += 1
                    break
                # else:
                #     order = ord(strs[j][i])
        # print(ans)
        return ans