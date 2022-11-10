class Solution:
    def removeDuplicates(self, s: str) -> str:
        stack = [s[0]]
        i = 1
        while i < len(s):
            if stack and stack[-1] == s[i]:
                stack.pop(-1)
            else:
                stack.append(s[i])
            i += 1
        return ''.join(stack)

    
# Not Accepted Solution(TLE)
# class Solution:
#     def removeDuplicates(self, s: str) -> str:
#         s = list(s)
#         while len(s)!=0:
#             flag = False
#             for i in range(0, len(s)-1):
#                 if s[i] == s[i+1]:
#                     s.pop(i)
#                     s.pop(i)
#                     flag = True
#                     break
#             if flag == False:
#                 break
#         return ''.join(s)
