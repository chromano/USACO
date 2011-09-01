/*
TASK: dualpal
LANG: C
ID: chroman1
*/
#include <stdio.h>
#include <string.h>

char *digits = "0123456789";

void convert(int number, int base, char *out) {
    int len;

    if (number) {
        convert(number / base, base, out);
        len = strlen(out);
        out[len] = digits[number % base];
        out[len + 1] = '\0';
    } else {
        out[0] = '\0';
    }
}

int ispal(char *number) {
    int i, len;

    len = strlen(number);
    for (i = 0; i < len / 2; i++)
        if (number[i] != number[len - i - 1])
            return 0;
    return 1;
}

void solve(int n, int s) {
    char buff[17];
    int i, base, npal;
    FILE *out;

    out = fopen("dualpal.out", "w");
    while (n) {
        npal = 0;
        s++;
        for (npal = 0, base = 2; base <= 10; base++) {
            convert(s, base, buff);
            if (ispal(buff))
                npal++;
            if (npal >= 2) {
                break;
            }
        }
        if (npal >= 2) {
            fprintf(out, "%d\n", s);
            n--;
        }
    }
    fclose(out);
}

int main(void) {
    FILE *fp;
    int n, s;

    fp = fopen("dualpal.in", "r");
    fscanf(fp, "%d %d\n", &n, &s);
    fclose(fp);
    solve(n, s);

    return 0;
}
