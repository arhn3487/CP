#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	    //char c='0';
	    int one=0,two=0,n;
	    string s;
	    cin>>n>>s;
	    
	    for(int i=0;i<n;i++)
	    {
	        if(s[i]=='0'){continue;}
	        while(s[i]!='1') i++;
	        i--;
	        one++;
	    }
	    for(int i=0;i<n;i++)
	    {
	        if(s[i]=='1'){continue;}
	        while(s[i]!='0') i++;
	        i--;
	        two++;
	    }
	    cout<<min(one,two)<<endl;
	}
}
