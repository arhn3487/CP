tree=[]
s=[]
def build(ind,low,hi):
    if low==hi:
        tree[ind]=1<<(ord(s[low])-ord('a'))
        return
    mid=(low+hi)//2
    build(2*ind+1,low,mid)
    build(2*ind+2,mid+1,hi)
    tree[ind]=tree[2*ind+1] | tree[2*ind+2]
    return

def update(ind,low,hi,target_ind,val):
    if low==hi:
        tree[ind]=(1<<val)
        return
    mid=(low+hi)//2
    if target_ind<=mid:
        update(2*ind+1,low,mid,target_ind,val)
    else:
        update(2*ind+2,mid+1,hi,target_ind,val)
    
    tree[ind]=tree[2*ind+1] | tree[2*ind+2]
    return

def query(ind,low,hi,L,R):
    if R<low or L>hi:
        return 0
    if low>=L and hi<=R:
        return tree[ind]
    mid=(low+hi)//2
    m1=query(2*ind+1,low,mid,L,R)
    m2=query(2*ind+2,mid+1,hi,L,R)

    return m1 | m2

def solve():
    global s,tree
    n=int(input())
    s=list(input())
    q=int(input())

    tree=[0]*(4*n)

    build(0,0,n-1)

    for _ in range(q):
        data=input().split()
        type,a=int(data[0]),int(data[1])
        if type==1:
            s[a-1]=data[2]
            x=ord(data[2])-ord('a')
            update(0,0,n-1,a-1,x)
        else :
            b=int(data[2])
            ans=query(0,0,n-1,a-1,b-1)
            print(ans.bit_count())
    pass

def main():
    t=1
    #t=int(input())
    for i in range(1,t+1):
        #print(f"Case {i} : ")
        solve()

if __name__=="__main__":
    main()