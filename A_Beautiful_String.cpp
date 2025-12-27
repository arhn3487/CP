#include<bits/stdc++.h>
using namespace std;

#define ll long long
char c[]={'a','b','c'};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int flag=1;
        string str,s;
        cin>>str;
        str.push_back('.');
        str='.'+str;

        
        for(int i=1;i<str.length();i++)
        {
            if(str[i]=='?')
            {
                s=str;
                for(int j=0;j<3;j++)
                {
                    s[i]=c[j];
                    if(s[i-1]!=s[i] && s[i]!=s[i+1]) {str=s;break;}
                    s=str;
                }
            }
            if(str[i-1]==str[i] || str[i]==str[i+1]) flag=0;
        }
        if(flag)cout<<str.substr(1,str.length()-2)<<endl;
        else cout<<-1<<endl;
    }
}