#include<bits/stdc++.h>
using namespace std;

int main()
{
    double h,l,res,x;
    cin>>h>>l;
    x=abs(l*l-h*h);
    res=x/(2*h);
    cout<<fixed<<setprecision(13)<<res;
}