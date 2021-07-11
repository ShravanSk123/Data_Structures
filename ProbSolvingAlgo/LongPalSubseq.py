def longestPalindromicSubSeq(s):
    n = len(s)
 
    # Create a table to store results of subproblems
    L = [[0 for x in range(n)] for x in range(n)]
 
    # Strings of length 1 are palindrome of length 1
    for i in range(n):
        L[i][i] = 1
        
    # cl is length of substring
    for k in range(2, n+1):
        for i in range(n-k+1):
            j = i+k-1
            if s[i] == s[j] and k == 2:
                L[i][j] = 2
            elif s[i] == s[j]:
                L[i][j] = L[i+1][j-1] + 2
            else:
                L[i][j] = max(L[i][j-1], L[i+1][j]);
 
    return L[0][n-1]

x = input()
n = len(x)
print("The length of the Longest Palindromic Subsequence is " + str(longestPalindromicSubSeq(x)))
