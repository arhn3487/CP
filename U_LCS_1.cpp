#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s, t;
    cin >> s >> t;

    int n1 = s.length(), n2 = t.length();

    int dp[n1+1][n2+1] = {};
    char dir[n1+1][n2+1]; // to store directions


    for(int i = 0; i <= n1; i++)
        for(int j = 0; j <= n2; j++)
            dir[i][j] = ' ';

    for(int i = 1; i <= n1; i++)
    {
        for(int j = 1; j <= n2; j++)
        {
            if(s[i-1] == t[j-1])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
                dir[i][j] = 'D'; 
            }
            else if(dp[i-1][j] >= dp[i][j-1])
            {
                dp[i][j] = dp[i-1][j];
                dir[i][j] = 'U'; 
            }
            else
            {
                dp[i][j] = dp[i][j-1];
                dir[i][j] = 'L'; 
            }
        }
    }

    cout << "    ";
    for(int j = 0; j < n2; j++)
        cout << t[j] << " ";
    cout << endl;

    for(int i = 0; i <= n1; i++)
    {
        if(i == 0)
            cout << "  ";
        else
            cout << s[i-1] << " ";

        for(int j = 0; j <= n2; j++)
        {
            cout << dir[i][j] << " ";
        }
        cout << endl;
    }

    // Reconstruct the LCS string
    string res = "";
    int i = n1, j = n2;
    while(i > 0 && j > 0)
    {
        if(dir[i][j] == 'D')
        {
            res += s[i-1];
            i--; j--;
        }
        else if(dir[i][j] == 'U')
            i--;
        else
            j--;
    }

    reverse(res.begin(), res.end());

    cout << "\nLCS: " << res << endl;
}
