#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;
    string str;
    map<string,int> mp;

    while(n--)
    {
        cin>>str;

        if(mp[str]==0)
        {
            cout<<"OK"<<endl;
            mp[str]++;
        }
        else
        {
            cout<<str<<mp[str]<<endl;
            mp[str]++;
        }
    }
}