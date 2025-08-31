#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct team {
    int num;
    double feitos;
    double sofridos;
    int vitorias;
} team;

int sortt(team a, team b) {
    if (a.vitorias > b.vitorias) return 1;
    if (b.vitorias > a.vitorias) return 0;
    double as = a.feitos / (a.sofridos == 0 ? 1 : a.sofridos);
    double bs = b.feitos / (b.sofridos == 0 ? 1 : b.sofridos);
    if (as > bs) return 1;
    if (bs > as) return 0;
    if (a.num < b.num) return 1;
    return 0;
}

int main() {
    int n;
    int x, y, z, w;
    int inst = 1;
    while (true) {
        cin >> n;
        if (n == 0) break;
        else if (inst > 1) cout << "\n";
        vector<team> teams(n);
        for (int i = 0; i < n * (n - 1) / 2; i++) {
            cin >> x >> y >> z >> w;
            x--;
            z--;
            teams[x].num = x + 1;
            teams[z].num = z + 1;
            teams[x].feitos += y;
            teams[z].sofridos += y;
            teams[x].sofridos += w;
            teams[z].feitos += w;
            if (y > w) {
                teams[x].vitorias += 2;
                teams[z].vitorias += 1;
            } else {
                teams[z].vitorias += 2;
                teams[x].vitorias += 1;
            }
        }
        sort(teams.begin(), teams.end(), sortt);
        cout << "Instancia " << inst << "\n";
        for (int i = 0; i < n - 1; i++) {
            cout << teams[i].num << " ";
        }
        cout << teams[n - 1].num << "\n";
        inst++;
    }
    return 0;
}
