/*
TASK: transform
LANG: C
ID: chroman1

This problem was very, *very* poorly described. Bleh.
*/
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 11

typedef struct {
    char matrix[MAX_SIZE][MAX_SIZE];
    int n;
} pattern;


pattern reflect(pattern in) {
    pattern out;
    int col, row, size;

    memset(out.matrix, '\0', MAX_SIZE * MAX_SIZE);
    out.n = size = in.n;
    for (row=0; row < size; row++)
        for (col=0; col < size; col++)
            out.matrix[row][size - col - 1] = in.matrix[row][col];
    return out;
}

pattern rotate(pattern in, int degrees) {
    pattern out;
    int i, size;

    memset(out.matrix, '\0', MAX_SIZE * MAX_SIZE);
    out.n = size = in.n;
    switch(degrees) {
		case 90:
    		/* Inverted columns of original becomes rows of result */
    		for (i=0; i < size * size; i++)
    			out.matrix[i / size][i % size] = \
                    in.matrix[size - (i % size) - 1][i / size];
			break;
		case 180:
			/* Inverted column N of original becomes column size-N */
			for (i=0; i < size * size; i++)
				out.matrix[i % size][size - (i  / size) - 1] = \
					in.matrix[size - (i % size) - 1][i / size];
			break;
		case 270:
			/* column N of original becomes row size-N of result */
			for (i=0; i < size * size; i++)
				out.matrix[size - (i / size) - 1][i % size] = \
                    in.matrix[i % size][i / size];
			break;
	}
    return out;
}

int match(pattern a, pattern b) {
    return !memcmp(a.matrix, b.matrix, MAX_SIZE * MAX_SIZE);
}

int main(void) {
    FILE *fp=fopen("transform.in", "r");
    int i, n;
    pattern in, out;
    int answer = -1;

    memset(in.matrix, '\0', MAX_SIZE * MAX_SIZE);
    memset(out.matrix, '\0', MAX_SIZE * MAX_SIZE);
    fscanf(fp, "%d\n", &in.n);
    for (i=0; i < in.n; i++)
        fscanf(fp, "%s\n", in.matrix[i]);
    for (i=0; i < in.n; i++)
        fscanf(fp, "%s\n", out.matrix[i]);
    fclose(fp);
    out.n = in.n;

    if (match(rotate(in,  90), out))
        answer = 1;
    else if (match(rotate(in, 180), out))
        answer = 2;
    else if (match(rotate(in, 270), out))
        answer = 3;
    else if (match(reflect(in), out))
        answer = 4;
    else if (match(rotate(reflect(in),  90), out) ||
             match(rotate(reflect(in), 180), out) ||
             match(rotate(reflect(in), 270), out))
        answer = 5;
    else if (match(in, out))
        answer = 6;
    else
        answer = 7;

    fp = fopen("transform.out", "w");
    fprintf(fp, "%d\n", answer);
    fclose(fp);

    return 0;
}
