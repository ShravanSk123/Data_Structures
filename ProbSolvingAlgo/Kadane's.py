#max sum in subarray
#Kadane's algorithm

def Kadane(a):
    maxsum = 0 # initialize it with ( -infinity ) if array contains all negative numbers / return max 
    cursum = 0
    l = len(a)
    for i in range(0,l):
        cursum += a[i]
        if cursum > maxsum:
            maxsum = cursum
        if cursum < 0:
            cursum = 0
    return maxsum

#main
a = list(map(int, input().split()))
x = Kadane(a)
print(x)
