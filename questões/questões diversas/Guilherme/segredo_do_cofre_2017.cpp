#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, b, d;
	cin >> n >> m;
	vector<vector<int>> x(n, vector<int>(m));
	cin >> b;
	x[i][b] = 1;
	for (int i = 1; i < n; i++) {
		cin >> b;
		x[i][b] = x[i-1][b] + 1;
	}
    return 0;
}
