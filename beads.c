/*
TASK: beads
LANG: C
ID: chroman1
*/
#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_BEADS 350
#define NEXT_INDEX_CIRCULAR(size, idx) (idx == size - 1 ? 0 : idx + 1)
#define PREV_INDEX_CIRCULAR(size, idx) (idx == 0 ? size - 1 : idx - 1)

int collect_same_color_beads(int pos, int size, char *beads, int reverse)
{
    int sentinel = size, result = 0;
    char last_valid_color = '\0', curr_color;

    while (beads[pos])
        {
            curr_color = beads[pos];
            if (curr_color != 'w')
                if (!last_valid_color)
                    last_valid_color = curr_color;
                else if (curr_color != last_valid_color)
                    break;
            beads[pos] = 0; /* mark bead as collected */
            result++;
            pos = (reverse ? PREV_INDEX_CIRCULAR(size, pos)
                   : NEXT_INDEX_CIRCULAR(size, pos));
        }
    return result;
}

int get_n_beads_to_collect(int pos, int size, char *beads)
{
    char tmp_beads[MAX_BEADS + 1];
    int f_result, b_result;

    strcpy(tmp_beads, beads);
    f_result = collect_same_color_beads(pos, size, tmp_beads, 0);
    pos = PREV_INDEX_CIRCULAR(size, pos);
    b_result = collect_same_color_beads(pos, size, tmp_beads, 1);
    return f_result + b_result;
}

int main(void)
{
    int i, n_beads, n, result = 0;
    char beads[MAX_BEADS + 1];
    FILE *fp;

    fp = fopen("beads.in", "r");
    fscanf(fp, "%d\n%s\n", &n, beads);
    fclose(fp);

    for (i = 0; i < n; i++)
        {
            n_beads = get_n_beads_to_collect(i, n, beads);
            result = n_beads > result ? n_beads : result;
        }
    fp = fopen("beads.out", "w");
    fprintf(fp, "%d\n", result);
    fclose(fp);
    return 0;
}
