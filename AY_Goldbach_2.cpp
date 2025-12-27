#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};
int dy[]={0,-1,0,1,1,-1,1,-1};
ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

bool is_prime(int n)
{
    if(n%2==0 && n!=2) return false;
    for(int i=3;i*i<=n;i+=2)
    {
        if(n%i==0) return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;

    if(is_prime(n))
    {
        cout<<1<<"\n"<<n<<endl;
    }
    else if(is_prime(n-2))
    {
        cout<<2<<"\n"<<2<<" "<<n-2<<endl;
    }
    else
    {
        cout<<3<<endl;
        for(int i=n;i>=2;i--)
        {
            if(is_prime(i))
            {
                cout<<i<<" ";
                n-=i;
                break;
            }
        }
        for(int i=2;i<=n;i++)
        {
            //cout<<i<<" "<<n-i<<endl;
            if(is_prime(i) && is_prime(n-i))
            {
                cout<<i<<" "<<n-i<<endl;;
                return 0;
            } 
        }
    }
}