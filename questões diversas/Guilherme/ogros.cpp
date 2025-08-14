#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, o, ff;
	cin >> n >> m;
	vector<int> f(n-1);
	for (int i = 0; i < n - 1; i++) {
		cin >> f[i];
	}
	for (int i = 0; i < m; i++) {
		ff = 0;
		cin >> o;
		for (int j = 0; j < n - 1; j++) {
			if (o < f[j]) {
				ff = j + 1;
				break;
			}
		}
		if (ff = 0) cout << n;
		else cout << ff;
		if (i != m - 1) cout << " ";
	}
	return 0;
}
