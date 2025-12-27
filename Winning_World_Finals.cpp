#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int f, p, cnt = 0;
        cin >> f >> p;
        bool a=true;
        
        // Add bounds checking or some termination condition if needed
        while(f+1 < 300 && p + 20 <= 1000 && p+20+f+1<=1000) {
            f += 1;
            a=false;
            p += 20;
            //if(p+20+1+f>1000) break;
            cnt++;
            //cout<<f<<" "<<p<<" "<<cnt<<endl;
        }
        
        cout << cnt << endl;
    }
}
