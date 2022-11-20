class Solution:
    def calculate(self, s):
        sign = 1
        i = res = num = 0
        stack = []
        
        while i < len(s):
            if s[i].isnumeric(): num = num * 10 + int(s[i]) # form number from digits
            elif s[i] in ['+', '-']: # when met with an operator
                res += num * sign # add the previous number to the result using the correct sign
                sign = 1 if s[i] == '+' else -1 # reset the sign for the next number
                num = 0 # reset the number
            elif s[i] == '(':
                stack.append(res) # append the current res to stack
                stack.append(sign) # append the sign for the number to be calculated within parenthesis eg: to store the minus in the equation res - (some new result)
                res = num = 0
                sign = 1
            elif s[i] == ')':
                res = (sign * num + res) * stack.pop() + stack.pop() # form new result by multiplying current res with last sign stored in stack and adding it to the last result stored in stack
                sign = 1
                num = 0
            
            i += 1
            
        return num * sign + res