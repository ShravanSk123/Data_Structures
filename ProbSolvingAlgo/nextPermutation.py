# finds the next permutation of given number in the form of array
# Ex: [1,5,7] -> [1,7,5]
# [1,3,4,7] -> [1,4,3,7]
# if permuatation is not possible, return lowest possible permutation
# Ex: [3,2,1] -> [1,2,3]

def nextPermutation(N, arr):
  curindex = -1
  for i in range(N-1,0,-1):
      if arr[i] > arr[i-1]: # to identify least significant / rightmost peak
          curindex = i
          break
          
  if curindex == -1: # array is in descending order, sort in ascending order
      arr.reverse()
  else:
      previndex = curindex
      for i in range(curindex,N):
          if (arr[i]>arr[curindex-1]) and (arr[i]<=arr[previndex]):
              previndex = i
              
      arr[curindex-1], arr[previndex] = arr[previndex], arr[curindex-1] # swapping
      arr[curindex:] = arr[curindex:][::-1] # reversing / sort in ascending order the last part of array
      
  return arr

# time complexity is O(n)
# no extra space so space complexity is O(1) 
