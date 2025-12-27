#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin>>t;
    
    while(t--)
    {
        int n,e=0,o=0;
        cin>>n;
        
        for(int i=1;i*i<=n;i++)
        {
            if(n%i==0)
            {
                if(i%2) o++;
                else e++;

                int a=n/i;

                if(a!=i)
                {
                    if(a%2) o++;
                    else e++;
                }

                
                //cout<<i<<" "<<n/i<<endl;
            }
        }
        
        if(e>o) cout<<1<<endl;
        else if(e==o) cout<<0<<endl;
        else cout<<-1<<endl;
    }
    
}
