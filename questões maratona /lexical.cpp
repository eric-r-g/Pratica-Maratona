#include <stdio.h>
#include <string.h>

int main(){
	int n, entr[100000];
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) scanf("%d", &entr[i]);
	
	// crio um vetor onde começa zero, e se o bit estiver ligado irei alocar 
	// na posicão mais a esquerda, marcado pelo pos_bit;
	int saida[100000], pos_bit[31];
	memset(saida, 0, n*sizeof(int));
	memset(pos_bit, 0, 31*sizeof(int)); 
	// brincando com o memset, mas na pratica é igual a pos_bit[31] = {} e saida[100000] = {}
	// (talvez um pouco mais rapido?)
	
	
	// defino as potencias de 2 necessarias
	long pot2[31];
	pot2[0] = 1;
	for(int i = 1; i < 31; ++i) pot2[i] = pot2[i - 1] * 2;

	
	// para cada um dos bits dos n numeros faco essa verificação
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < 31; ++j){
			if (entr[i] & pot2[j]){
				saida[pos_bit[j]] |= pot2[j];
				++pos_bit[j];
			}
		}
	}
	
	
	for(int i = 0; i < n - 1; ++i) printf("%d ", saida[i]);
	printf("%d\n", saida[n - 1]);
	return 0;
}
