class Solution:
    def solve(self, digits, output, index, ans, mapping):
        if index >= len(digits):
            ans.append(output)
            return
        
        num = int(digits[index])
        val = mapping[num]
        for i in range(len(val)):
            output += val[i]
            self.solve(digits, output, index+1, ans, mapping)
            output = output[:-1]
        
    def letterCombinations(self, digits: str) -> List[str]:
        ans = []
        output = ""
        if(len(digits) == 0):
            return []
        
        mapping = ["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
        index= 0
        self.solve(digits, output, index, ans, mapping)
        return ans