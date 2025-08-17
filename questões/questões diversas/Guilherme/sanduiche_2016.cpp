#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, d, soma_total = 0, maneiras = 0;
	cin >> n >> d;
	vector<int> c(n);
	for (int i = 0; i < n; i++) {
		cin >> c[i];
		soma_total += c[i];
	}

	int i = 0, j = 0;
	int soma_atual = c[i];
	while (i <= j) {
		if (soma_atual == d) maneiras++;
		if (soma_total - soma_atual == d) maneiras++;
		if (soma_atual < d) {
			if (j < n - 1) {
				j++;
				soma_atual += c[j];
			} else break;
		}
		else {
			i++;
			soma_atual -= c[i-1];
		}
	}
	cout << maneiras << endl;
	return 0;
}
