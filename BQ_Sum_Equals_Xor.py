MOD = 10**9 + 7

def solve():
    L = input().strip()
    n = len(L)

    # dp[tight]
    dp = [1, 0]  # dp[1]=1 initially (tight), dp[0]=0

    for ch in L:
        Li = int(ch)
        ndp = [0, 0]

        for tight in (0, 1):
            cur = dp[tight]
            if cur == 0:
                continue

            for a, b in ((0,0), (0,1), (1,0)):
                s = a + b
                if tight and s > Li:
                    continue

                ntight = tight and (s == Li)
                ndp[ntight] = (ndp[ntight] + cur) % MOD

        dp = ndp

    print((dp[0] + dp[1]) % MOD)
