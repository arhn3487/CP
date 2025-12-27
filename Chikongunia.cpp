#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll mod1 = 1e9+7;
const ll mod2 = 1e9+9;
const ll base1 = 2147483647;
const ll base2 = 2147476381;

vector<ll> pow1, pow2;

int n, m;

void calpow(int len)
{
    pow1.resize(len+1);
    pow2.resize(len+1);
    pow1[0]=1; pow2[0]=1;
    for(int i=0;i<len;i++)
    {
        pow1[i+1] = (pow1[i]*base1) % mod1;
        pow2[i+1] = (pow2[i]*base2) % mod2;
    }
}

class Hash
{
private:
    string str;
    vector<ll> ph1, ph2;

    void prefix_hash()
    {
        int len = str.size();
        ph1.resize(len);
        ph2.resize(len);
        ll x=0, y=0;
        for(int i=0;i<len;i++)
        {
            x = (x*base1 + str[i]) % mod1;
            y = (y*base2 + str[i]) % mod2;
            ph1[i] = x;
            ph2[i] = y;
        }
    }

public:
    Hash(string s)
    {
        str = s;
        prefix_hash();
    }

    pair<ll,ll> cal_hash(int left,int right)
    {
        if(left==0) return {ph1[right], ph2[right]};
        ll x = ((ph1[right] - ph1[left-1]*pow1[right-left+1]) % mod1 + mod1) % mod1;
        ll y = ((ph2[right] - ph2[left-1]*pow2[right-left+1]) % mod2 + mod2) % mod2;
        return {x,y};
    }
};

void solve()
{
    cin >> n >> m;
    calpow(m); // compute powers after knowing string length

    vector<string> v(n);
    map<pair<ll,ll>,int> freq;
    ll ans = 0;

    for(int i=0;i<n;i++)
    {
        cin >> v[i];
        Hash s(v[i]);
        string tmp = v[i];

        for(int j=0;j<m;j++)
        {
            for(char k='a'; k<='z'; k++)
            {
                if(tmp[j]==k) continue;
                tmp[j]=k;
                Hash t(tmp);
                ans += freq[t.cal_hash(0,m-1)];
            }
            tmp[j] = v[i][j];
        }

        freq[s.cal_hash(0,m-1)]++;
    }

    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    //cin >> t;
    for(int i=1;i<=t;i++) solve();
    return 0;
}
