t= int(input())

for _ in range(t):
    n=int(input())
    cnt=1

    while n>0:
        d=n%10
        n//=10
        tmp=0

        for i in range (d+1):
            for j in range(d+1):
                if i+j-d>=0:
                    tmp+=1
        cnt*=tmp
    print(cnt)