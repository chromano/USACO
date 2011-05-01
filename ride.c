/*
TASK: ride
LANG: C
ID: chroman1
*/
#include <stdio.h>

#define MAX_NAME_SIZE 7

int get_number(char *name)
    {
        char *p = name;
        int number = 1;
        while (*p != '\0' && *p != '\n')
            number *= (*p++ - 'A') + 1;
        return number;
    }

int main(void)
    {
        char group_name[MAX_NAME_SIZE + 1], comet_name[MAX_NAME_SIZE + 1];
        FILE *in = fopen("ride.in", "r");
        FILE *out = fopen("ride.out", "w");

        fscanf(in, "%s\n", comet_name);
        fscanf(in, "%s\n", group_name);
        if ((get_number(comet_name) % 47) == (get_number(group_name) % 47))
            fputs("GO\n", out);
        else
            fputs("STAY\n", out);
        return 0;
    }
