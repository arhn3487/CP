#include<bits/stdc++.h>
using namespace std;

struct _ { ios_base::Init i; _() { cin.sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10); } } ___;
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

//735134400 -> 1344
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//#define ordered_set tree<LL,null_type,less<LL>,rb_tree_tag,tree_order_statistics_node_update>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define FileIO freopen("input.txt","r",stdin);freopen("output.txt","w",stdout)
#define LL long long
#define LD long double
#define cmp(typ) complex<typ>
#define asort(ar,n) sort(ar,ar+n)
#define vsort(vc) sort(vc.begin(),vc.end())
#define vrsort(vc) sort(vc.rbegin(),vc.rend())
#define srev(st) reverse(st.rbegin(),st.rend())
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define Yes cout<<"Yes\n"
#define No cout<<"No\n"
#define yes cout<<"yes\n"
#define no cout<<"no\n"
#define Case(a) cout<<"Case "<<a<<": "
#define CaseN(a) cout<<"Case "<<a<<":\n"
#define psum(vc,sm) partial_sum(vc.begin(),vc.end(),sm.begin()+1)
#define pxor(vc,sm) partial_sum(vc.begin(),vc.end(),sm.begin()+1,[](LL x, LL y){return x^y;})
#define pgcdLeft(vc,sm) partial_sum(vc.begin(),vc.end(),sm.begin()+1,[](LL x, LL y){return __gcd(x,y);})
#define pgcdRight(vc,sm) partial_sum(vc.rbegin(),vc.rend(),sm.begin()+1,[](LL x, LL y){return __gcd(x,y);})
#define pi acos(-1)

int main()
{
    FastIO;

    LL t=1,n,h,k; cin>>t;
    while(t--)
    {
        cin>>n>>h>>k;

        LL sum=0;
        LL arr[n];
        for(LL i=0; i<n; i++)
        {
            cin>>arr[i];
            sum+=arr[i];
        }

        LL low=1;
        LL high=h+(h*k/n);

        while(low<high)
        {
            LL mid=low+high>>1;

            LL full=mid/(n+k);
            LL half=mid-full*(n+k);

            half=min(half,n);
            LL harm=full*sum;

            LL mnn=1e18;
            for(LL i=0; i<half; i++)
            {
                harm+=arr[i];
                mnn=min(mnn,arr[i]);
            }

            LL mxx=0;
            for(LL i=half; i<n; i++)
            {
                mxx=max(mxx,arr[i]);
            }

            harm+=max(0LL,mxx-mnn);

            if(harm<h) low=mid+1;
            else high=mid;
        }

        cout<<low<<"\n";
    }

    return 0;
}
