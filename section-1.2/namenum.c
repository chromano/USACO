/*
TASK: namenum
LANG: C
ID: chroman1
*/
#include <stdio.h>
#include <string.h>

#define MAX_DIGITS 12
char *alphabet[] = {"ABC", "DEF", "GHI", "JKL", "MNO", "PRS", "TUV", "WXY"};

void solve(char *number) {
    FILE *dict, *out;
    char name[MAX_DIGITS + 1];
    int i, n_digits, valid, n_valids=0;
    char c;

    n_digits = strlen(number);
    dict = fopen("dict.txt", "r");
    out = fopen("namenum.out", "w");
    while (!feof(dict)) {
        fscanf(dict, "%s\n", name);
        if (strlen(name) != n_digits)
            continue;
        valid = 1;
        for (i=0; i < strlen(name); i++) {
            c = number[i] - '2';
            if (!(alphabet[c][0] <= name[i] && name[i] <= alphabet[c][2])) {
                valid = 0;
                break;
            }
        }
        if (valid) {
            fprintf(out, "%s\n", name);
            n_valids += 1;
        }
    }
    if (!n_valids)
        fprintf(out, "NONE\n", name);
    fclose(dict);
    fclose(out);
}

int main(void) {
    FILE *fp;
    char number[MAX_DIGITS + 1];

    fp = fopen("namenum.in", "r");
    fscanf(fp, "%s\n", number);
    fclose(fp);
    solve(number);

    return 0;
}
