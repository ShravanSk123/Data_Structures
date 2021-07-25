# given two sorted arrays merge them such that whole array is sorted
# two pointer approach

def mergeSortedArr(nums1, nums2):
    m = len(nums1)
    n = len(nums2)
    
    i = m-1
    j = n-1
    k = m+n-1
    
    while (i>=0) and (j>=0):
        if nums1[i]>nums2[j]:
            nums1[k] = nums1[i]
            k-=1
            i-=1
        else:
            nums1[k] = nums2[j]
            k-=1
            j-=1
    
    while (i>=0):
        nums1[k] = nums1[i]
        k-=1
        i-=1
    while (j>=0):
        nums1[k] = nums2[j]
        k-=1
        j-=1 
    return nums1

# time complexity is O(m+n)
# space complexity is O(1)
