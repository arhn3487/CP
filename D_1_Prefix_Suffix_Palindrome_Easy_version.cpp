#include <bits/stdc++.h>
#include "D:/debug.h"
using namespace std;


string longestPalPrefix(string s) {
    string rev = s;
    reverse(rev.begin(), rev.end());
    string concat = s + "#" + rev;
    
    vector<int> lps(concat.size(), 0);
    for (int i = 1; i < concat.size(); i++) {
        int j = lps[i-1];
        while (j > 0 && concat[i] != concat[j])
            j = lps[j-1];
        if (concat[i] == concat[j])
            j++;
        lps[i] = j;
    }
    debug(lps); 
    return s.substr(0, lps[concat.size()-1]);
}

string solve(string s) {
    int n = s.size();
    int l = 0;
    while (l < n/2 && s[l] == s[n-l-1]) l++;
    
    if (l > 0) {
        string mid = s.substr(l, n-2*l);
        string pref_pal = longestPalPrefix(mid);
        reverse(mid.begin(), mid.end());
        string suff_pal = longestPalPrefix(mid);
        
        if (pref_pal.size() > suff_pal.size()) {
            return s.substr(0, l) + pref_pal + s.substr(n-l, l);
        } else {
            return s.substr(0, l) + suff_pal + s.substr(n-l, l);
        }
    } else {
        string pref_pal = longestPalPrefix(s);
        string rev = s;
        reverse(rev.begin(), rev.end());
        string suff_pal = longestPalPrefix(rev);
        return pref_pal.size() > suff_pal.size() ? pref_pal : suff_pal;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << solve(s) << endl;
    }
    return 0;
}