n,a=map(int,input().split())
k=int(input())
a-=1

k=k%n
print(k)

arr=list(map(int,input().split()))

while k>1:
    a=arr[a]
    k-=1

print(a+1)