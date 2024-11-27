#include <stdio.h>

void merge_sort(long l[], int tam){
	if (tam == 1) return ; 
	
	int meio = tam / 2;
	long l_a[meio], l_b[meio + 1];
	
	int tam_a = meio;
	int tam_b = tam - tam_a;
	
	for (int i = 0; i < tam_a; ++i) l_a[i] = l[i];
	for (int i = 0; i < tam_b; ++i) l_b[i] = l[i + tam_a];
	
	merge_sort(l_a, tam_a);
	merge_sort(l_b, tam_b);
	
	int e, ou;
	int i = tam_a - 1, j = tam_b - 1, p = tam - 1;
	while(i > -1 && j > -1){
		
		e = l_a[i] & l_b[j];
		ou = l_a[i] | l_b[j];
		
		if (l_a[i] > l_b[j])
		{
			l_a[i] = ou;
			--j;
		} 
		else 
		{
			l_b[j] = ou;
			--i;
		}
		l[p--] = e;
	}
	
	for(;i > -1; --i)l[p--] = l_a[i];
	for(;j > -1; --j)l[p--] = l_b[j];
}


int main(){
	int n;
	long lista[100000]; 
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) scanf("%ld", &lista[i]);
	merge_sort(lista, n);
	for(int i = 0; i < n; ++i) printf("%ld ", lista[i]);
	
	return 0;
}
