#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, q, a, b;
	cin >> n >> q;
	vector<long long> x(n);
	cin >> x[0];
	for (int i = 1; i < n; i++) {
		cin >> x[i];
		x[i] += x[i-1];
	}
	for (int i = 0; i < q; i++) {
		cin >> a >> b;
		long long res = x[b-1] - (a == 1 ? 0 : x[a-2]);
		cout << res << "\n";
	}
    return 0;
}
