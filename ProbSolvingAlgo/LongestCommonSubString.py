# length of longest common substring using Dynamic Programming

def longestCommonSubstr(a,b,n,m):
  #create matrix with n+1 rows and m+1 columns
  T = [[0 for i in range(m+1)] for i in range(n+1)]
  maxi = 0
  for i in range(1,n+1):
      for j in range(1,m+1):
          if a[i-1] == b[j-1]:
              T[i][j] = T[i-1][j-1] +1
              if T[i][j] > maxi:
                  maxi = T[i][j]
  return maxi
  
a = input()
b = input()
n = a.length
m = b.length

x = longestCommonSubstr(a,b,n,m)
print(x)
