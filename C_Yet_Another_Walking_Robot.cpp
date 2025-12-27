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
        int n;
        cin>>n;

        string str;
        cin>>str;
        //LRUD
        if(find(str.begin(),str.end(),"LR")!=str.end())
        {
            auto it = find(str.begin(),str.end(),"LR")-str.begin();
            cout<<it<<" "<<it+2<<endl;
        }
        else if(find(str.begin(),str.end(),"RL")!=str.end())
        {
            auto it = find(str.begin(),str.end(),"RL")-str.begin();
            cout<<it<<" "<<it+2<<endl;
        }
        else if(find(str.begin(),str.end(),"UD")!=str.end())
        {
            auto it = find(str.begin(),str.end(),"UD")-str.begin();
            cout<<it<<" "<<it+2<<endl;
        }
        else if(find(str.begin(),str.end(),"DU")!=str.end())
        {
            auto it = find(str.begin(),str.end(),"DU")-str.begin();
            cout<<it<<" "<<it+2<<endl;
        }
        
    }
}