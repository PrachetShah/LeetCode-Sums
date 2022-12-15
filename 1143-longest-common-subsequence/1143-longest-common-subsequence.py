class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        output = [[0 for _ in range(len(text1)+1)] for _ in range(len(text2)+1)]
        print(len(output),len(output[0]))
        for i in range(1, len(text2)+1):
            for j in range(1, len(text1)+1):
                if(text2[i-1]==text1[j-1]):
                    output[i][j] = 1 + output[i-1][j-1]
                else:
                    output[i][j] = max(output[i-1][j], output[i][j-1])
        return output[-1][-1]