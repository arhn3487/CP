import math
def solve():
    n=int(input())
    a=list(map(int,input().split()))
    sum=0
    l=1
    for x in a:
        l=math.lcm(l,x)
    
    for x in a:
        sum+=(l//x)
    
    print(sum%(10**9+7))

    pass

def main():
    t=1
    #t=int(input())
    for i in range(1,t+1):
        #print(f"Case {i} : ")
        solve()

if __name__=="__main__":
    main()