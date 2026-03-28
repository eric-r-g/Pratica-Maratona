//O(n), testei com 10^8 passou com uns 900 ms, melhor nao arriscar se for 1 segundo
//prime contem os primos de (1, n) (nao inclusivo)
vector <int> prime;
bool is_composite[MAXN];
void sieve (int n) {
    fill (is_composite, is_composite + n, false);
  	for (int i = 2; i < n; ++i) {
    		if (!is_composite[i]) prime.push_back (i);
        for (int j = 0; j < prime.size () && i * prime[j] < n; ++j) {
            is_composite[i * prime[j]] = true;
            if (i % prime[j] == 0) break;
    		}
  	}
}
