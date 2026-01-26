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
    n,c=map(int,input().split())
    start=[0]*(100005)
    fin=[0]*(100005)
    channels = [[] for _ in range(31)]
    marge = [[] for _ in range(31)]

    active,free=0,0

    for _ in range(n):
        s,t,c=map(int,input().split())
        channels[c].append((s,t))
        # start[s]+=1
        # fin[t]+=1
    
    for i in range(1,31):
        if(len(channels[i])==0):
            continue
        channels[i].sort()
        st=channels[i][0][0]
        en=channels[i][0][0]
        for j in range(len(channels[i])):
            if(en==channels[i][j][0]):
                en=channels[i][j][0]
            else:
                marge[i].append((st,en))
                if j==len(channels[i])-1:
                    break
                st=channels[i][j+1][0]
                en=channels[i][j+1][0]
                j-=1
        marge[i].append((st,en))

    for i in range(1,31):
        for [s,t] in marge[i]:
            start[s]+=1
            fin[t]+=1


    for i in range(100005):
        
        if free<=start[i]:
            active+=(start[i])
            free=0
        elif free>start[i]:
            active+=start[i]
            free-=start[i]
        free+=fin[i]
        active-=fin[i]

    print(active+free)
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