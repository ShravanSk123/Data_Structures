# return maximum element in every window of size 'k' in  an array
# Time complexity O(n)
# leetcode -- https://leetcode.com/problems/sliding-window-maximum/
def maxSlidingWindow(nums, k):

    n = len(nums)
    max_upto=[0 for i in range(n)]
    s=[] # stack
    s.append(0)
    ans = []
    # similar to next greater element
    for i in range(1,n):
        while (len(s) > 0 and nums[s[-1]] < nums[i]):
            max_upto[s[-1]] = i - 1
            s.pop()
        s.append(i)

    while len(s) > 0:
        max_upto[s[-1]] = n-1
        s.pop()

    j = 0
    for i in range(n - k + 1):
        while (j < i or max_upto[j] < i + k - 1):
            j += 1
        ans.append(nums[j])
    return ans

