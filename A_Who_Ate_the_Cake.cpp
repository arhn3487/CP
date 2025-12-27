#include<bits/stdc++.h>
using namespace std;

int main()
{
  set<int> st;
  int a;
  cin>>a;
  st.insert(a);
  cin>>a;
  st.insert(a);
  if(st.size()==1) cout<<-1<<endl;
  else if(st.find(2)==st.end()) cout<<2<<endl;
  else if(st.find(1)==st.end()) cout<<1<<endl;
  else if(st.find(3)==st.end()) cout<<3<<endl;
}