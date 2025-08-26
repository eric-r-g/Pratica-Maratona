#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    if (!(cin >> N >> Q)) return 0;
    vector<int64> A(N+1);
    for (int i = 1; i <= N; ++i) cin >> A[i];

    vector<int> c(Q+1);
    vector<int64> d(Q+1);
    for (int q = 1; q <= Q; ++q) cin >> c[q] >> d[q];

    const int MAXC = 100000;

    // Pré-calcula divisores de 1..MAXC
    vector<vector<int>> divisors(MAXC+1);
    for (int t = 1; t <= MAXC; ++t)
        for (int m = t; m <= MAXC; m += t)
            divisors[m].push_back(t);

    // Möbius até MAXC
    vector<int> mu(MAXC+1, 1), primes, is_comp(MAXC+1, 0);
    vector<int> minp(MAXC+1, 0);
    mu[0] = 0; mu[1] = 1;
    for (int x = 2; x <= MAXC; ++x) {
        if (!is_comp[x]) { primes.push_back(x); mu[x] = -1; minp[x] = x; }
        for (int p: primes) {
            long long y = 1LL * p * x;
            if (y > MAXC) break;
            is_comp[y] = 1;
            minp[y] = p;
            if (x % p == 0) { mu[y] = 0; break; }
            else mu[y] = -mu[x];
        }
    }

    // Divisores de i (i vai até N, e N <= 1e5)
    vector<vector<int>> div_i(N+1);
    for (int i = 1; i <= N; ++i)
        for (int t = 1; t * 1LL * t <= i; ++t) {
            if (i % t == 0) {
                div_i[i].push_back(t);
                if (t * 1LL * t != i) div_i[i].push_back(i / t);
            }
        }

    // Busca binária paralela
    vector<int> lo(N+1, 1), hi(N+1, Q+1); // [1..Q], Q+1 => não alcança
    vector<int> ans(N+1, -1);

    auto alive = [&]() {
        for (int i = 1; i <= N; ++i) if (lo[i] < hi[i]) return true;
        return false;
    };

    // Arrays acumuladores por prefixo de rodadas
    vector<int64> S(MAXC+1, 0); // S_t
    int64 T = 0;

    while (true) {
        bool any = false;
        for (int i = 1; i <= N; ++i) if (lo[i] < hi[i]) { any = true; break; }
        if (!any) break;

        // buckets[mid] => lista de participantes a avaliar no prefixo mid
        vector<vector<int>> buckets(Q+2);
        for (int i = 1; i <= N; ++i) if (lo[i] < hi[i]) {
            int mid = lo[i] + (hi[i] - lo[i]) / 2;
            buckets[mid].push_back(i);
        }

        // reset prefixos
        fill(S.begin(), S.end(), 0);
        T = 0;
        int qptr = 0;

        for (int mid = 1; mid <= Q; ++mid) {
            while (qptr < mid) {
                ++qptr;
                T += d[qptr];
                // adiciona d[qptr] em S_t para todo t | c[qptr]
                for (int t : divisors[c[qptr]]) S[t] += d[qptr];
            }
            // avalia todos desse mid
            for (int i : buckets[mid]) {
                // soma coprima = sum_{t|i} mu(t) * S_t
                int64 cop = 0;
                for (int t : div_i[i]) {
                    if (t <= MAXC) cop += (int64)mu[t] * S[t];
                }
                int64 applicable = T - cop;
                if (applicable >= A[i]) {
                    hi[i] = mid;
                } else {
                    lo[i] = mid + 1;
                }
            }
        }
        // quem ficou com lo > Q não alcança
    }

    for (int i = 1; i <= N; ++i) {
        if (lo[i] == Q+1) cout << -1 << '\n';
        else cout << lo[i] << '\n';
    }
    return 0;
}
