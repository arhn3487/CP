#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        ll n;
        cin>>n;
        string str;
        cin>>str;
        map<char,ll> mp;

        for(auto ch : str) mp[ch]++;

        if(n%2 || n<2) cout<<"NO"<<endl;
        else{
            int flag=0;
            if((mp['N']%2) && (mp['S']%2) && (mp['E']%2) && (mp['W']%2)) flag=1;
            else if((mp['N']%2) && (mp['S']%2) && mp['S']!=0 && mp['N']!=0) flag=1;
            else if((mp['E']%2) && (mp['W']%2) && mp['E']!=0 && mp['W']!=0) flag=1;
            else if(mp['E'] && mp['E']%2) flag=1;
            cout<<flag<<endl;
            if(!flag) cout<<"NO"<<endl;
            else{
                int a=mp['N']%2,b=mp['S']%2,c=mp['E']%2,d=mp['W']%2;
                if(a) mp['N']--;
                if(b) mp['S']--;
                if(c) mp['E']--;
                if(d) mp['W']--;
                for(int i=0;i<mp['N'];i++)
                {
                    if(i%2)cout<<'H';
                    else cout<<'P';
                }
                for(int i=0;i<mp['S'];i++)
                {
                    if(i%2)cout<<'H';
                    else cout<<'P';
                }
                for(int i=0;i<mp['E'];i++)
                {
                    if(i%2)cout<<'H';
                    else cout<<'P';
                }
                for(int i=0;i<mp['W'];i++)
                {
                    if(i%2)cout<<'H';
                    else cout<<'P';
                }
                if(a&&b&&c&&d) cout<<"HHHH";
                else if(a&&b) cout<<"HH";
                else if(c&&d) cout<<"HH";
                cout<<endl;
            }
        }
    }
}