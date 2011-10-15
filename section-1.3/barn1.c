/*
TASK: barn1
LANG: C
ID: chroman1
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_STALLS     200

int _cmp(const void *a, const void *b, int dir) {
    return (*(int*)a) < (*(int*)b) ? -1 * dir : \
        ((*(int*)a) == (*(int*)b) ? 0 : 1 * dir);
}

int cmp_asc(const void *a, const void *b) {
    return _cmp(a, b, 1);
}

int cmp_desc(const void *a, const void *b) {
    return _cmp(a, b, -1);
}

int main(void) {
    FILE *in=fopen("barn1.in", "r"), *out=fopen("barn1.out", "w");
    int i, j, k, m, s, c, stalls[MAX_STALLS], \
        solutions[MAX_STALLS] = {0};

    fscanf(in, "%d %d %d\n", &m, &s, &c);
    for (i=0; i < c; i++) {
        fscanf(in, "%d\n", &stalls[i]);
    }
    qsort(stalls, c, sizeof(int), cmp_asc);
    for (i=1, j=0; i < c; i++) { 
        k = stalls[i] - stalls[i - 1] - 1;
        if (k)
            solutions[j++] = k;
    }
    qsort(solutions, c, sizeof(int), cmp_desc);

    s = stalls[c - 1] - stalls[0] + 1;
    for (i=0; i < m - 1 && solutions[i]; i++)
        s -= solutions[i];

    fprintf(out, "%d\n", s);

    fclose(in);
    fclose(out);
    return 0;
}
