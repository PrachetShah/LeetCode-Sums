class Solution:
    def subarraysDivByK(self, A: List[int], K: int) -> int:
        result,running_sum = 0,0
        mod_array = [1] + [0]*K
        for i in range(len(A)):
            running_sum+=A[i]
            result+=mod_array[running_sum%K]
            mod_array[running_sum%K]+=1
        return result
        