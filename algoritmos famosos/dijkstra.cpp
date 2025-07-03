#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;
typedef vector <pii> vi;
typedef vector <vi> grafo;

grafo g;
vector <bool> visitados;

priority_queue <pii, vector<pii>, greater<pii>> pq;
vector <int> dist;

void dijkstra(int n, int ini){
    dist.assign(n, INT_MAX);
    visitados.assign(n, false);

    pq.push({0,ini});
    dist[ini] = 0;

    while(!pq.empty()){
        int u = pq.top().second;

        pq.pop();

        if(visitados[u]) 
            continue;

        visitados[u] = true;

        for(auto x : g[u]){
            if (dist[x.first] > dist[u] + x.second){
                dist[x.first] = dist[u] + x.second;
                pq.push({dist[x.first], x.first});
            }
        }
    }

    return;
}

int main(){
    int n, m, ini, fim;
    cin >> n >> m >> ini >> fim;
    g.assign(n, vi());

    int a, b, peso;
    for(int i = 0; i < m; ++i){
        cin >> a >> b >> peso;    
        g[a].push_back({b, peso});
        g[b].push_back({a, peso});
    }

    dijkstra(n, ini);

    cout << "distancia: " << dist[fim] << endl;

    return 0;
}
