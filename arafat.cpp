#include <bits/stdc++.h>
using namespace std;

int main() {
    srand(time(0));

    int test = 0;
    while (true) {
        test++;

    // ==== Generate random test case ====
    int t = 1; // number of test cases (fixed to 1 for stress testing)
        ofstream in("input.txt");
        in << t << "\n";

        for (int tc = 0; tc < t; tc++) {
            int n = rand() % 20 + 3; // grid size (1 to 100)
            int k = rand() % n; // grid size (1 to 100)
            in << k<<' '<<n << "\n";
            // for (int i = 0; i < n; i++) 
            // {
            //     int val = rand() % 100 + 1;
            //     in << val << " ";
            // }
            in << "\n";
            // for (int i = 0; i < n; i++)
            // {
            //     int val = rand()%(n-i)+1;i
            //     in << val << " ";
            // }
            // in << "\n";
            
            
        }
        in.close();

        // ==== Run both programs (Windows syntax) ====
        system("solution1.exe < input.txt > output1.txt");
        system("solution2.exe < input.txt > output2.txt");

        // ==== Compare outputs ====
        ifstream out1("output1.txt");
        ifstream out2("output2.txt");
        string s1((istreambuf_iterator<char>(out1)), istreambuf_iterator<char>());
        string s2((istreambuf_iterator<char>(out2)), istreambuf_iterator<char>());

        if (s1 != s2) {
            cout << "❌ Mismatch found on test #" << test << "!\n";
            cout << "------------------------------\n";
            cout << "Input:\n";
            ifstream fin("input.txt");
            cout << fin.rdbuf() << "\n";
            cout << "------------------------------\n";
            cout << "Output1:\n" << s1 << "\n";
            cout << "------------------------------\n";
            cout << "Output2:\n" << s2 << "\n";
            cout << "------------------------------\n";
            break;
        }

        if (test % 100 == 0)
            cout << "✅ Passed " << test << " random tests...\n";
    }

    return 0;
}