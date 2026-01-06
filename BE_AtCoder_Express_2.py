def solve():
    n,m,q=map(int,input().split())
    grid=[[0]*(n+1) for _ in range(n+1)]
    pre=[[0]*(n+1) for _ in range(n+1)]

    for i in range(m):
        x,y=map(int,input().split())
        grid[x][y]+=1
    
    for i in range (1,n+1):
        for j in range(1,n+1):
            pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+grid[i][j]
    
    for _ in range(q):
        x,y=map(int,input().split())
        print(pre[y][y]-pre[x-1][y]-pre[y][x-1]+pre[x-1][x-1])

    pass

def main():
    t=1
    #t=int(input())
    for i in range(1,t+1):
        #print(f"Case {i} : ")
        solve()

if __name__=="__main__":
    main()