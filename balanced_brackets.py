def checkBalanced(exp):
### Implement your code here
    open = ['[','{','(']
    close = [']','}',')']

    stack = []

    for i in range(len(exp)):
        if(exp[i] in open):
            stack.append(exp[i])
        elif(exp[i] in close):
            for j in range(len(close)):
                if(exp[i] == close[j]):
                    break
            if(stack[-1] == open[j]):
                stack.pop(-1)
            else:
                return False
                
    if(len(stack) == 0):
        return True
    else:
        return False

exp=input()
if checkBalanced(exp):
    print('true')
else:
    print('false')
