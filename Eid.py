import sys, math, itertools, functools, collections, heapq, bisect, random

def lcm(a, b):
    return (a * b) // math.gcd(a, b)

def solve():
    n = int(input()) 
    numbers = list(map(int, input().split()))
    ans = 1
    
    for a in numbers:
        ans = lcm(ans, a)
    
    print(ans)

def main():
    sys.stdin = open(0) 
    t = int(input())
    
    for i in range(1, t + 1):
        print(f"Case {i}: ", end="")
        solve()

if __name__ == "__main__":
    main()
