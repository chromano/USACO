/*
TASK: palsquare
LANG: C
ID: chroman1
*/
#include <stdio.h>
#include <string.h>

#define MIN_BASE   2
#define MAX_N      300
#define MAX_DIGITS 17   /* ((int)(log(MIN_BASE) / log(MAX_N*MAX_N)) + 1) */

char *digits = "0123456789ABCDEFGHIJ"; /* base 20 is the max. as defined */

int convert(int number, int base, char *out) {
    int i, j;
    char c;

    for (i = 0; number; number /= base, i++)
        out[i] = digits[number % base];
    for (j = 0; j < i / 2; j++) {
        c = out[j];
        out[j] = out[i - j - 1];
        out[i - j - 1] = c;
    }
    out[i] = '\0';
    return i;
}

void solve(int base) {
    FILE *out;
    char square[MAX_DIGITS + 1], conv[MAX_DIGITS + 1];
    int i, j, k;

    out = fopen("palsquare.out", "w");
    for (i = 1; i <= MAX_N; i++) {
        k = convert(i * i, base, square);
        for (j = 0, k = k - 1; (k >= 0 && square[j] == square[k]); k--, j++);
        if (k != -1)
            continue;
        convert(i, base, conv);
        fprintf(out, "%s %s\n", conv, square);
    }
    fclose(out);
    return;
}

int main(void) {
    FILE *fp;
    int base;

    fp = fopen("palsquare.in", "r");
    fscanf(fp, "%d\n", &base);
    fclose(fp);
    solve(base);
    return 0;
}
