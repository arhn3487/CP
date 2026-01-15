import bisect
def solve():
    n=int(input())
    v=list(map(int,input().split()))
    v.sort()
    q=int(input())
    
    for x in range(q):
        a=list(map(int,input().split()))
        b=bisect.bisect_right(v,a[1])-bisect.bisect_left(v,a[0])
        print(b)
    pass

def main():
    t=1
    #t=int(input())
    for i in range(1,t+1):
        #print(f"Case {i} : ")
        solve()

if __name__=="__main__":
    main()