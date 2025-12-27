#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        string s;
        cin>>s;
        int l=s.length(),cnt=0,f=0;
        int prev=s[0];

        for(int i=0;i<l;i++)
        {
            if(i<l-1 && s[i]=='0' && s[i+1]=='1') f=1;
            if(s[i]==prev) continue;
            else
            {
                //cout<<i<<" "<<prev<<endl;
                prev=prev^1;
                cnt++;
            }
        }
        ////bool f=s.find("01");
        //cout<<f<<endl;
        if(f) {cout<<cnt<<endl; continue;}
        else if(cnt==0) {cout<<1<<endl; continue;}
        if(cnt)cout<<cnt+1<<endl;
        else cout<<1<<endl;
    }
}