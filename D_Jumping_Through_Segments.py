import sys

def solve():
    n=int(input())
    l=[0]*n
    r=[0]*n

    for i in range(n):
        l[i],r[i]=map(int,input().split())

    lo,hi=0,int(1e9)

    while(lo<hi):
        k=lo+(hi-lo)//2
        leftk,rightk,f=0,k,0

        for i in range (n):
            if(leftk>r[i] or rightk<l[i]):
                f=1
                break
            leftk=max(l[i],leftk)
            rightk=min(rightk,r[i])
            leftk-=k
            rightk+=k
        if f:
            lo=k+1
        else :
            hi=k
    print(lo)

def main():
    t=int(input())
    for i in range(t):
        solve()

if __name__=="__main__":
    main()