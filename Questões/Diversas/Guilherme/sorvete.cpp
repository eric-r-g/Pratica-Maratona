#include <bits/stdc++.h>
using namespace std;

int main() {
    int p, s, u, v;
    vector<pair<int,int>> intervalos;
    cin >> p >> s;
    for (int i = 0; i < s; i++) {
        cin >> u >> v;
        pair<int,int> intervalo = {u, v};
        intervalos.push_back(intervalo);
    }
    sort(intervalos.begin(), intervalos.end());
    for (int i = 1; i < s; i++) {
        if (intervalos[i].first < intervalos[i-1].second) {
            intervalos[i].first = intervalos[i-1].first;
            if (intervalos[i].second > intervalos[i-1].second) intervalos[i].second = intervalos[i-1].second;
            intervalos.erase(intervalos.begin() + i - (s - intervalos.size()) - 1);
        }
    }
    for (pair<int,int> intervalo : intervalos) {
        cout << intervalo.first << " " << intervalo.second << "\n";
    }
    return 0;
}
