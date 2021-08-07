# Find next greater element in the array
# InOrder using Stack
# problem statement -- https://www.geeksforgeeks.org/next-greater-element/

def nextGreaterElement(arr,n):
    s = [] # stack

    ans = [0 for i in range(n)] # stores next greater elements in order

    for i in range(n - 1, -1, -1):
        while (len(s) > 0 and s[-1] <= arr[i]):
            s.pop()

        if (len(s) == 0): # if stack is empty, greater element doesn't exist
            ans[i] = -1       
        else:
            ans[i] = s[-1] # s[-1] is top of stack

        s.append(arr[i])
    return ans

# Time complexity is O(n)
