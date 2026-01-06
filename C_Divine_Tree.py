def solve():
    n,k=map(int,input().split())
    val=list(range(1,n+1))
    
    if k<n or k>(n*(n+1))//2:
        print(-1)
        return

    rem=(n*(n+1))//2-k

    for i in range(n-1,-1,-1):
        if rem<=val[i]-1:
            val[i]-=rem
            rem=0
        else:
            rem-=val[i]-1
            val[i]=1
        
        if rem<=0:
            break
    
    root=max(val)
    print(root)

    for i in range(0,n):
        if val[i]==i+1:
            if i+1==root:
                continue
            print(f"{i+1} {root}")
        else:
            print(f"{val[i]} {i+1}")

    pass

def main():
    t=1
    t=int(input())
    for i in range(1,t+1):
        #print(f"Case {i} : ")
        solve()

if __name__=="__main__":
    main()