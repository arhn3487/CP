#include <bits/stdc++.h>
#include "D:/debug.h"
using namespace std;


bool canReach(const vector<int>& steps, int target) {
    set<int> reachable;
    reachable.insert(0);  

    for (int step : steps) {
        set<int> next;
        for (int pos : reachable) {
            next.insert(pos + step);  
            next.insert(pos - step);  
        }
        reachable = move(next);

        //debug(reachable);
    }

    return reachable.count(target) > 0;
}

int main() {
    string s;
    int targetX, targetY;
    cin >> s >> targetX >> targetY;

    vector<int> movesX, movesY;
    bool firstMove = true;
    bool horizontal = true;   
    int currentMove = 0,b=0;


    for (int i = 0; i <= (int)s.size(); i++) {
        if (i < (int)s.size() && s[i] == 'F') {
            currentMove++;
        } else {
            if (firstMove) {
                targetX -= currentMove;   
                firstMove = false;
            } else {
                if (horizontal) movesX.push_back(currentMove);
                else            movesY.push_back(currentMove);
            }
            currentMove = 0;
            horizontal = !horizontal;    
        }
    }

    //debug(movesX,movesY);


    if (canReach(movesX, targetX) && canReach(movesY, targetY))
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}
