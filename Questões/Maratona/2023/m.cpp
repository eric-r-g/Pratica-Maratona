#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define f first
#define s second

typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 101;

vector<pii> g[MAX];

vector<int> dijkstra(int s, pii e){
    vector<int> dist(MAX, INT_MAX);
    vector<bool> vis(MAX, 0);

    priority_queue<pii, vector<pii>, greater<pii>> pq;
	dist[s] = 0;
	pq.push({0, s});

	while(!pq.empty()){
		int u = pq.top().second;
		pq.pop();

		if(vis[u]) continue;

		vis[u] = 1;
		
		for(auto p : g[u]){
			int v = p.s, w = p.f;
            if(u == e.first && v == e.second) continue;
			if(dist[v] > dist[u] + w){
				dist[v] = dist[u] + w;
				pq.push({dist[v], v});
			}
		}
	}

    return dist;
}

int main(){ _
    int n; cin >> n;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            int w; cin >> w;
            g[i].push_back({w, j});
        }
    }
    // for(int i = 0 ; i < n ; i++){
    //     cout << i << ": [";
    //     for(auto u : g[i]) cout << u.f << " " << u.s << ", ";
    //     cout << "]";
    // }
    int ans = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = i+1 ; j < n ; j++){
            vector<int> dist = dijkstra(i, {i,j});
            // cout << "i: " << i << " j: " << j << " dist: ";
            // cout << g[i][j].first << " dijktra: ";
            // cout << dist[j] << endl;
            if(dist[j] > g[i][j].first) continue;
            else if(dist[j] == g[i][j].first) ans++;
            else{
                cout << -1 << endl;
                return 0;
            }
        }
    }
    cout << ans << endl;
    return 0;
}