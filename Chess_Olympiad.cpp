#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    float x,y,z;
    cin>>x>>y>>z;
    float a=x+y*.5,b=z+y*.5;
    float r_r=4-x-y-z;
    
    if(a+r_r>b) cout<<"Yes\n";
    else cout<<"No\n";
}
