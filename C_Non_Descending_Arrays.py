mod = 998244353
def solve():
    n=int(input())
    a=[0]+ list(map(int,input().split()))
    b=[0]+ list(map(int,input().split()))

    dp=[[0]*(2) for _ in range(n+1)]

    dp[n][0]=dp[n][1]=1

    for i in range(n-1,0,-1):
        if a[i]<=a[i+1] and b[i]<=b[i+1]:
            dp[i][0]=dp[i+1][0]
        if a[i]<=b[i+1] and b[i]<=a[i+1]:
            dp[i][0]+=dp[i+1][1]
        if a[i]<=b[i+1] and b[i]<=a[i+1]:
            dp[i][1]=dp[i+1][0]
        if a[i]<=a[i+1] and b[i]<=b[i+1]:
            dp[i][1]+=dp[i+1][1]
    
    print((dp[1][0]+dp[1][1])%mod)



def main():
    t = 1
    t=int(input())
    for _ in range(t):
        solve()

if __name__ == '__main__':
    main()