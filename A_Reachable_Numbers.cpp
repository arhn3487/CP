#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin>>n;
    set<long long> st;

    while(n>9)
    {
        st.insert(n);
        n++;
        while(n%10==0) n/=10;
    }
    cout<<st.size()+9<<endl;
}