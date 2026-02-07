import sys
input = sys.stdin.readline

def solve():
    n, a= map(int, input().split())
    k=int(input())
    v = [0] + list(map(int, input().split()))

    vis = [0] * (n + 1)
    sz = -1

    for i in range(1, k + 1):
        if vis[a]:
            k -= i
            sz = i - vis[a] 
            a = v[a]
            break
        vis[a] = i
        a = v[a]
        if i == k:
            print(a)
            return

    if k == 0:
        print(a)
        return

    k %= sz
    while k > 0:
        a = v[a]
        k -= 1

    print(a)


if __name__ == "__main__":
    solve()