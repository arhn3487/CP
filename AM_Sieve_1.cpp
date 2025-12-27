#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll infinity = LLONG_MAX;
int dx[]={1,0,-1,0,1,1,-1,-1};
int dy[]={0,-1,0,1,1,-1,1,-1};
ll lcm(ll a,ll b) {return (a*b)/__gcd(a,b);}

//const int mx=1e6+10;
const int mx=50;
bool isPrime[mx];

void seive()
{
    for(int i=2;i<mx;i++) isPrime[i]=true;

    for(int i=2;i*i<mx;i++)
    {
        if(isPrime[i])
        {
            for(int j=i*2;j<mx;j+=i)
            {
                isPrime[j]=false;
                //cout<<j<<" "<<i<<endl;
            }
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    seive();
    

    while(t--)
    {
        int n;
        cin>>n;

        if(isPrime[n]) cout<<n<<" is a prime number.\n";
        else cout<<n<<" is not a prime number.\n";
    }
}