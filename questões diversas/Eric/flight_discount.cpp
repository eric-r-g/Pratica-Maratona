#include <bits/stdc++.h>
using namespace std;

typedef pair <long long, long long> pii;
typedef vector <pii> vi;
typedef vector <vi> grafo;

grafo g;
vector <bool> visitados;

priority_queue <pii, vector<pii>, greater<pii>> pq;
vector <long long> dist[2];

void dijkstra_sem_cupom(int n){
    dist[0].assign(n, LLONG_MAX);
    visitados.assign(n, false);

    pq.push({0,0});
    dist[0][0] = 0;

    while(!pq.empty()){
        long long u = pq.top().second;

        pq.pop();

        if(visitados[u]) 
            continue;

        visitados[u] = true;

        for(auto x : g[u]){
            if (dist[0][x.first] > dist[0][u] + x.second){
                dist[0][x.first] = dist[0][u] + x.second;
                pq.push({dist[0][x.first], x.first});
            }
        }
    }

    return;
}

void dijkstra_com_cupom(int n){
    dist[1].assign(n, LLONG_MAX);
    visitados.assign(n, false);

    pq.push({0,0});
    dist[1][0] = 0;

    while(!pq.empty()){
        long long u = pq.top().second;

        pq.pop();

        if(visitados[u]) 
            continue;

        visitados[u] = true;

        for(auto x : g[u]){
            long long distancia;
            if (dist[0][u] + x.second / 2 < dist[1][u] + x.second){
                distancia = dist[0][u] + x.second / 2;
            }
            else {
                distancia = dist[1][u] + x.second;
            }

            if (dist[1][x.first] > distancia){
                dist[1][x.first] = distancia;
                pq.push({dist[1][x.first], x.first});
            }
        }
    }

    return;
}

int main(){
    int n, m;
    cin >> n >> m;
    g.assign(n, vi());

    long long a, b, peso;
    for(int i = 0; i < m; ++i){
        cin >> a >> b >> peso;    
        g[--a].push_back({--b, peso});
    }

    dijkstra_sem_cupom(n);
    dijkstra_com_cupom(n);

    cout << dist[1][n - 1] << endl;

    return 0;
}
