# Minimum coins required to obtain given amount
# using dynamic programming
#problem statement -- https://leetcode.com/problems/coin-change/

int coinChange(int* coins, int coinsSize, int amount){
    
    int dp[coinsSize+1][amount+1];

    for(int i=0;i<=coinsSize;i++)
    {
        for(int j=0;j<=amount;j++)
        {
            if(j==0)
                dp[i][j] = 0;
            else if(i==0)
                dp[i][j] = 1e5; #consider 10^5 as infinite
            else if(coins[i-1]>j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
        }
    }
            
    if(dp[coinsSize][amount]>1e4)
        return -1;
    return dp[coinsSize][amount];
}

#time complexity is O(amt*n)
