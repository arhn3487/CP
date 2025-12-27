#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Monster {
    long long HP;
    long long ATK;
};

bool compareByAttack(const Monster& a, const Monster& b) {
    return a.ATK > b.ATK; // Sort by ATK in descending order
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n;
        cin >> n;
        vector<Monster> monsters(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> monsters[i].HP >> monsters[i].ATK;
        }
        
        // Sort monsters by ATK in descending order
        sort(monsters.begin(), monsters.end(), compareByAttack);
        
        long long totalDamage = 0;
        long long currentDamage = 0; // Damage from alive monsters
        
        for (const auto& monster : monsters) {
            currentDamage += monster.ATK;
        }
        
        for (const auto& monster : monsters) {
            long long turnsToKill = (monster.HP + 1) / 2; // Calculate how many attacks are needed
            totalDamage += currentDamage * turnsToKill; // Add damage suffered during these turns
            currentDamage -= monster.ATK; // Monster is killed, reduce its ATK from total
        }
        
        cout << "Case #" << t << ": " << totalDamage << endl;
    }
    return 0;
}
