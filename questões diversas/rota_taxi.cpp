#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> pii;
typedef long long ll;


const int MAX = 1e4 + 1; 
const int maxn = 20, maxm = (1 << 16) + 10;

vector <vector <pii>> grafo;
map <int, vector <ll>> distancias; // distancias pra cada um dos pontos principais
vector <bool> visitados;

int n, m, k;

void dijkstra(int ini){
    priority_queue <pii, vector <pii>, greater <pii>> pq;

    vector <ll>& dist = distancias[ini];
    dist.assign(n + 1, LLONG_MAX);
    visitados.assign(n + 1, 0);

    pq.push({0, ini});
    dist[ini] = 0;
    
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();

        if(visitados[u]) continue;
        visitados[u] = true;

        for(auto v : grafo[u]){
            if(dist[v.first] > dist[u] + v.second){
                dist[v.first] = dist[u] + v.second;
                pq.push({dist[v.first], v.first});
            }
        }
    }
}

ll dist_pedidos[maxn][maxn], dp[maxm][maxn];

ll calcular_rota(int mask, int i){
    if (mask == (1 << (k + 1)) - 1) return dist_pedidos[i][0];

    if (dp[mask][i] != -1) return dp[mask][i];

    ll retorno = 1e18;
    
    for(int v = 0; v <= k; ++v){
        int deslocado = 1 << v;

        if(mask & deslocado){ 
            continue;
        }
        retorno = min(retorno, calcular_rota(mask | deslocado, v) + dist_pedidos[i][v]);
    }

    return dp[mask][i] = retorno;
}



vector <pii> p_esp;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    grafo.assign(n + 1, vector<pii>());
    int a, b, c;
    while(m--){
        cin >> a >> b >> c;
        grafo[a].push_back({b, c});
        grafo[b].push_back({a, c});
    }

    int ini, fim;
    
    p_esp.push_back({1, 1});
    for(int i = 0; i < k; ++i){
        cin >> ini >> fim;
        p_esp.push_back({ini, fim});
    }

    for(int i = 0; i <= k; ++i){
        dijkstra(p_esp[i].second);
    }

    for(int i = 0; i <= k; ++i){
        for(int j = 0; j <= k; ++j){
            dist_pedidos[i][j] = distancias[p_esp[i].second][p_esp[j].first] + distancias[p_esp[j].second][p_esp[j].first];
        }
    }

    memset(dp, -1, sizeof(dp));
    cout << calcular_rota(1, 0) << "\n";
}