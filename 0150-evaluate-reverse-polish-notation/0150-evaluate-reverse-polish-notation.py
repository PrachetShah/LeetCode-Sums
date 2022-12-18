class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        operators= ["+", "-", "*", "/"]
        stack = []
        # stack.append(tokens[0])
        for token in tokens:
            if token not in operators:
                stack.append(token)
            else:
                val1 = int(stack.pop())
                val2 = int(stack.pop())
                if token == "+":
                    stack.append(val1+val2)
                if token == "-":
                    stack.append(val2-val1)
                if token == "*":
                    stack.append(val1*val2)
                if token == "/":
                    if val2/val1<0:
                        stack.append(math.ceil(val2/val1))
                    else:
                        stack.append(math.floor(val2/val1))
        #         print(stack)
        # print(stack)
        return int(stack[-1])