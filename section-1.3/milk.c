/*
TASK: milk 
LANG: C
ID: chroman1
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_SUPPLIERS 5000

typedef struct {
	int price;
	int amount;
} supplier;


int cmp_suppliers(const void *_a, const void *_b) {
	const supplier *a, *b;
	a = (supplier*)_a;
	b = (supplier*)_b;
	return a->price < b->price ? -1 : (a->price == b->price ? 0 : 1);
}

int main(void) {
	FILE *in=fopen("milk.in", "r"), *out=fopen("milk.out", "w");
	int i, n, m, result=0;
	supplier farmers[MAX_SUPPLIERS];

	fscanf(in, "%d %d\n", &n, &m);
	for (i=0; i < m; i++) {
		fscanf(in, "%d %d\n", &farmers[i].price, &farmers[i].amount);
	}
	qsort(farmers, m, sizeof(supplier), cmp_suppliers);
	for (i=0; i < m; i++) {
		if (farmers[i].amount >= n) {
			result += farmers[i].price * n;
			break;
		}
		result += farmers[i].price * farmers[i].amount;
		n -= farmers[i].amount;
	}

   fprintf(out, "%d\n", result);
   fclose(in);
   fclose(out);
   return 0;
}
