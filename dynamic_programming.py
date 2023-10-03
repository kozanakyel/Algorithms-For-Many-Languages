
def kProfit(W,N,wt,pr,dp):
    # Base Condition
    if N==0 or W==0:
        return 0
    # If sub problem is previously solved tehn return it.
    if dp[N][W] is not None:
        return dp[N][W]
    if wt[N-1] <= W:
        dp[N][W] = max(pr[N-1]+kProfit(W-wt[N-1],N-1,wt,pr,dp), kProfit(W,N-1,wt,pr,dp))
        return dp[N][W]
    else:
        dp[N][W] = kProfit(W,N-1,wt,pr,dp)
        return dp[N][W]
 
def subSum(arr,target):
    n = len(arr)
    dp = [[None]*(target+1) for _ in range(n+1)]

    # Initialise DP array !!
    # If no. of elements in arr are 0 then Target sum is not possible
    # Target sum = 0 is always possible i.e, by keeping the array subset as null/phi.
    for i in range(target+1):
        dp[0][i] = False
    for j in range(n+1):
        dp[j][0] = True

    # An element can be chosen only if sum is less han arr[i] else it cannot be included
    for i in range(1,n+1):
        for j in range(target+1):
            if arr[i-1] <= j:
                dp[i][j] = dp[i-1][j-arr[i-1]] or dp[i-1][j]
            else:
                dp[i][j] = dp[i-1][j]

    return dp[n][target]   


def LCS(s1,s2,l1,l2):
    dp = [[None]*(l2+1) for _ in range(l1+1)]

    # Initialise dp
    # If length of any substring is 0 then length of LCS will be zero
    # So dp[0][i] and dp[j][0] will be zero

    for i in range(l1+1):
        dp[i][0] = 0
    for j in range(l2+1):
        dp[0][j] = 0

    # if s1[i] == s2[j] then increase by 1 else search in i-1 and j or i and j-1
    for i in range(1,l1+1):
        for j in range(1,l2+1):
            if s1[i-1] == s2[j-1]:
                dp[i][j] = 1 + dp[i-1][j-1]
            else:
                dp[i][j] = max(dp[i][j-1],dp[i-1][j])

    # dp[l1][l2] contains the length of LCS of s1 and s2
    return dp[l1][l2]    
    
if __name__ == '__main__':
    
    W = 11
    wt = [1, 2, 5, 6, 7]
    pr = [1, 6, 18, 22, 28]
    N = len(pr)
    # define DP array
    dp = [[None] * (W + 1) for _ in range(N + 1)]
    # Call for kProfit to calculate max profit
    maxProfit = kProfit(W,N,wt,pr,dp)
    print('Maximum Profit is : ',maxProfit)
    
    ## subset sum
    arr = [0, 3, 2, 7, 1]
    target = 6
    exists =  subSum(arr,target)
    print('Subset with Target sum exists : ', str(exists))
    
    ## LCS longest common subsequence
    s1 = 'abbacdcba'
    s2 = 'bcdbbcaa'
    maxlen = LCS(s1,s2,len(s1),len(s2))
    print("Length of LCS = ",maxlen)
    
    