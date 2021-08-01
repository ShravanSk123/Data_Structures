
# Using two stacks and a leftToRight variable

def zigzagLevelOrder(self, root):
    if root is None:
        return
    ans = [] # [[ins]] -> separates the levels
    ins = [] # inside list [ins]
    currentLevel = [] #stack 1
    nextLevel = [] #stack 2
    ltr = True

    currentLevel.append(root)

    # Check if stack is empty
    while len(currentLevel) > 0:
        temp = currentLevel.pop(-1)
        ins.append(temp.val)
        if ltr:
            if temp.left:
                nextLevel.append(temp.left)
            if temp.right:
                nextLevel.append(temp.right)
        else:
            if temp.right:
                nextLevel.append(temp.right)
            if temp.left:
                nextLevel.append(temp.left)

        if len(currentLevel) == 0:
            ans.append(ins)
            ins = []
            ltr = not ltr
            currentLevel, nextLevel = nextLevel, currentLevel
    return ans
