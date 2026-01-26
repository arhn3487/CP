import math

def possible(mid,v,two_pow):
    ans=0
    for i in range(len(v)-1,-1,-1):
        a=v[i]
        while a<mid:
            a*=2
            two_pow-=1
        if two_pow<0:
            return False
        ans+=1
        if ans>=mid:
            return True
    return


def solve():
    n=int(input())
    v=list(map(int,input().split()))

    two_pow=0

    for i,x in enumerate(v):
       k=0
       while x%2==0:
           x//=2
           k+=1
       
       v[i]=x
       two_pow+=k
    v.sort()

    lo,ans,hi=0,0,n

    while lo<=hi:
        mid=(lo+hi)//2
        if(possible(mid,v,two_pow)):
            ans=mid
            lo=mid+1
        else:
            hi=mid-1
    
    print(ans)
    return

def main():
    t=int(input())
    for _ in range(t):
        solve()

if __name__=="__main__":
    main()