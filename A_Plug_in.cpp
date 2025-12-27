#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin>>str;
    int l=str.length();
    stack<char> st;

    for(int i=0;i<l;i++)
    {
        char ch=str[i];
        //if(st.top()==ch) st.pop();
        if(!st.empty() && st.top() == ch) st.pop();
        else st.push(ch);
    }
    str="";
    while(!st.empty())
    {
        char ch = st.top();
        st.pop();
        str.push_back(ch);
    }
    reverse(str.begin(),str.end());
    cout<<str<<endl;
}