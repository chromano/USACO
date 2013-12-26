/*
TASK: calfflac
LANG: C
ID: chroman1
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define DEBUG
#define STRING_LIMIT 20000
#define VALID_CHAR(c) ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))

typedef struct {
    int start;
    int length;
} pal;


void get_longest_pal2(pal *result, char *sample) {
    int start, l_expand, expand, length;

    result->start = -1;
    result->length = 0;
    for (start=0; start < strlen(sample); start++) {
        if (start > 0 && sample[start - 1] == sample[start])
            l_expand = 2;
        else
            l_expand = 1;
        expand = 1;
        while (start - l_expand >= 0 && start + expand < strlen(sample)
               && sample[start - l_expand] == sample[start + expand]) {
            #ifdef DEBUG
                printf("%.*s\n", l_expand + expand + 1, sample + start - l_expand);
            #endif
            l_expand++;
            expand++;
        }
        expand -= 1;
        l_expand -= 1;
        length = l_expand + expand + 1;
        if (length > result->length) {
            result->length = length;
            result->start = start - l_expand;
        }
    }
}

int main(void) {
	FILE *in=fopen("calfflac.in", "r"),
         *out=fopen("calfflac.out", "w");
    char sample[STRING_LIMIT + 1], c;
    char normalized[STRING_LIMIT + 1];
    int i, j;
    pal result;

    i = j = 0;
    while ((c = (char)fgetc(in)) != -1) {
        sample[i++] = c;
        if (VALID_CHAR(c))
            normalized[j++] = tolower(c);
    }
    sample[i] = '\0';
    fclose(in);

    get_longest_pal2(&result, normalized);

    fprintf(out, "%d\n", result.length);

    for (i=0, j=0; i < strlen(sample); i++) {
        if (VALID_CHAR(sample[i]))
            j++;
        if (j - 1 >= result.start)
            fputc(sample[i], out);
        if (j == result.start + result.length)
            break;
    }

    fputc('\n', out);

    fclose(out);
    return 0;
}
