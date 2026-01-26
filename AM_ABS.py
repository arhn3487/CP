import math
import sys
import os

def dbg(*args):
    if 'ONLINE_JUDGE' in os.environ:
        return
    import traceback
    stack = traceback.extract_stack()
    line = stack[-2].line
    names = line[line.find('dbg(')+4 : line.rfind(')')]
    print(f"[{names}]:", *args, file=sys.stderr)

def solve():
    n,x,y=map(int,input().split())
    v=list(map(int,input().split()))

    if n==1:
        print(abs(v[0]-y))
    else:
        print(max(abs(v[n-1]-y),abs(v[n-1]-v[n-2])))
    return

def main():
    t=1
    #t = int(input())
    for i in range(1, t + 1):
        # print(f"Case {i} : ")
        solve()
    return

if __name__ == "__main__":
    main()